 ///
 /// @file    mem_fn.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-29 18:48:13
 ///
 
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::for_each;


class Number
{
public:
	Number(size_t data = 0)
	: _data(data)
	{}

	void display() const
	{ 
		cout << _data << " ";  
	}

	bool isEven() const
	{
		return (_data % 2 == 0);
	}

	bool isPrime() const
	{
		if(_data == 1)
			return false;
		for(size_t idx = 2; idx <= _data / 2; ++idx){
			if(_data % idx == 0)
				return false;
		}
		return true;
	}

private:
	size_t _data;
};

int main(void)
{
	vector<Number> numbers;
	for(size_t idx = 1; idx != 20; ++idx)
		numbers.push_back(Number(idx));
	//对于自定义类类型，如要通过迭代器的方式进行访问，可以使用mem_fn来进行适配
	for_each(numbers.begin(), numbers.end(),std::mem_fn(&Number::display));
	cout << endl;

	auto it = remove_if(numbers.begin(), numbers.end(),std::mem_fn(&Number::isEven));
	numbers.erase(it, numbers.end());
	for_each(numbers.begin(), numbers.end(),std::mem_fn(&Number::display));
	cout << endl;

	auto iter = remove_if(numbers.begin(), numbers.end(),std::mem_fn(&Number::isPrime));
	numbers.erase(iter, numbers.end());
	for_each(numbers.begin(), numbers.end(),std::mem_fn(&Number::display));
	cout << endl;
}
