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

#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using namespace std;

	
//笔试题：写一个程序，判断当前的计算机是大端模式还是小端模式
void test0()
{
	int a = 1;
	char * p = (char *)&a;
	int b = (int)(*p); 
	cout << "b = " << b << endl;

	p += 3;
	cout << "执行p += 3 之后: " << endl;
	b = (int)(*p);
	cout << "b = " << b << endl;
}

//联合体实现
void test1()
{
    char buff[1024];
	cout << buff[0] << endl;
	//char类型不存在大端模式 小端模式的问题,
	//大端模式和小端模式只针对于多字节类型的数据
	union test //联合体共享数据空间
	{
		int a;
		char data[4];
	}t1;

	t1.a = 1;
	int x = t1.data[0];
	int y = t1.data[3];

	//经过测试，采用的小端模式进行存储(主机字节序)
	cout << "data[0] = " << x << endl;
	cout << "data[3] = " << y << endl;
}


#define ERROR_EXIT(msg) {\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
}

int test2()
{
	//1.创建套接字，得到一个文件描述符
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == -1){
		ERROR_EXIT("socket");
	}

	//网络模式 ==> 大端模式
	unsigned short port = 8888;
	string ip("192.168.31.128");
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
	cout << ">>> server listenfd = " << listenfd << endl;
	//listenfd的值为什么从3开始
	//--->标准输入 0
	//--->标准输出 1
	//--->标准错误 2

	//3.对新连接请求进行监听
	if(-1 == ::listen(listenfd, 10)) { //设置处于半连接状态的连接数的最大值 
		::close(listenfd);
		ERROR_EXIT("listen");
	}
	while(1){
		//4.建立新连接
		//客户请求连接我们的服务器，我们服务器先做了一些绑定和监听等等操作之后，
		//如果允许连接，则调用 accept 函数产生一个新的套接字
		//然后用这个新的套接字跟我们的客户进行收发数据
		cout << ">> server is about to accept a new link " << endl;
		int peerfd = ::accept(listenfd, NULL, NULL);
		if(-1 == peerfd){
			::close(listenfd);
			ERROR_EXIT("accept");
		}
		cout << ">>> server client with fd = " << peerfd << endl;
		//如果peerfd > 0, 则新连接建立完毕，以后通过peerfd所对应的数据结构与对端通信
		
		//peerfd//代表的就是一个建立好的连接,满足5元组
		//4.1 解析对端IP和port
		struct sockaddr_in clientaddr;
		socklen_t len = sizeof(struct sockaddr_in);
		int ret = ::getpeername(peerfd, (struct sockaddr*)&clientaddr, &len);
		string clientip(inet_ntoa(clientaddr.sin_addr));
		unsigned short clientport(ntohs(clientaddr.sin_port));
		cout << " >> server " << ip << ":" << port << " --> " 
			 << "client " << clientip << ":" << clientport
			 << " has connected!" << endl;
		

		cout << " >>> before recv" << endl;
		//5. 进行数据的接收和发送
		//用新的套接字来接收远端主机传来的数据，并把数据存到由参数 buff 指向的内存空间
		char buff[1024] = {0};//应用层缓冲区
		ret = ::recv(peerfd, buff, sizeof(buff), 0);
		cout << ">>> server recv ret = " << ret << endl;
		if(ret == -1){
			if(ret == -1 && errno == EINTR) //EINTR中断
				continue;
			else
				ERROR_EXIT("recv");
		}else if(ret == 0) {//连接已经断开了
			close(peerfd);
		}else {
			// ret > 0 表示已经接受到了对端发送的数据的长度
			//6. 对接受的数据进行处理(业务逻辑)
			cout << ">> server gets msg fron client: "<< buff << endl;

			//6. 进行数据的发送,进行回显操作
			ret = ::send(peerfd, buff, strlen(buff), 0);
			if(ret == -1){
				ERROR_EXIT("send");
				close(peerfd);
			}
			//8.断开连接
			::close(peerfd);//关闭连接
		}
	}//end of while

	//9. 关闭服务器监听的文件描述符
	::close(listenfd);//文件描述符资源是有限的
}
 
int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
