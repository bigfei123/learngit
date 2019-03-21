 ///
 /// @file    MyVector.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-29 19:21:13
 ///
 
#include <iostream>
#include <memory>
#include <algorithm>
using std::cout;
using std::endl;
 
template <class T>
class Vector
{
public:
	typedef T value_type;
	typedef T* iterator;

	Vector()
	: _start(nullptr)
	, _finish(nullptr)
	, _end_of_storage(nullptr)
	{}

	void push_back(const T & t);
	void pop_back();

	iterator begin() { return _start;	}
	iterator end()	 { return _finish;  }

	~Vector();

	int size() const { return _finish - _start;	}
	int capacity() const { return _end_of_storage - _start;	}
private:
	void reallocate(); //扩容操作，重新分配内存

private:
	static std::allocator<T> _alloc;
	T* _start;
	T* _finish;
	T* _end_of_storage;
};

template <class T>
std::allocator<T> Vector<T>::_alloc;


template <class T>
Vector<T>::~Vector()
{
	if(_start) {
		while(_finish != _start)
		{
			_alloc.destroy(--_finish);
		}
		
		_alloc.deallocate(_start, capacity());
	}
}

//当前元素是否装满？
//是--->重新分配空间
//否--->在_finish处构造对象,最后_finish + 1
//std::allocator::construct
//void construct(pointor p, const_reference val);
template <class T>
void Vector<T>::push_back(const T & t)
{
	if(size() == capacity()){
		reallocate();
	}

	if(_finish){
	//if(size() < capacity()) {
		_alloc.construct(_finish++, t);
	}
}

//判断当前capacity()是否为0?
//是--->赋值为 1 
//否--->把原来的大小翻倍
//std::allocator::allocate
//T* allocate(std::size_t n, const void * hint);
template <class T>
void Vector<T>::reallocate()
{
	int oldCapacity = capacity();
	int newCapacity = 2 * oldCapacity > 0 ? 2 * oldCapacity : 1;
	//_start是有空间的,需要把原来的空间释放，再重新开辟空间
	//_start = _alloc.allocate(newCapacity);
	T * ptmp = _alloc.allocate(newCapacity); //只开辟空间，在该空间上无对象
	if(_start){
		//std::copy(_start, _finish, ptmp); //copy算法只能在对象存在的时候使用,而当前空间无对象
		std::uninitialized_copy(_start, _finish, ptmp);
		//回收原来的空间
		while(_finish != _start){
			_alloc.destroy(--_finish); //_finish指向空间的下一个地址，需要先--
		}
	}
	_start = ptmp;
	_finish = _start + oldCapacity;
	_end_of_storage = _start + newCapacity;
}

//将_finish--即可
template <class T>
void Vector<T>::pop_back()
{
	if(size() > 0) {
		_alloc.destroy(--_finish);
	}
}

template <class Container>
void displayMyVector(Container & vec)
{
	cout << "vec's size = " << vec.size()<< endl 
		 << "vec's capacity = " << vec.capacity() << endl;
}


void test0()
{
	Vector<int> numbers;
	displayMyVector(numbers);

	numbers.push_back(1);
	displayMyVector(numbers);

	numbers.push_back(2);
	displayMyVector(numbers);
	
	numbers.push_back(3);
	displayMyVector(numbers);
	
	numbers.push_back(4);
	displayMyVector(numbers);
	
	numbers.push_back(5);
	displayMyVector(numbers);
	
	for(auto & elem : numbers){
		cout << elem << " ";
	}
	cout << endl;
}


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int) " << endl;	}

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy) 
	{cout << "Point(const Point &)}" << endl; }
	~Point() { cout << "~Point() " << endl; }

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	  int _ix;
	  int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")" ;
	return os;
}

void test1()
{
	Vector<Point> numbers;
	displayMyVector(numbers);

	numbers.push_back(Point(1,1));
	displayMyVector(numbers);

	numbers.push_back(Point(2,2));
	displayMyVector(numbers);

	numbers.push_back(Point(3,3));
	displayMyVector(numbers);

	numbers.push_back(Point(4,4));
	displayMyVector(numbers);

	numbers.push_back(Point(5,5));
	displayMyVector(numbers);

	
	for(auto & elem : numbers){
		cout << elem << " ";
	}
	cout << endl;
}

int main()
{
	//test0();
	test1();
	return 0;
}
