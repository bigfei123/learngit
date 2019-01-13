 ///
 /// @file    io3.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-11 08:37:41
 ///
#include <sstream> 
#include <string>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::ifstream;

void test0()
{
	int number1= 10;
	int number2= 10;
	
	stringstream ss;//字符串输出流
	ss << "number1= " << number1 << " ,number2= " << number2 << endl;
	string line = ss.str();
	//将字符串输出流中的数字逐个转换为字符输入到line中
	cout << line;
	string key;
	int value;
	//字符串输入流
	while(ss >> key >> value, !ss.eof())
		cout << key << "--> " << value << endl; 
	}

string int2str(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}


void test1()
{
	int value = 1024;
	string str =int2str(value);
	cout << "str = " <<str << endl;

}

void readConfig(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs) {
		cout << "ifstream open " << filename << " error" <<endl;
		return ;
	}

	string line;
	while(getline(ifs,line)){
		string key, value;
		istringstream iss(line);
		iss >> key >> value;
		cout << key << "---> " << value <<endl;
	}
	ifs.close();
}

void test2()
{
	readConfig("my.config");
}


int main(void)
{
	//test0();
	//test1();
	test2();
}
