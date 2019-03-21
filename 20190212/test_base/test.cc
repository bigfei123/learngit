 ///
 /// @file    test.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-14 16:55:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
//1. 创建套接字，得到一个文件描述符
int socked(int domain, int type, int protocol)
int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);

//1.1 设置端口号与ip
struct sockaddr_in serveraddr;
serveraddr.sin_family = AF_INET;
serveraddr.sin_port = htons(8888); host to net small
serveraddr.sin_addr.s_addr = inet_addr(ip.data());

//2.绑定网络地址
int bind(int sockfd, const struct sockaddr * mysock, int addrlen)
bind(listend, (const struct sockaddr*) &serveraddr, sizeof(serveraddr))

//3.对新连接请求进行监听
listen(listenfd, 10)

//4.建立新链接
peerfd = accept(listenfd, NULL, NULL);

//4.1 解析对端IP和port
struct sockaddr_in clientaddr
int getpeername(int sockfd, struct sockaddr*addr, socklen_t * addrlen);
int getpeername(peerfd, (struct sockaddr*)&clientaddr, &len)
//求clientip、clientport
cout << ip << port
	   << clientip << clientport

//5.进行数据的接收和发送
char buff[1024] = {0};
int recv(int sockfd, void *buf, size_t len, int flags(0) );
//判断ret的值
//if(ret < 0)
//	if((ret == -1) && errno == EINTR)
//else if(ret == 0)
//else
//   cout << buff;
	
//6. 进行数据的发送，进行回显操作
int send(int sockfd, const void *buf, size_t len, int flags)
int ret = send(peerfd, buff, sizeof(buff), 0)

Client 
//1. 创建客户端套接字
//2. 客户端发起连接请求
// int connect(int sockfd, const struct sockaddr * addr, socklen_t addrlen);
//3. 连接建立好之后，发送数据
//
//4. 向服务器发送业务请求
int send(int sockfd, const struct sockaddr * addr, socklen_t addrlen);

//5. 接收服务器返回的数据
//

tcp_thread

struct thread_data{
	const char * ip;
	unsigned port;
	int peerfd;
}pth_data, local_pthread_data;

//1. 创建套接字
//1.1 设置server端ip和port
//2. 绑定网络地址
//3. 对新连接请求进行监听
//4. 并发服务器模型之多线程模式： 一个请求交给一个子线程处理
vector<pthread_t> pthreads;
while(cnt){
//5. 建立新连接
//-->采用多线程的方式处理请求
//pthread_t pthid;
//int pthread_create(pthread_t * thread, 
//					 const pthread_attr_t *attr,//nullptr
//                   void *(*func)(void*), 函数指针
//					 void * arg);函数参数
pthread.push_back(pthid);
}
//6. 释放线程资源(for)
void * process_connection(void * arg)
{
	struct thread_data * pdata = (struct thread_data*)(arg);
	//复制到全局结构体中
	local_pthread_data.ip = pdata->ip;
	local_pthread_data.port = pdata->port;
	local_pthread_data.peerfd = pdata->peerfd;

	int peerfd = local_pthread_data.peerfd;

	getpeername(peerfd, struct sockaddr*, *len);

	//进行数据的接收和发送
	int recv(peerfd, void * , size_t, int flags)
	int send(peerfd, void * , size_t, int flags)

	//断开连接
	::close(peerfd);
	return nullptr;
}
//7. 关闭服务器监听的文件描述符







