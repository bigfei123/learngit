 ///
 /// @file    ReplaceBlank_2.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-07 20:30:53
 ///
 
//优化(O(N))
//从后往前遍历字符串,统计空格出现的次数，计算替换后的字符串长度
//再遍历一遍,完成替换每找到一个空格，需要将‘ ‘后面的字符串一次后移两位，预留出%20的空间
#include <iostream>
using std::cout;
using std::endl;
 
class Solution
{
public:
	//length为字符数组str的总容量
	void replaceBlank(char *str, int length)
	{
		//对传入空指针的处理
		if(str == nullptr && length <= 0)
			return ;
		//originalLength为字符串的实际长度
		int originalLength = 0;
		int numberofBlank = 0;
		int i =0;
		while(str[i] != '\0') {
			++ originalLength;

			if(str[i] == ' ')
				++ numberofBlank;

			++ i;
		}

		//newLength 为把空格替换成%20之后的长度

		int newLength = originalLength + numberofBlank * 2;
		//对newLength的异常处理
		if(newLength > length)
			return ;
		int indexofOriginal = originalLength;
		int indexofNew = newLength;
		while(indexofOriginal >= 0 && indexofNew > indexofOriginal) {
			if(str[indexofOriginal] == ' ') {
				str[indexofNew--] = '0';
				str[indexofNew--] = '2';
				str[indexofNew--] = '%';
			}else {
				str[indexofNew--] = str[indexofOriginal];
			}
			//indexofOriginal每循环一次减一
			indexofOriginal--;
		}
	}
};

int main(void)
{
	char str[13] = "a b c d";
	Solution solu;
	solu.replaceBlank(str, 13);
	cout << str << endl;
}
