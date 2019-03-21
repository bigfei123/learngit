 ///
 /// @file    test_server.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-14 19:42:03
 ///
 
#include <netinet/in.h>//协议栈
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
 
using namespace std;

#define ERROR_EXIT(msg) \
{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
}

void test0()
{
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == -1){
		//::close(listenfd);
		ERROR_EXIT("socket");
	}

	string ip("192.168.31.128");
	unsigned short int port(8888);

	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ip.c_str());

	int ret = ::bind(listenfd, (const sockaddr *) &serveraddr, sizeof(serveraddr));
	if(ret == -1){
		::close(listenfd);
		ERROR_EXIT("bind");
	}

	ret = ::listen(listenfd, 10);
	if(ret == -1){
		ERROR_EXIT("listen");
	}
	cout << ">>> server listenfd = " << listenfd << endl;

	while(1){
		cout << ">> server is about to accept a new link " << endl;
		int peerfd = ::accept(listenfd, nullptr, nullptr);
		if(peerfd == -1){
			::close(listenfd);
			ERROR_EXIT("accept");
		}
		cout << ">>> server client with fd = " << peerfd << endl;

		struct sockaddr_in clientaddr;
		socklen_t len = sizeof(sockaddr_in);
		ret = ::getpeername(peerfd, (struct sockaddr *)&clientaddr, &len);
		if(ret == -1){
			ERROR_EXIT("getpeername");
		}

		string clientip(inet_ntoa(clientaddr.sin_addr));
		unsigned short int clientport(htons(clientaddr.sin_port));
		cout << "serverip: " << ip << "serverport:" << port << "---->"
			 << "clientip: " << clientip << "clientport: " << clientport << endl;
		char buff[1024] = {0};
		ret = ::recv(peerfd, buff, sizeof(buff), 0);
		if(ret < 0){
			if(ret == -1 && errno == EINTR)
				continue;
			}else if(ret == 0){
				::close(peerfd);
				//ERROR_EXIT("recv");
			}else{
				cout << " >> server gets msg from client: " << buff << endl;
				ret = ::send(peerfd, buff, sizeof(buff), 0);
				if(ret == -1){
					::close(peerfd);
					ERROR_EXIT("send");
				}
			}
			::close(peerfd);
		}//end of while
		::close(listenfd);
}

int main(void)
{
	test0();
	return 0; 
}
