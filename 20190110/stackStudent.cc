 ///
 /// @file    Student.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 19:52:49
 ///
#include <cstring> 
#include <iostream>
using std::cout;
using std::endl;
//只能生成栈对象
//1.该对象只能放在栈上，不能放在堆上
//2.采取的操作是：将operator new/delete 放在private中
//
class Student
{
public:
	Student(int id, const char *name)
	: _id(id)
	, _name(new char[strlen(name)+1]())
	{
		cout << " Student(int ,const char *)" << endl;
		strcpy(_name, name);
	}

	void print() const
	{
		cout << "id:" << _id <<endl
			 << "name:" << _name << endl;

	}

	~Student()
	{
		delete [] _name;
		cout << "~Student()" << endl;
	}
	
	
private:
	void * operator new(size_t size);
	void operator delete(void * pret);
private:
	int _id;
	char *_name;
	

};



int main(void)
{
	Student s1(101,"小红");
	s1.print();

	//Student * pstu = new Student(100, "小明"); //error
	//pstu->print();//error

	//delete pstu;//error
	return 0;
}

