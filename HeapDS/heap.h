#include <algorithm>
#include <iostream>

#ifndef HEAP_H
#define HEAP_H

template <typename TYPE>
class Heap
{
	private:
		TYPE* heap;
		int numValues;
		int capacity;
		void _siftUp(int c);
		void _siftDown(int p);
		int _leftChildOf(int p) const;
		int _parentOf(int c) const;

	public:
		Heap(int c = 100);
		~Heap();
		bool insert(const TYPE& dataIn);
		bool remove(TYPE& dataOut);
		bool viewMax(TYPE& dataOut) const;
		int getCapacity() const;
		int getNumValues() const;
		bool isEmpty() const;
		bool isFull() const;
};

template <typename TYPE>
Heap<TYPE>::Heap(int c)
{
	numValues = 0;
	capacity = c;
	heap = new TYPE[capacity];
}

template <typename TYPE>
Heap<TYPE>::~Heap()
{
	numValues = 0;
	capacity = 0;
	delete heap;
}

template <typename TYPE>
void Heap<TYPE>::_siftUp(int child)
{
	int parent;

	if (child > 0)
	{
		parent = _parentOf(child);

		if (heap[child] > heap[parent])
		{
			swap(heap[child], heap[parent]);
			_siftUp(parent);
		}
	}
}

template <typename TYPE>
void Heap<TYPE>::_siftDown(int parent)
{
	int child;
	child = _leftChildOf(parent);

	if (child < numValues)
	{
		
		if (((child + 1) < numValues) && (heap[child] < heap[child + 1]))
		{
			child++;
		}

		if (heap[parent] < heap[child])
		{
			swap(heap[parent], heap[child]);
			_siftDown(child);
		}
	}
}

template <typename TYPE>
int Heap<TYPE>::_leftChildOf(int p) const
{
	return ((2 * p) + 1);
}

template <typename TYPE>
int Heap<TYPE>::_parentOf(int c) const
{
	return ((c - 1) / 2);
}

template <typename TYPE>
bool Heap<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;

	if (numValues < capacity)
	{
		heap[numValues] = dataIn;
		_siftUp(numValues);
		numValues++;
		success = true;
	}

	return success;
}

template <typename TYPE>
bool Heap<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = heap[0];
		heap[0] = heap[numValues - 1];
		numValues--;
		_siftDown(0);
		success = true;
	}

	return success;
}

template <typename TYPE>
bool Heap<TYPE>::viewMax(TYPE& dataOut) const
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = heap[0];
		cout << heap[0];
	}

	return success;
}

template <typename TYPE>
int Heap<TYPE>::getCapacity() const
{
	return capacity;
}

template <typename TYPE>
int Heap<TYPE>::getNumValues() const
{
	return numValues;
}

template <typename TYPE>
bool Heap<TYPE>::isEmpty() const
{
	return (numValues == 0);
}

template <typename TYPE>
bool Heap<TYPE>::isFull() const
{
	return (numValues == capacity);
}

#endif HEAP_H