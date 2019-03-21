#include <iostream>
using std::cout;
using std::endl;

//引用与指针的异同？

void test0()
{
	int number =10;
	int &ref= number;


	cout << "修改之前："<<endl;
	cout << "number=" <<number<<endl;
	cout <<"ref="<<ref<<endl;

	ref=100;
	cout << endl << "修改之后：" << endl;
	cout << "number=" << number << endl;
	cout << "ref=" << ref << endl;
	cout << "&number= "<< &number <<endl;
	cout << "&ref= " << &ref <<endl;
}

void swap(int *px, int *py)
{
	int temp=*px;
		*px=*py;
		*py=temp;
}
void swap(int & x, int& y)
{
	int temp=x;
	x=y;
	y=temp;
}

void test1()
{
	int a = 3;
	int b = 4;
	int *A = &a;
	int *B = &b;
	cout << "交换之前："<< endl;
	cout << "a="<< a << endl;
	cout << "b="<< b << endl;
	swap(A,B);
	cout << "交换之后" <<endl;
	cout << "a="<< a<< endl;
	cout << "b=" <<b <<endl;
}

int func()
{
	int number=10;
	return number;//执行return就会复制
}
//2.引用作为函数的返回值，执行return语句时不会进行复制，直接返回实体本身
//  前提条件：返回的实体其生命周期一定要大于函数
int array[10]={1,2,3,4,5};
int & getIndex(int idx)
{
	return array[idx];
}

int  *func2()
{
	int number =10;//这种用法是错误的
	return & number;
}

//不要返回局部变量的引用
int &getNumber()
{
	int number=10;//局部变量只存在于函数的栈空间
	return number;//当函数执行完毕后，栈空间会被销毁，局部变量也被销毁
				  //既然已经被销毁了，再去操作它就没有意义了
}

//不要轻易去返回一个堆空间变量的引用，这样做有可能发生内存泄漏
//除非有了一个内存回收的策略
int & getHeapVariable()
{
	int *pNumber=new int(10);
	return *pNumber;
}

void test2()
{
	cout<< "getIndex(0)= " << getIndex(0) << endl;
	getIndex(0) =10;
	cout << "getIndex(0)= " << getIndex(0) <<endl;
	cout << "array[0]=" <<array[0]<<endl;
}

void test3()
{
	int a=1,b=2;
	int c=a+getHeapVariable()+b;
	cout <<"c="<<c<<endl;

	int &ref = getHeadVariable();
	cout << "ref=" << ref <<endl;
	delete &ref;
}



	
int main()
{

	//test0();
	//test1();
	//test2();
	test3();
	return 0;
}

