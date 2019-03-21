 ///
 /// @file    vector.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-02-01 12:13:21
 ///
 
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
 
class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

	~Point()
	{	cout << "~Point()" << endl;	}

private:
	int _ix;
	int _iy;
};

int main(void)
{
	vector<Point *> numbers;
	numbers.push_back(new Point(1, 2));
	return 0;
}
