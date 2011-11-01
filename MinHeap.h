/*
 * MinHeap.h
 *
 *  Created on: 29-Oct-2011
 *      Author: prabhakar
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_
#define MAX 256

template <class T> class MinHeap {
	void buildMinHeap();
	int getLeftChild(int index);
	int getRightChild(int index);
protected:
	int heapSize;
	T *heap;
	void minHeapify(int index);
	int getParent(int index);
public:
	virtual ~MinHeap();
	MinHeap();
};

template <class T> inline void MinHeap<T>::buildMinHeap()
{
	for(int i=heapSize/2-1; i>=0; i--)
		minHeapify(i);
}

template <class T> inline int MinHeap<T>::getLeftChild(int index)
{
	return 2*index+1;
}

template <class T> inline int MinHeap<T>::getRightChild(int index)
{
	return 2*index+2;
}

template <class T> inline void MinHeap<T>::minHeapify(int index)
{
	int l = getLeftChild(index);
	int r = getRightChild(index);
	int smallest;
	if(l<heapSize && heap[l] < heap[index])
		smallest=l;
	else
		smallest=index;
	if(r<heapSize && heap[r] < heap[smallest])
		smallest=r;
	if(smallest != index){
		//exchange heap[index] with heap[largest]
		T temp=heap[index];
		heap[index]=heap[smallest];
		heap[smallest]=temp;
		minHeapify(smallest);
	}
}

template <class T> inline int MinHeap<T>::getParent(int index)
{
	if(index&1)
		return index/2;
	return index/2-1;
}

template <class T> inline MinHeap<T>::~MinHeap() {
	//delete heap;
	heapSize=0;
}

template <class T> inline MinHeap<T>::MinHeap()
{
	heap = new T[MAX];
	heapSize=0;
}

#endif /* MINHEAP_H_ */
