 ///
 /// @file    ReplaceBlank_1.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-07 20:30:53
 ///
 
//暴力替换
//从后往前遍历字符串
//每找到一个空格，需要将‘ ‘后面的字符串一次后移两位，预留出%20的空间
#include <iostream>
using std::cout;
using std::endl;
 
class Solution
{
public:
	void replaceBlank(char *str, int length)
	{
		int i = length;
		int j = 0;
		int len = length;
		//从后往前遍历
		for(; i > 0; i--) {
			//如果当前字符是空格
			if(str[i] == ' ') {
				// 总长度+2
				len += 2;
				for(j = len ; j > i + 2; j--) {
					str[j] = str[j -2];
				}
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '%';
			}
			cout << str << endl;
		}
		str[len] = '\0';
	}
};

int main(void)
{
	//13为提前预估好总长度
	char str[13] = "a b c d";
	Solution solu;
	solu.replaceBlank(str, 7);//7为字符实际长度
	cout << str << endl;
}
