 ///
 /// @file    SafeFile.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 16:12:08
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class SafeFile
{
public:
	//通过构造对象托管资源
	SafeFile(FILE *fp)
	: _fp(fp)
	{
		cout << "SafeFile(FILE*)" << endl;
		if(_fp == nullptr){
			cout << "_fp == nullptr" << endl;
		}
	}

	//提供资源的访问方法
	void write(const string & msg)
	{
		fwrite(msg.c_str(), 5, msg.size(), _fp);
	}

	//当对象被销毁时释放资源
	~SafeFile()
	{
		cout << "~SafeFile()" << endl;
		if(_fp){
			fclose(_fp);
			cout << "fclose(_fp)" << endl;
		}
	}
private:
	FILE * _fp;
};
 
int main(void)
{
	//RAII
	SafeFile sf(fopen("test.txt","w"));
	sf.write("hello, world");
	return 0;
}
