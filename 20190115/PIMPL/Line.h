 ///
 /// @file    Line.h / @author  bigfei775655478@qq.com)
 /// @date    2019-01-17 11:49:56
 ///
#ifndef __DF_LINE_H__ 
#define __DF_LINE_H__
#include <iostream>
		
//设计模式：PIMPL
//作用：1.实现信息隐藏,只提供函数的接口
//		2.减小编译依赖，提高编译速度
//		3.以最小的代价实现库的平滑升级

//嵌套类的高级用法

class Line
{
public:
	Line(int ,int ,int ,int );
	~Line();

	void printLine() const;

	class LineImpl; //前向声明

private:
	LineImpl * _pimpl; //指向类LineImpl的指针
};
#endif
