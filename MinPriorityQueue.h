/*
 * MinPriorityQueue.h
 *
 *  Created on: 29-Oct-2011
 *      Author: prabhakar
 */

#ifndef MINPRIORITYQUEUE_H_
#define MINPRIORITYQUEUE_H_

#include "MinHeap.h"
#include <string>
#include <sstream>
using namespace std;

template <class T> class MinPriorityQueue: public MinHeap<T> {
public:
	void insert(T x);
	string getData();
	T getMinimum();
	T extractMinimum();
	void decreaseKey(int x, T k);
	int getSize();
};

template <class T> inline void MinPriorityQueue<T>::insert(T x)
{
	this->heapSize++;
	this->heap[this->heapSize-1]=x;
	decreaseKey(this->heapSize-1, x);
}

template <class T> inline T MinPriorityQueue<T>::getMinimum()
{
	T temp=-1;
	if(this->heapSize==0)
		return temp;
	return this->heap[0];
}

template<class T> inline T MinPriorityQueue<T>::extractMinimum()
{
	T temp=-1;
	if(this->heapSize==0)
		return temp;
	T min=this->heap[0];
	this->heap[0]=this->heap[this->heapSize-1];
	this->heapSize--;
	this->minHeapify(0);
	return min;
}

template <class T> string MinPriorityQueue<T>::getData(){
	stringstream ss;
	for(int i=0; i<this->heapSize; i++)
		ss<<this->heap[i]<<endl;
	ss<<endl;
	return ss.str();
}
template <class T> void MinPriorityQueue<T>::decreaseKey(int x, T k)
{
	this->heap[x]=k;
	while(x>0 && this->heap[this->getParent(x)]>this->heap[x]){
		//exchange heap[x] with heap[parent(x)]
		T temp=this->heap[this->getParent(x)];
		this->heap[this->getParent(x)]=this->heap[x];
		this->heap[x]=temp;
		x=this->getParent(x);
	}
}

template<class T> inline int MinPriorityQueue<T>::getSize()
{
	return this->heapSize;
}

#endif /* MINPRIORITYQUEUE_H_ */
