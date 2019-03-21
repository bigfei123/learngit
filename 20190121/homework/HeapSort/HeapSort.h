 ///
 /// @file    HeapSort.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-26 15:56:17
 ///
#ifndef _HEAPSORT_H__
#define _HEAPSORT_H__
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
template <class T>
class HeapSort
{
public:
	HeapSort(const vector<T> & array){
		_array.assign(array.begin(), array.end());
	}

	template <class Compare>
	void Sort(Compare comp)
	{
		PrintArray(_array);
		CreatHeap(comp);         //建堆
		vector<T> array;
		for(int idx = _array.size() - 1; idx >= 0; idx--)
		{
			array.push_back(_array[0]);     //保留堆顶
			std::swap(_array[0], array[idx]);      //交换
			_array.pop_back();				//去掉最后一个元素
			DownElement(0, comp);			//将新的首元素下沉
		}
		PrintArray(array);
		_array.assign(array.begin(), array.end());
	}

	template <class Compare>
	void CreatHeap(Compare comp)  //创建堆
	{
		//从最后一个非叶子节点开始，将每个父节点都调整为最小堆
		for(int idx = _array.size()/2-1; idx>=0; idx--)
		{
			DownElement(idx, comp);
		}
	}

	template <class Compare>
	void DownElement(int _elem, Compare comp) //下沉元素
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
				std::swap(_array[min], _array[idx]);
				idx = min;
			}
		}
	}

	void PrintArray(const vector<T> & array)
	{
		for(int idx=0; idx<array.size(); ++idx)
		{
			cout << array[idx] << " ";
		}
		cout << endl;
	}

private:
	vector<T> _array;
};
#endif
