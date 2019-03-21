 ///
 /// @file    QuickSort.h
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-26 17:07:13
 ///

#ifndef _QUICKSORT_H__
#define _QUICKSORT_H__

#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;
using std::endl;
using std::cout;

template <class T>
class QuickSort
{
public:
	void quicksort(vector<T> & vec, int first, int last){
		int lower = first + 1;
		int upper = last;
		std::swap(vec[first], vec[(first + last)/2]);
		key = vec[first];
		while(lower <= upper)
		{
			while(vec[lower] < key)
				lower++;
			while(vec[upper] > key)
				upper--;
			if(lower < upper)
				std::swap(vec[lower++], vec[upper--]);
			else lower++;
		}
		std::swap(vec[upper], vec[first]);
		if(first < upper - 1) 
			quicksort(vec, first, upper -1);
		if(upper + 1 < last)
			quicksort(vec, upper + 1, last);
	}
	
	template <class Container>
	void display(const Container & c)	
	{
		for(auto & elem : c){
			cout << elem << " ";
		}
		cout << endl;
	}

		
private:
	int lower;
	int upper;
	T key;
};




#endif
