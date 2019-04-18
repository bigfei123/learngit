 ///
 /// @file    test.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-04-18 16:12:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
/*	旋转数组
 *1.把index1指向第一个数字，index2指向第二个数字,mid指向index1，index2中间的数字
 *2.若mid大于index1指向的数字，则mid处在第一个子数组中，并将index1指向mid的数字
 *	否则mid处在第二个子数组中，且小于index2指向的数字,将index2指向mid的数字
 *3.若index1和index2指向两个相邻的数字，则index2指向的是数组中的最小数字。
*/
int Min(int *numbers, int length)
{
	int index1 = 0;
	int index2 = length-1;
	//如果排序数组的前面的0个元素搬到最后面，即排序数组本身
	//此时，数字中的第一个数字就是最小的数字，可以直接返回.
	int indexMid = index1;
	while(numbers[index1] >= numbers[index2])
	{
		if(index2 - index1 == 1) {
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2)/2;
		if(numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if(numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

int main(void)
{
	int numbers[] = {3, 4, 5, 1, 2};
	int ret = Min(numbers, 5);
	cout << "ret = " << ret << endl;
	return 0;
}
