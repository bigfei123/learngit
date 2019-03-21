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
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <functional>
using std::cout;
using std::endl;
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
	socklen_t reuse = on;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&reuse, sizeof(socklen_t)))
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
		cout << " >>> " << serverip << ":" << serverport << " --> " 
			 <<  clientip << ":" << clientport
			 << " has connected!" << endl;
	}
	return peerfd;
}
void handle_client_message(int peerfd, fd_set * rfds)
{
	//5. 对已经建立好的连接进行数据的接收
	char buff[1024] = {0};//应用层缓冲区
	cout << " >>> before recv " << endl;
	
	int ret = ::recv(peerfd, buff, sizeof(buff), 0);
	cout << ">>> server recv ret = " << ret << endl;
	if(ret == -1){
		if(ret == -1 && errno == EINTR)
			return ;
		else
			::perror("recv");
	}else if(ret == 0) {//连接已经断开了
		::close(peerfd);
		FD_CLR(peerfd, rfds);
	}else {
		// ret > 0 表示已经接受到了对端发送的数据的长度
		//6. 对接受的数据进行处理(业务逻辑)
		cout << ">> server gets msg fron client: "<< buff << endl;

		//7. 进行数据的发送,进行回显操作
		ret = ::send(peerfd, buff, strlen(buff), 0);
		if(ret == -1){
			::perror("send");
			::close(peerfd);
		}
		//8.断开连接
		::close(peerfd);//关闭连接
		FD_CLR(peerfd, rfds);
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


int test0()
{
	//1.创建套接字，得到一个文件描述符
	int listenfd = create_tcp_socket();
	cout << " >>>> server listenfd = " << listenfd << endl;

	set_reuse_addr(listenfd, 1);//将网络地址设置成可以重用的

    //2.绑定网络地址
	bind_inet_addr(listenfd, "192.168.31.128", 8888);

	//3.对新连接请求进行监听
	mylisten(listenfd);

	//并发服务器之IO复用
	fd_set rfds;//读时间的fd_set
	FD_ZERO(&rfds); 
	FD_SET(listenfd, &rfds);//将listenfd添加到select的监听队列中
	struct timeval tv;
	tv.tv_sec = 5;
	tv.tv_usec = 0;

	while(1){
		//32位机的最大连接数1024, 64位机最大2048
		int ready = select(1024, &rfds, nullptr, nullptr, &tv);//阻塞式函数
		//int ready = select(1024, &rfds, nullptr, nullptr, nullptr);//阻塞式函数
		cout << ">>> select retval = " << ready << endl;
		if(ready == -1 && errno == EINTR){
			continue;
		}else if(ready == -1){
			ERROR_EXIT("select");
		}else if(ready == 0){
			cout << ">> select timeout!" << endl;
			continue;
		}else { //ready > 0
			for(int fd = 0; fd < 1024; ++fd){
				//查看fd是否在存在并且是否为listenfd
				if(FD_ISSET(fd, &rfds) && fd == listenfd){
					//建立新连接
					int peerfd = handle_new_connection(listenfd);
					set_non_block(peerfd);//设置成非阻塞
					FD_SET(peerfd, &rfds);
				}
				if(FD_ISSET(fd, &rfds) && (fd != listenfd)){
					//处理已经创建好的连接
					handle_client_message(fd, &rfds);
					//若client-1建立连接后没有输入数据,此时recv()函数进去阻塞,后建立的连接无法输入
					//解决：将recv()设置成非阻塞函数
				}
			}//end of for
		}
	}// end of while
	//9. 关闭服务器监听的文件描述符
	::close(listenfd);
	FD_CLR(listenfd, &rfds);
}
 
int main(void)
{
	test0();
	return 0;
}
