#ifndef HEADER_H
#define HEADER_H

template <typename TYPE>
class Node
{
public:
	TYPE data;

	union
	{
		Node<TYPE>* next;
		Node<TYPE>* left;
	};

	union
	{
		Node<TYPE>* prev;
		Node<TYPE>* right;
	};

	Node();
	Node(const TYPE&, Node<TYPE>* = nullptr, Node<TYPE>* = nullptr);
};

template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
}

template <typename TYPE>
Node<TYPE>::Node(const TYPE& d, Node<TYPE>* n, Node<TYPE>* p)
{
	data = d;
	next = n;
	prev = p;
}

#endif HEADER_H