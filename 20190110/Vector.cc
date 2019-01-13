 ///
 /// @file    Vector.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-11 08:47:12
 ///
 
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void printVectorCapacity(const vector<int> & v1)
{
	cout << "v1's size = " << v1.size() << endl
		 << "v1's capacity = " << v1.capacity() << endl;
}



int main(void)
{
	//动态数组，可以自动扩容，但动态扩容是有开销的
	//策略： 当size == capacity 时， 就在去开辟新的空间2*size
	//		 再把原来的空间的元素复制到新空间，并释放原来的空间
	//		最后在新空间的末尾添加新的元素
 
	vector<int> numbers;
//	numbers.reserve(60);   //reserve()方法为开空间。 提前开辟好空间，之后再去使用就不会在频繁地动态扩容
	printVectorCapacity(numbers);

	numbers.push_back(1);
	printVectorCapacity(numbers);
	
	
	numbers.push_back(2);
	printVectorCapacity(numbers);
	

	numbers.push_back(3);
	printVectorCapacity(numbers);

	
	numbers.push_back(4);
	printVectorCapacity(numbers);
	 

	numbers.push_back(5);
	printVectorCapacity(numbers);
	 

	numbers.push_back(5);
	printVectorCapacity(numbers);


	numbers.push_back(6);
	printVectorCapacity(numbers);

	
	numbers.push_back(6);
	printVectorCapacity(numbers);

	return 0;
}
