 ///
 /// @file    test_client.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-14 20:28:58
 ///
 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
 
using namespace std;

#define ERROR_EXIT(msg)\
{\
	::perror("msg");\
	::exit(EXIT_FAILURE);\
}

void test0()
{
	int clientfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(clientfd == -1){
		ERROR_EXIT("socket");
	}

	string ip("192.168.31.128");
	unsigned short int port(8888);

	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ip.c_str());
	
	cout << "client is about to connect server !" << endl;
	int ret = ::connect(clientfd, (const struct sockaddr*)&serveraddr, sizeof(sockaddr_in));
	if(ret == -1){
		::close(clientfd);
		ERROR_EXIT("connect");
	}

	cout << "pls input :" ;
	string data;
	cin >> data;

	ret = ::send(clientfd, data.c_str(), data.size(), 0);
	if(ret == -1){
		::close(clientfd);
		ERROR_EXIT(send);
	}

	char buff[1024] = {0};
	ret = ::recv(clientfd, buff, sizeof(buff), 0);
	if(ret < -1){
		::close(clientfd);
		ERROR_EXIT(recv);
		return ;
	}else if(ret == 0){
		::close(clientfd);
	}else {
		cout << ">> client receive " << ret << "bytes data" << endl;
		cout << ">> receive data : " << buff << endl;
	}
	::close(clientfd);
}

int main(void)
{
	test0();
	return 0;
}
