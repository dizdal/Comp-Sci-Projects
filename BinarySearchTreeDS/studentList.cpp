#include <iostream>

using namespace std;

#include "BST.h"
#include "student.h"

void buildList(BST<Student>& list);
char getChoice();
void process(BST<Student>& list);
void addStudent(BST<Student>& list);
void findStudent(BST<Student>& list);
void removeStudent(BST<Student>& list);
void displayStudents(BST<Student>& list);
void listInfo(BST<Student>& list);
void updateStudent(BST<Student>& list);

int main()
{
	BST<Student> studentList;
	buildList(studentList);
	process(studentList);

	return 0;
}

void buildList(BST<Student>& list)
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
		<< "S:   Search for a student\n"
		<< "U:   Update a student's info\n"
		<< "D:   Delete a student record\n"
		<< "P:   Print list of students\n"
		<< "X:   Show list information\n"
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

		case 'S': valid = true;
			break;

		case 'U': valid = true;
			break;

		case 'D': valid = true;
			break;

		case 'P': valid = true;
			break;

		case 'X': valid = true;
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

void process(BST<Student>& list)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A': addStudent(list);
			break;

		case 'S': findStudent(list);
			break;

		case 'U': updateStudent(list);
			break;

		case 'D': removeStudent(list);
			break;

		case 'P': displayStudents(list);
			break;

		case 'X': listInfo(list);
			break;

		case 'Q': break;
		}
	} while (choice != 'Q');
}

void addStudent(BST<Student>& list)
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

	cout << "Student's current amount of credits: ";
	cin >> newStudent.credits;

	cout << "Student's gpa: ";
	cin >> newStudent.gpa;
	cin.ignore();

	cout << "Student's major: ";
	cin.getline(newStudent.major, 6);

	list.insert(newStudent);
	cout << endl;
}

void findStudent(BST<Student>& list)
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

void removeStudent(BST<Student>& list)
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

void displayStudents(BST<Student>& list)
{
	cout << endl << setw(7) << "ID:" << setw(30) << "Name:" << setw(10) 
		<< "GPA:" << setw(10) << "Major:" << endl;
	list.inorderTraverse(display1Student);
	cout << endl;
}

void listInfo(BST<Student>& list)
{
	cout << "\nNumber of students in the list: " << list.getCount();
	cout << "\nHeight of tree: " << list.getHt() << endl;

	if (list.isEmpty() == true)
	{
		cout << "Table is empty.\n";
	}

	else
	{
		cout << "Table is not empty\n";
	}

	if (list.isFull() == true)
	{
		cout << "Table is full.\n";
	}

	else
	{
		cout << "Table is not full\n";
	}

	if (list.isComplete() == true)
	{
		cout << "Table is complete.\n";
	}

	else
	{
		cout << "Table is not complete\n";
	}

	if (list.isBalanced() == true)
	{
		cout << "Table is empty.\n";
	}

	else
	{
		cout << "Table is not empty\n";
	}

	cout << endl;
}

void updateStudent(BST<Student>& list)
{
	Student searchStudent;
	Student tempStudent;

	cout << "\nPlease enter the ID of the student you wish to update. \n";
	cout << "Student's ID number: ";
	cin >> tempStudent.id;
	cin.ignore();

	if (list.update(tempStudent) == true)
	{
		cout << "\nStudent found in list. Please enter the following information: \n" << endl;
		searchStudent.id = tempStudent.id;

		cout << "Student's name (Last, First Middle): ";
		cin.getline(searchStudent.name, 50);

		cout << "Student's city and state (City, State): ";
		cin.getline(searchStudent.cityState, 50);

		cout << "Student phone number: ";
		cin.getline(searchStudent.phone, 12);

		cout << "Student's gender: ";
		cin >> searchStudent.gender;

		cout << "Student's grade level (1 = freshman, 2 = sophomore, etc.): ";
		cin >> searchStudent.year;

		cout << "Student's current amount of credits: ";
		cin >> searchStudent.credits;

		cout << "Student's gpa: ";
		cin >> searchStudent.gpa;
		cin.ignore();

		cout << "Student's major: ";
		cin.getline(searchStudent.major, 6);

		list.remove(tempStudent);
		list.insert(searchStudent);

		cout << endl;
	}

	else
	{
		cout << "\nStudent not found in list.\n" << endl;
	}
}