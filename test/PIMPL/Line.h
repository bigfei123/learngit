 ///
 /// @file    Line.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-03-05 15:38:33
 ///
 
#ifndef __LINE_H__
#define __LINE_H__

//设计模式：PIMPL

class Line
{
public:
	Line(int ,int ,int ,int);
	~Line();

	void printLine() const;

	class LineImpl; //前向声明

private:
	LineImpl * _pimpl;//指向类LineImpl的指针
};

#endif
