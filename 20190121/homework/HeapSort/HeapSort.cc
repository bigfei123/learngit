 ///
 /// @file    HeapSort.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-26 15:56:07
 ///
 
#include "HeapSort.h"
#include <vector> 
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

template <class T>
template <class Compare>
void HeapSort<T>::Sort(Compare comp)
{
	PrintArray(_array);
	CreatHeap(comp);         //建堆
	vector<T> array;
	for(int idx = _array.size() - 1; idx >= 0; idx--)
	{
		array.push_back(_array[0]);     //保留堆顶
		swap(_array[0], array[idx]);      //交换
		_array.pop_back();				//去掉最后一个元素
		DownElement(0, comp);			//将新的首元素下沉
	}
	PrintArray(array);
	_array.assign(array.begin(), array.end());
}

template <class T>
template <class Compare>
void HeapSort<T>::CreatHeap(Compare comp)
{
	//从最后一个非叶子节点开始，将每个父节点都调整为最小堆
	for(int idx = _array.size()/2-1; idx>=0; idx--)
	{
		DownElement(idx, comp);
	}
}

template <class T>
template <class Compare>
void DownElement(int _elem, Compare comp)    //下沉元素
{
	int min;			//设置最小元素下标
	int idx = _elem;    //当前下沉的元素下标
	while(idx*2+1 < _array.size()) //存在左节点
	{
		min = idx*2 + 1;
		if(idx*2 + 2 < _array.size()) //存在右节点
		{
			//左右节点比较，选出最小的
			if(comp(_array[idx*2 + 2], _array[min]))
			{
				min = idx*2 + 2;
			}
		}

		//同子节点比较，若父节点最小则结束
		if(comp(_array[idx], _array[min]))
		{
			break;
		}
		else //选最小元素到父节点
		{
			swap(_array[min], _array[idx]);
			idx = min;
		}
	}
}

template <class T>
void PrintArray(const vector<T> & array)
{
	for(int idx=0; idx<array.size(); ++idx)
	{
		cout << array[idx] << " ";
	}
	cout << endl;
}


