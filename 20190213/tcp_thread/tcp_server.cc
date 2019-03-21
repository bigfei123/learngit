 ///
 /// @file    tcp_server.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-12 19:43:17
 ///
 
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#include <functional>
#include <vector>
#include <iostream>
using namespace std;


#define ERROR_EXIT(msg) {\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
}

struct thread_data{
	const char * ip;
	unsigned port;
	int peerfd;
}pth_data, local_pthread_data;//全局


//子线程的处理过程
void * process_connection(void * arg)
{
	struct thread_data *pdata = (struct thread_data*)(arg);
	//复制到全局结构体中
	local_pthread_data.ip = pdata->ip;
	local_pthread_data.port = pdata->port;
	local_pthread_data.peerfd = pdata->peerfd;
	cout << ">>>> subthread " << pthread_self() << endl;

	int peerfd = local_pthread_data.peerfd;//局部变量

	//如果peerfd > 0, 则新连接建立完毕，以后通过peerfd所对应的数据结构与对端通信
	//peerfd//代表的就是一个建立好的连接,满足5元组
	//4.1 解析对端IP和port
	struct sockaddr_in clientaddr;
	::memset(&clientaddr, 0, sizeof(struct sockaddr_in));
	socklen_t len = sizeof(struct sockaddr_in);
	int ret = ::getpeername(peerfd, (struct sockaddr*)&clientaddr, &len);
	if(ret == -1){
		perror("getpeername");
	}else{
		cout << " >>>> subthread " << pthread_self() << ":" 
			 << local_pthread_data.ip << ":" << local_pthread_data.port << " --> " 
			 << " has connected!" << endl;
	}
	
	
	//5. 进行数据的接收和发送
	//用新的套接字来接收远端主机传来的数据，并把数据存到由参数 buff 指向的内存空间
	char buff[1024] = {0};//应用层缓冲区
	cout << " >>>> before recv" << endl;
	ret = ::recv(peerfd, buff, sizeof(buff), 0);//peerfd发生了读事件
	if(ret == -1){
		if(ret == -1 && errno == EINTR) //EINTR中断
			return nullptr;
		else
			ERROR_EXIT("recv");
	}else if(ret == 0) {//连接已经断开了
		close(peerfd);
	}else {
		// ret > 0 表示已经接受到了对端发送的数据的长度
		//6. 对接受的数据进行处理(业务逻辑)
		cout << ">> server gets msg fron client: "<< buff << endl;

		//6. 进行数据的发送,进行回显操作
		ret = ::send(peerfd, buff, strlen(buff), 0);//peerfd发生写事件
		if(ret == -1){
			ERROR_EXIT("send");
			::close(peerfd);
		}
	}
	//8.断开连接
	::close(peerfd);//关闭连接

	return nullptr;
}

int test0()
{
	//1.创建套接字，得到一个文件描述符
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == -1){
		ERROR_EXIT("socket");
	}

	cout << ">> server listenfd = " << listenfd << endl;

	//网络模式 ==> 大端模式
	unsigned short port(8888);
	string ip("192.168.31.128");

	pth_data.ip = ip.data();
	pth_data.port = port;

	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET; //IPv4
	serveraddr.sin_port = htons(port); //端口号 host to net small
	serveraddr.sin_addr.s_addr = inet_addr(ip.data());//inet_addr()用来将 IP地址字符串转换成网络所使用的二进制数字
    //2.绑定网络地址
	if(-1 == bind(listenfd, 
		(const struct sockaddr *)&serveraddr,
		sizeof(serveraddr)))
	{
		::close(listenfd);
		ERROR_EXIT("bind");
	}
	//listenfd的值为什么从3开始
	//--->标准输入 0
	//--->标准输出 1
	//--->标准错误 2

	//3.对新连接请求进行监听
	if(-1 == ::listen(listenfd, 10)) { //设置处于半连接状态的连接数的最大值 
		::close(listenfd);
		ERROR_EXIT("listen");
	}

	vector<pthread_t> pthreads;
	//并发服务器模型之多线程模型: 一个请求交给一个子线程处理
	int cnt = 5;
	while(cnt--){
		//4.建立新连接
		cout << ">> server is about to accept a new link " << endl;
		int peerfd = ::accept(listenfd, NULL, NULL);//在listenfd上是有读时间发生
		if(-1 == peerfd){
			::close(listenfd);
			ERROR_EXIT("accept");
		}
		cout << ">> server client with fd = " << peerfd << endl;
		pth_data.peerfd = peerfd;

		//采用多线程的方式处理请求
		pthread_t pthid;//创建子线程处理请求
		if(pthread_create(&pthid, nullptr, process_connection, (void*)&pth_data)){
											//(void*)&pth_data))为process_connection的参数
			ERROR_EXIT("pthread_create");
		}
		pthreads.push_back(pthid);
		cout << ">> main thread create subthread" << pthid << endl;
	}//end of while

	//当client数量大于5时,退出while循环,无法执行新连接,但底层tcp协议栈还是可以接听client的请求的
	//第6个client发送数据时就会造成send:Connection reset by peer
	cout << ">> main thread release subthreads..." << endl;
	for(auto & pthid : pthreads){
		pthread_join(pthid, nullptr);
	}

	//9. 关闭服务器监听的文件描述符
	::close(listenfd);//文件描述符资源是有限的
}
 
int main(void)
{
	test0();
	return 0;
}
