 ///
 /// @file    MinNumber2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-18 16:41:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
 
int MinInOrder(int * numbers, int index1, int index2)
{
	int result = numbers[index1];
	for(int i = index1 + 1; i <= index2; ++i) {
		if(result > numbers[i])
			result = numbers[i];
	}
	return result;
}

int Min(int * numbers, int length)
{
	if(numbers == nullptr || length <= 0)
		cerr << "Invalid parameters" << endl;
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while(numbers[index1] >= numbers[index2]) {
		if(index2 - index1 == 1) {
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2)/2;
	//如果index1、index2、indexMid指向的三个数字相等，只能进行顺序查找
	if(numbers[index1] == numbers[index2] &&
	   numbers[indexMid] == numbers[index1])
		return MinInOrder(numbers, index1, index2);

	if(numbers[indexMid] >= numbers[index1])
		index1 = indexMid;
	else if(numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}


int main(void)
{
	int numbers[] = {1, 0, 1, 1, 1};
	//int numbers[] = {3, 4, 5, 1, 2};
	int ret = Min(numbers, 5);
	cout << "ret = " << ret << endl;
	return 0;
}
