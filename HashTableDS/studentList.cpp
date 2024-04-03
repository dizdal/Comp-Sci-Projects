#include <iostream>
using namespace std;
#include "hashTable.h"
#include "student.h"

void process(HashTable<Student>& list);
char getChoice();
void buildList(HashTable<Student>& list);
void displayStudents(HashTable<Student>& list);
void printStudents(HashTable<Student>& list);
void addStudent(HashTable<Student>& list);
void findStudent(HashTable<Student>& list);
void removeStudent(HashTable<Student>& list);
void displayStatistics(HashTable<Student>& list);

int main()
{
	HashTable<Student> studentList(61);
	buildList(studentList);
	process(studentList);

	return 0;
}

void buildList(HashTable<Student>& list)
{
	ifstream inFile("studentFile.txt");
	Student student;

	while (inFile >> student.id)
	{
		inFile.ignore();
		inFile.getline(student.name, 51);
		inFile.getline(student.cityState, 51);
		inFile.getline(student.phone, 13);
		inFile >> student.gender >> student.year
			>> student.credits >> student.gpa >> student.major;

		list.insert(student);
	}
}

char getChoice()
{
	char choice;
	bool valid;

	cout << "======== MENU ========\n"
		<< "A:   Add a new student\n"
		<< "F:   Find a student record\n"
		<< "R:   Remove a student\n"
		<< "S:   Display statistics\n"
		<< "D:   Display students\n"
		<< "P:   Print students to file\n"
		<< "Q:   Quit\n\n"
		<< "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'A': valid = true;
			break;

		case 'F': valid = true;
			break;

		case 'R': valid = true;
			break;

		case 'S': valid = true;
			break;

		case 'D': valid = true;
			break;

		case 'P': valid = true;
			break;

		case 'Q': valid = true;
			break;

		default: valid = false;
			cout << "\aInvalid choice\n" << "Please try again: ";
			break;
		}

	} while (!valid);

	return choice;
}

void displayStudents(HashTable<Student>& list)
{
	list.displayTable();
}

void printStudents(HashTable<Student>& list)
{
	list.writeFile();
	cout << "Hash Table was printed to file.\n" << endl;
}

void addStudent(HashTable<Student>& list)
{
	Student newStudent;

	cout << "\nPlease enter information for the new student: \n";
	cout << "Student's ID number: ";
	cin >> newStudent.id;
	cin.ignore();

	cout << "Student's name (Last, First Middle): ";
	cin.getline(newStudent.name, 50);

	cout << "Student's city and state (City, State): ";
	cin.getline(newStudent.cityState, 50);

	cout << "Student phone number: ";
	cin.getline(newStudent.phone, 12);

	cout << "Student's gender: ";
	cin >> newStudent.gender;

	cout << "Student's grade level (1 = freshman, 2 = sophomore, etc.): ";
	cin >> newStudent.year;

	cout << "Student's gpa: ";
	cin >> newStudent.gpa;
	cin.ignore();

	cout << "Student's major: ";
	cin.getline(newStudent.major, 6);

	list.insert(newStudent);
	cout << endl;
}

void process(HashTable<Student>& list)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A': addStudent(list);
			break;

		case 'F': findStudent(list);
			break;

		case 'R': removeStudent(list);
			break;

		case 'S': displayStatistics(list);
			break;

		case 'D': displayStudents(list);
			break;

		case 'P': printStudents(list);
			break;

		case 'Q': break;
		}
	} while (choice != 'Q');
}

void findStudent(HashTable<Student>& list)
{
	Student searchStudent;

	cout << "\nPlease enter the ID of the student you wish to search for. \n";
	cout << "Student's ID number: ";
	cin >> searchStudent.id;
	cin.ignore();

	if (list.retrieve(searchStudent) == true)
	{
		cout << "\nStudent found in list. Here's their information: \n" << endl;
		
		cout << "Student ID: " << searchStudent.id
			<< "\nStudent Name (Last, First): " << searchStudent.name
			<< "\nStudent City and State: " << searchStudent.cityState
			<< "\nStudent Phone Number: " << searchStudent.phone
			<< "\nStudent Gender: " << searchStudent.gender
			<< "\nStudent Year (1 = Freshman, 2 = Sophomore, etc.): " << searchStudent.year
			<< "\nStudent GPA: " << searchStudent.gpa
			<< "\nStudent Major: " << searchStudent.major << endl << endl;
	}

	else
	{
		cout << "\nStudent not found in list.\n" << endl;
	}
}

void removeStudent(HashTable<Student>& list)
{
	Student removeStudent;

	cout << "\nPlease enter information for the student you wish to remove. \n";
	cout << "Student's ID number: ";
	cin >> removeStudent.id;
	cin.ignore();

	if (list.remove(removeStudent) == true)
	{
		cout << "\nStudent removed from list.\n" << endl;
	}

	else
	{
		cout << "\nStudent not found in list.\n" << endl;
	}
}

void displayStatistics(HashTable<Student>& list)
{
	list.statistics();
	cout << endl;
	
	if (list.isEmpty() == true)
	{
		cout << "Table is empty.\n" << endl;
	}

	else
	{
		cout << "Table is not empty\n" << endl;
	}
}