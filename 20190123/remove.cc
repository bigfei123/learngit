 ///
 /// @file    remove.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-29 10:42:14
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::remove_if;

bool func(int number)
{
	return number > 4;
}

int test0()
{
	vector<int> numbers{1, 3, 4, 6, 2, 7, 0};
	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//remove_if(Forword first, Forword last, UnaryPredicate p)//一元断言 binary predicate 二元断言
	auto it = remove_if(numbers.begin(), numbers.end(), [](int number){
			return number > 4;
	});
	numbers.erase(it,numbers.end());//删除>4的元素

	//erase-remove惯用法
	//numbers.erase(remove_if(numbers.begin(), numbers.end(),[](int number){
	//	return number > 4;
	//}), numbers.end());
	
	std::less<int> lt; //bind1st ==> lt(4, rhs);  
					   //bind2nd ==> lt(lhs, 4); std::bind1st 和 std::bind2nd将二元函数转换为一元函数
	auto iter = remove_if(numbers.begin(), numbers.end(), std::bind1st(lt, 4));
	//bind1st 将4绑定为第一个参数,即4 < value
	//bind2nd 将4绑定为第二个参数,即value < 4
	numbers.erase(iter, numbers.end());
	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;

}

void test1()
{
	//在遍历元素的过程中，不要轻易做删除元素后添加元素的操作
	vector<int> numbers;
	numbers.push_back(1);
	cout << endl << "number's capacity = " << numbers.capacity() << endl;
	bool flag = true;
	for(auto it = numbers.begin(); it != numbers.end(); ++it){
		cout << *it << " ";
		if(flag){
			numbers.push_back(2); //底层发生了扩容操作，迭代器it失效
			cout << endl << "number's capacity = " << numbers.capacity() << endl;
			flag = false;
			it = numbers.begin(); //重新获取位置
		}
	}
}

int main(void)
{
	//test0(); 
	test1();
}
