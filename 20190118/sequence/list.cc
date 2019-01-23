 ///
 /// @file    list.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-19 22:10:30
 ///
 
#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;
 

template <class Container>

void display(const Container & c)
{
	for(auto & elem : c) {  //使用auto时，要记得加上引用&符号，否则会进行复制
		cout << elem << " ";
	}
	cout << endl;
}

int main()
{
	list<int> numbers1{7, 7, 5, 6, 5, 5, 4, 7, 8};
	display(numbers1);
	cout << "test reverse:" << endl;
	numbers1.reverse(); //逆序输出
	display(numbers1);
	cout << "sort test : " << endl;
	numbers1.sort();  // 升序输出
	display(numbers1);
	std::less<int> lt;
	std::greater<int> gt; //函数对象，定制化操作
	numbers1.sort(lt);
	//numbers1.sort(std::less<int>());
	display(numbers1);
	numbers1.sort(gt);  //降序输出
	//numbers1.sort(std::greater<int>());  //降序输出
	display(numbers1); 
	cout << endl << "test unique:" << endl;
	numbers1.unique();
	numbers1.unique();
	display(numbers1); 

	cout << "test merge:" << endl;
	list<int> numbers2{11, 22, 33};
	numbers1.merge(numbers2); //链表合并
	display(numbers1); 
	display(numbers2);  //numbers2 没有元素了，全部合并到numbers1中去了

	cout << endl << "test splite:" << endl;
	list<int> numbers3{41, 42 ,43, 44, 45, 46, 47};
	list<int>::iterator it = numbers1.begin();
	++it; ++it;
	//numbers1.splice(it, numbers3);   //在指定下标处插入元素
	//display(numbers1);   

	auto it2 = numbers3.begin();   //若不注释前两句话，则it2指向为空。
	++it2; ++it2;
	cout << *it2<<endl;
	numbers1.splice(it, numbers3, it2);  //将在numbers3中it2指向的元素添加到number1，it指向的位置
	display(numbers1); 

	auto it3 = numbers1.end();
	--it3;
	numbers1.splice(numbers1.begin(), numbers1, it3); //在numbers1中将最后一个元素插入到第一个元素前
	display(numbers1);

}





