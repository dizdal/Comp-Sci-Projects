#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "customer.h"
#include "heap.h"

void getData(Heap<Customer>& waitList);
void printWaitList(Heap<Customer>& waitList);

int main()
{
	Heap<Customer> waitList;
	getData(waitList);
	printWaitList(waitList);
}

void getData(Heap<Customer>& waitList)
{
	Customer cust;
	ifstream inFile;
	inFile.open("overbooked.bin", ios::binary);

	while (inFile.read((char*)&cust, sizeof(cust)))
	{
		cust.priority = (cust.mileage / 1000) + cust.years - cust.arrivalNum;
		waitList.insert(cust);
	}

	inFile.close();
}

void printWaitList(Heap<Customer>& waitList)
{
	Customer cust;
	ofstream outFile;
	outFile.open("waitList.txt");
	
	outFile << string(30, '-');
	outFile << setw(15) << "Customer Flight Records";
	outFile << string(30, '-') << endl;
	outFile << endl;

	outFile << "Priority:";
	outFile << setw(14) << "First Name:" << setw(14) << "Last Name:" 
		<< setw(17) << "Arrival #:" << setw(11) << "Years:" << setw(14) <<
		"Miles:" << endl;

	while (waitList.remove(cust))
	{
		outFile << cust;
	}
}