#include <iostream>
using std::cout;
using std::endl;

int test0()
{
	int number1=10;
	double number2=11.11;
	number1=(int)number2;
	//number1=int(number2);
	cout << "number1=" <<number1 <<endl;
	return 0;
}

void test1()
{
	int number1=10;
	double number2=11.11;
	int number3(12);
	cout << "number3=" << number3<<endl;

	number1= static_cast<int>(number2);
	cout<<"number1=" <<number1<<endl;
	int *pInt=static_cast<int *>(malloc(sizeof(int)));
	*pInt=10;
	cout << "*pInt=" << *pInt<<endl;
	
	free(pInt);

}

int main(void)
{
	test0();
	test1();
	return 0;
}
