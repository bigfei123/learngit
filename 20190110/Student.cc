 ///
 /// @file    Student.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-10 19:52:49
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
	Student(int id, const char *name)
	: _id(id)
	, _name(new char[strlen(name)+1]())
	{
		cout << " Student(int ,const char *)" << endl;
		strcpy(_name ,name);
	}

	void print() const
	{
		cout << "id:" << _id <<endl
			 << "name:" << _name << endl;

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
	Student s1(101,"小红");//error
	s1.print();

	Student * pstu = new Student(100, "小明"); //ok
	pstu->print();
	delete pstu;
	return 0;
}

