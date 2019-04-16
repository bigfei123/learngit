 ///
 /// @file    tcp_server.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-12 19:43:17
 ///
 
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <cstring>
#include <fcntl.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <unordered_set>
#include <functional>
#include <vector>
using namespace std;

#define ERROR_EXIT(msg) {\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
}

int create_tcp_socket()
{
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == -1){
		ERROR_EXIT("socket");
	}
	return listenfd;
}

void set_reuse_addr(int fd, int on)
{
	int reuse = on;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)))
	{
		ERROR_EXIT("setsockopt");
	}
}

//对端口的复用,意味着linux内核可以在用一台物理主机上实现系统级别的负载均衡
void set_reuse_port(int fd, int on)
{
	int reuse = on;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(int)))
	{
		ERROR_EXIT("setsockopt");
	}
}

int bind_inet_addr(int fd, const char *ip, unsigned short port)
{
	//网络模式 ==> 大端模式
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET; 
	serveraddr.sin_port = htons(port); 
	serveraddr.sin_addr.s_addr = inet_addr(ip);
	int ret= bind(fd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr));
	if(ret == -1)
	{
		::close(fd);
		ERROR_EXIT("bind");
	}
	return ret;
}

int mylisten(int fd)
{
	int ret = ::listen(fd, 10); 
	if(-1 == ret)
	{
		::close(fd);
		ERROR_EXIT("listen");
	}
	return ret;
}

int my_accept(int fd)
{
	int peerfd = ::accept(fd, NULL, NULL);
	if(-1 == peerfd){
		::close(fd);
		::perror("accept");
	}
	return peerfd;
}

int handle_new_connection(int listenfd)
{
	//4.建立新连接
	cout << ">>> server is about to accept a new link " << endl;
	int peerfd = my_accept(listenfd);
	cout << ">>> server client with fd = " << peerfd << endl;

	return peerfd;
}

void print_connection_info(int peerfd)
{
	//4.1 解析对端IP和port
	struct sockaddr_in clientaddr;
	::memset(&clientaddr, 0, sizeof(struct sockaddr_in));
	socklen_t len = sizeof(struct sockaddr_in);
	int ret = ::getpeername(peerfd, (struct sockaddr*)&clientaddr, &len);

	//解析服务器的IP和port
	struct sockaddr_in serveraddr;
	ret = ::getsockname(peerfd, (struct sockaddr*)&serveraddr, &len);
	if(ret == -1){
		perror("getpeername");
	}else {
		cout << " clientaddr len = " << len << endl;
		string serverip(inet_ntoa(serveraddr.sin_addr));
		unsigned short serverport = ntohs(serveraddr.sin_port);

		string clientip(inet_ntoa(clientaddr.sin_addr));
		unsigned short clientport(ntohs(clientaddr.sin_port));
		cout << " >>> " << serverip << ":" << serverport 
			 << " --> " <<  clientip << ":" << clientport ;
	}
}

void handle_client_message(int peerfd, unordered_set<int> & client_fds)
{
	//5. 对已经建立好的连接进行数据的接收
	char buff[1024] = {0};//应用层缓冲区
	cout << " >>> before recv " << endl;
	
	int ret = ::recv(peerfd, buff, sizeof(buff), 0);
	cout << ">>> server recv ret = " << ret << endl;
	if(ret < 0){
		if(ret == -1 && errno == EINTR)
			return ;
		else
			::perror("recv");
	}else if(ret == 0) {//连接已经断开了
		print_connection_info(peerfd);
		cout << "has closed ! " << endl;
		::close(peerfd);
		client_fds.erase(peerfd);
	}else {
		// ret > 0 表示已经接受到了对端发送的数据的长度
		//6. 对接受的数据进行处理(业务逻辑)
		cout << ">> server gets msg fron client: "<< buff << endl;

		//7. 得到要返回给client的结果，对数据的发送,进行回显操作
		ret = ::send(peerfd, buff, strlen(buff), 0);//(传输层操作，对我们来说是透明的)
		//ret = ::write(peerfd, buff, strlen(buff));//(传输层操作，对我们来说是透明的)
		if(ret == -1){
			::perror("send");
			::close(peerfd);
		}
	}
}

