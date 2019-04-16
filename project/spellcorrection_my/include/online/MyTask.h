 ///
 /// @file    MyTask.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-22 21:18:55
 ///

#ifndef __ONDLINE_MYTASK_H__
#define __ONDLINE_MYTASK_H__

#include <vector>
#include <queue>
#include <string>

#include "MyResult.h"
#include "TcpConnection.h"

using namespace std;

namespace online
{

class MyTask
{
public:
	MyTask(const string &, const TcpConnectionPtr &);
	void excute();

private:
	int distance(const string &);
	void response();

	int getBytesCode(char);
	string getNthChar(const string &, int);
	int getLength(const string &);
private:
	string _queryWord;
	TcpConnectionPtr _conn;
	priority_queue<MyResult, vector<MyResult>> _resultQue;//返回给客户端的候选词
};

}//end of namespace wd

#endif
