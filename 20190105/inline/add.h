#ifndef  __ADD_H__
#define  __ADD_H__

//inline函数不能分成头文件和实现文件，
//其定义必须要放在头文件中才能正常调用
//
//注意：不要再inline函数中使用for循环，这样会导致代码膨胀

inline
int add(int x, int y);//函数的声明

int add(int x, int y)
{
	return x + y;
}
#endif
