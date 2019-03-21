 ///
 /// @file    tcp_client.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-12 21:56:25
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

#define ERROR_EXIT(msg) do{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
}while(0)

void test0()
{
	//1. 创建客户端套接字
	int clientfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(clientfd == -1){
		ERROR_EXIT("socket");
	}

	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8888);
	serveraddr.sin_addr.s_addr = ::inet_addr("192.168.31.128");

	//2. 客户端发起连接请求
	cout << ">> client is about to connect server..." << endl;
	int ret = ::connect(
		clientfd,
		(const struct sockaddr*)&serveraddr,
		sizeof(serveraddr));
	if(ret == -1) {
		ERROR_EXIT("connect");
		::close(clientfd);
	}

	//3.连接建立好之后，发送数据
	
	string data;
	cout << ">> client <---> server has connect " << endl;
	cout << "pls input : " ;
	cin >> data;

	//4. 向服务器发送业务请求
	//第6个client发送数据时就会造成send:Connection reset by peer
	ret = ::send(clientfd, data.c_str(), data.size(), 0);
	if(ret == -1){
		ERROR_EXIT("send");
		close(clientfd);
	}
	
	//5. 接受服务器返回的数据
	char buff[1024] = {0};//客户端的应用层缓冲区
	ret = ::recv(clientfd, buff, sizeof(buff), 0);
	//recv的返回值有3种情况，都要进行判断
	if(ret == -1){
		ERROR_EXIT("recv");
		::close(clientfd);
		return ;
	}else if(ret == 0){ //连接断开
		::close(clientfd);
	}else { //接收到了数据
		cout << ">> client receive " << ret << " bytes data" << endl;
		cout << ">> receive data: " << buff << endl;
	}

	//6. 断开连接
	::close(clientfd);
}
 
int main(void)
{
	test0(); 
	return 0;
}