//设置为非阻塞模式
void set_non_block(int fd)
{
	int flags = fcntl(fd, F_GETFL, 0);
	if(flags == -1){
		ERROR_EXIT("fcntl");
	}
	int ret = ::fcntl(fd, F_SETFL, O_NONBLOCK | flags);
	if(ret == -1){
		ERROR_EXIT("fcntl");
	}
}

void select_fds_init(int & maxfd, fd_set * rfds, unordered_set<int> & client_fds)
{
	for(auto & fd : client_fds) {
		FD_SET(fd, rfds);
		if(maxfd < fd) maxfd = fd;
	}
}

int tcp_server(const string & ip, unsigned short port)
{
	int listenfd = create_tcp_socket();
	cout << " >>>> server listenfd = " << listenfd << endl;

	set_reuse_addr(listenfd, 1);//将网络地址设置成可以重用的
	set_reuse_port(listenfd, 1);//将server端设置成为重用的
	
    //2.绑定网络地址
	bind_inet_addr(listenfd, ip.data(), port);

	//3.对新连接请求进行监听
	mylisten(listenfd);
	return listenfd;
}


int test0()
{
	string ip("192.168.31.128");
	unsigned short port = 8888;
	//1.创建套接字，得到一个文件描述符
	int listenfd = tcp_server(ip, port);

	//并发服务器之IO复用poll
	vector<struct pollfd> pfds(1024);//pfds.size() == 1024
	//pfds.reserve(1024); //pfds.size() == 0
	
	size_t fd_idx = 0;
	pfds[fd_idx].fd = listenfd;//由内核进行修改
	pfds[fd_idx].events = POLLIN;//POLLIN为读事件
	//pfds[0].revents; 
	//pfds[1].fd = peerfd;
	//pfds[1].events = POLLIN;
	

	unordered_set<int> client_fds;//存储的是所有已经建立连接的fd
	while(1){
		//poll能够监听的文件描述符数量没有限制
		int ready = poll(&*pfds.begin(), pfds.size(), 5000);//阻塞式函数,指定时间,5s之后返回
		if(fd_idx == pfds.size()){
			pfds.resize(pfds.size() * 2); //执行扩容操作
		}

		cout << ">>> poll retval = " << ready << endl;
		if(ready == -1 && errno == EINTR){
			continue;
		}else if(ready == -1){
			ERROR_EXIT("poll");
		}else if(ready == 0){
			cout << ">> poll timeout!" << endl;
			continue;
		}else { //ready > 0
			vector<int> new_conns;//存放的是当前pool返回之后，又建立好的链接
			for(int idx = 0; idx < ready; ++idx){
				if((pfds[idx].fd == listenfd) && (pfds[idx].revents & POLLIN)){
					//建立新连接
					int peerfd = handle_new_connection(listenfd);
					set_non_block(peerfd);//设置成非阻塞
					print_connection_info(peerfd);
					cout << " has connected! " << endl;
					client_fds.insert(peerfd);
					new_conns.push_back(peerfd);
				}else if(pfds[idx].revents & POLLIN){
					//处理已经创建好的连接
					handle_client_message(pfds[idx].fd, client_fds);
				}
			}//end of for
			//将peerfd添加到poll的监听队列中去
			for(auto & fd : new_conns){
				pfds[fd_idx].fd = fd;
				pfds[fd_idx].events = POLLIN;
				++fd_idx;
			}
		}
	}// end of while
	//9. 关闭服务器监听的文件描述符
	::close(listenfd);
}
 
int main(void)
{
	test0();
	return 0;
}
