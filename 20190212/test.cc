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
int send(int sockfd, const void *buf, size_t len, int flags)

//5. 接收服务器返回的数据
int recv(int sockfd, void *buf, size_t len, int flags(0) );

