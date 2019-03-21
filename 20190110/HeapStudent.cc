 ///
 /// @file    Student.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 19:52:49
 ///
#include <cstring> 
#include <iostream>
using std::cout;
using std::endl;
//只能生成堆对象
//1.该对象只能放在堆上，不能放在栈上
//2.采取的操作是：将析构函数设置为private
//
class Student
{
public:
	Student(int id, const char *name)
	: _id(id)
	, _name(new char[strlen(name)+1]())
	{
		cout << " Student(int ,const char *)" << endl;
	}

	void print() const
	{
		cout << "id:" << _id <<endl
			 << "name:" << _name << endl;

	}
	
	void destroy()
	{
	//	this->~Student();不能直接调析构函数
		delete this;
	}
	
	void * operator new(size_t size)
	{
		void * pret = malloc(size);
		cout << "void * operator new(size_t)" << endl;
		return pret;
	}
	void operator delete(void * pret)
	{
		free(pret);
		cout << " void operator delete(void*)" << endl;
	}
		
	
private:
	~Student()
	{
		delete[] _name;
		cout << "~Student()" << endl;
	}
private:

	int _id;
	char *_name;
	

};

int main(void)
{
	//在类之外无法执行	
	//Student s3(101,"小红");//error
	//s1.print();

	Student * pstu = new Student(100, "小明"); //ok
	pstu->print();
	pstu->destroy();
	return 0;
}

