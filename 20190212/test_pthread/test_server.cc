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
#include <vector>
#include <pthread.h>
 
using namespace std;

#define ERROR_EXIT(msg) \
{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
}

struct pthread_data{
	const char * ip ;
	unsigned port;
	int peerfd;
}pth_data, local_pthread_data;

void * process_connection(void * arg)
{
	struct pthread_data * pdata = (struct pthread_data*)(arg);
	local_pthread_data.ip = pdata->ip;
	local_pthread_data.port = pdata->port;
	local_pthread_data.peerfd = pdata->peerfd;

	int peerfd = local_pthread_data.peerfd;

	struct sockaddr_in clientaddr;
	socklen_t len = sizeof(sockaddr_in);
	int ret = ::getpeername(peerfd, (struct sockaddr *)&clientaddr, &len);
	if(ret == -1){
		ERROR_EXIT("getpeername");
	}

	cout << "subthreadid : " <<  pthread_self() << ":" << endl
		 << "clientip: " << local_pthread_data.ip << "--->"
		 << "clientport: " << local_pthread_data.port << endl;
	char buff[1024] = {0};
	ret = ::recv(peerfd, buff, sizeof(buff), 0);
	if(ret < 0){
		if(ret == -1 && errno == EINTR)
			return nullptr;
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
}

void test0()
{
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == -1){
		//::close(listenfd);
		ERROR_EXIT("socket");
	}
	cout << ">>> server listenfd = " << listenfd << endl;

	string ip("192.168.31.128");
	unsigned short port(8888);

	pth_data.ip = ip.data();
	pth_data.port = port;

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
	
	int cnt = 5;
	vector<pthread_t> pthreads;
	while(cnt--){
		cout << ">> server is about to accept a new link " << endl;
		int peerfd = ::accept(listenfd, nullptr, nullptr);
		if(peerfd == -1){
			::close(listenfd);
			ERROR_EXIT("accept");
		}
		cout << ">> server client with fd = " << peerfd << endl;
		pth_data.peerfd = peerfd;

		pthread_t pthid;
		int ret = pthread_create(&pthid, nullptr, process_connection, (void*)&pth_data);
		if(ret)
			ERROR_EXIT("pthread_create");
		pthreads.push_back(pthid);
		cout << "main thread create subthread " << pthid << endl;
	}

	for(auto & pth : pthreads){
		pthread_join(pth, nullptr);
	}

	::close(listenfd);
}

int main(void)
{
	test0();
	return 0; 
}
