#include <iostream>
#include <fstream>
#include <iomanip>
#include "node.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

template <typename TYPE>
class HashTable
{
	private:
		Node<TYPE>* table;
		int size;
		bool _isPrime(int s) const;
		int _hash(const TYPE& dataIn) const;
		void _tableOut(ostream& out) const;

	public:
		HashTable(int s = 23);
		~HashTable();
		bool insert(const TYPE& dataIn);
		void writeFile() const;
		void displayTable() const;
		bool remove(TYPE& dataOut);
		bool retrieve(TYPE& dataOut) const;
		bool isEmpty() const;
		void statistics() const;
};

template <typename TYPE>
HashTable<TYPE>::HashTable(int s)
{
	s += 1;

	if (s % 2 == 0)
	{
		s += 1;
	}

	while (_isPrime(s) == false)
	{
		s += 2;
	}

	size = s;
	table = new Node<TYPE>[size];
}

template <typename TYPE>
bool HashTable<TYPE>::_isPrime(int num) const
{
	bool result = true;

	for (int i = 3; i < 20 && result == true; i += 2)
	{

		if (num % i == 0)
		{
			result = false;
		}
	}

	return result;
}

template <typename TYPE>
HashTable<TYPE>::~HashTable()
{
	Node<TYPE>* pTemp;

	for (int i = 0; i < size; i++)
	{

		while (table[i].next != nullptr)
		{
			pTemp = table[i].next;
			table[i].next = pTemp->next;
			delete pTemp;
		}
	}

	delete[] table;
	size = 0;
}

template <typename TYPE>
int HashTable<TYPE>::_hash(const TYPE& dataIn) const
{
	return dataIn % size;
}

template <typename TYPE>
bool HashTable<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pNew;
	int loc;

	loc = _hash(dataIn);

	if (table[loc].data == 0)
	{
		table[loc].data = dataIn;
		success = true;
	}

	else
	{
		pNew = new (nothrow) Node<TYPE>(dataIn, table[loc].next);

		if (pNew != nullptr)
		{
			table[loc].next = pNew;
			success = true;
		}
	}

	return success;
}

template <typename TYPE>
void HashTable<TYPE>::writeFile() const
{
	ofstream outFile("studentTable.txt");
	_tableOut(outFile);
	outFile.close();
}

template <typename TYPE>
void HashTable<TYPE>::displayTable() const
{
	_tableOut(cout);
}

template <typename TYPE>
void HashTable<TYPE>::_tableOut(ostream& out) const
{
	Node<TYPE>* pTemp;

	out << '\n' << "Address" << setw(11) << "Prime Area" << setw(15) << "Overflow";

	for (int i = 0; i < size; i++)
	{

		if (i < 10)
		{
			out << '\n' << "[0" << i << "]";
		}

		else if (i >= 10)
		{
			out << '\n' << "[" << i << "]";
		}

		if (table[i].data != 0)
		{
			out << setw(7) << table[i].data;
		}

		if (table[i].next != nullptr)
		{
			pTemp = table[i].next;

			while (pTemp != nullptr)
			{
				out << setw(10) << pTemp->data;

				if (pTemp->next != nullptr)
				{
					out << ',';
				}
				pTemp = pTemp->next;
			}
		}
	}
	
	out << '\n' << '\n';
}

template <typename TYPE>
bool HashTable<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	int loc;
	Node<TYPE>* pTemp;
	Node<TYPE>* pPrev;

	loc = _hash(dataOut);
	pTemp = table[loc].next;
	pPrev = &table[loc];

	if (table[loc].data == dataOut)
	{
		dataOut = table[loc].data;

		if (table[loc].next == nullptr)
		{
			table[loc].data = 0;
		}

		else
		{
			table[loc] = *pTemp;
			delete pTemp;
		}

		success = true;
	}

	else
	{

		while ((pTemp != nullptr) && (pTemp->data != dataOut))
		{
			pPrev = pTemp;
			pTemp = pTemp->next;
		}

		if ((pTemp != nullptr) && (pTemp->data == dataOut))
		{
			dataOut = pTemp->data;

			if (pPrev != nullptr)
			{
				pPrev->next = pTemp->next;
			}
			
			delete pTemp;
			success = true;
		}
	}

	return success;

}

template <typename TYPE>
bool HashTable<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;
	int loc;
	Node<TYPE>* pTemp;

	loc = _hash(dataOut);
	pTemp = table[loc].next;

	if (table[loc].data == dataOut)
	{
		dataOut = table[loc].data;
		success = true;
	}

	else
	{

		while ((pTemp != nullptr) && (pTemp->data != dataOut))
		{
			pTemp = pTemp->next;
		}

		if ((pTemp != nullptr) && (pTemp->data == dataOut))
		{
			dataOut = pTemp->data;
			success = true;
		}
	}

	return success;
}

template <typename TYPE>
bool HashTable<TYPE>::isEmpty() const
{
	bool success = true;

	for (int i = 0; (i < size) && (success == true); i++)
	{

		if (table[i].data != 0)
		{
			success = false;
		}
	}

	return success;
}

template <typename TYPE>
void HashTable<TYPE>::statistics() const
{
	int countElems = 0;
	int countFull = 0;
	int countCollisions = 0;
	int tempChainCount;
	int maxChain = 0;
	int numDiffOverflows = 0;
	Node<TYPE>* pTemp;

	for (int i = 0; i < size; i++)
	{

		if (table[i].data != 0)
		{
			countElems++;
			countFull++;
		}

		if (table[i].next != nullptr)
		{
			pTemp = table[i].next;
			tempChainCount = 0;
			numDiffOverflows++;

			while (pTemp != nullptr)
			{
				countElems++;
				countCollisions++;
				tempChainCount++;
				pTemp = pTemp->next;
			}

			if (tempChainCount > maxChain)
			{
				maxChain = tempChainCount;
			}
		}
	}


	cout << "\nTable Size: " << setw(15) << size << endl;
	cout << "Number of Elements: " << setw(7) << countElems << endl;
	cout << "Empty Positions: " << setw(10) << (size - countFull) << endl;
	cout << "Num. of Chains: " << setw(11) << numDiffOverflows << endl;
	cout << "Max Chain Length: " << setw(9) << maxChain << endl;
	cout << "Num. of Collisions: " << setw(7) << countCollisions << endl;
	cout << "Avg. Chain Length: " << setw(9) << fixed << setprecision(1) << 
		(static_cast<double>(countCollisions) / static_cast<double>(numDiffOverflows)) << endl;
	cout << "Percent Collisions: " << setw(9) << ((static_cast<double>(countCollisions) /
		static_cast<double>(countElems)) * 100) << " %" << endl;
	cout << "Load Factor: " << setw(16) << ((static_cast<double>(countFull) /
		static_cast<double>(size)) * 100) << " %" << endl;
	cout << "Avg # Search Steps: " << setw(10) << fixed << setprecision(3) << 
		((static_cast<double>(countFull)) / 
			static_cast<double>(countElems)) << endl;
}

#endif HASHTABLE_H