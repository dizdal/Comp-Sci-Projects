#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
	int id;
	char name[50];
	char cityState[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();
	bool operator== (const Student& rhs) const;
	bool operator== (int value) const;
	bool operator!= (const Student& rhs) const;
	bool operator!= (int value) const;
	bool operator<= (const Student& rhs) const;
	bool operator<= (int value) const;
	bool operator>= (const Student& rhs) const;
	bool operator>= (int value) const;
	bool operator< (const Student& rhs) const;
	bool operator< (int value) const;
	bool operator> (const Student& rhs) const;
	bool operator> (int value) const;
	int operator% (int value) const;
	Student& operator= (int value);
	void display1Student(Student list);
};

Student::Student()
{
	id = 0;
}

bool Student::operator== (const Student& rhs) const
{
	return (this->id == rhs.id);
}

bool Student::operator== (int value) const
{
	return (this->id == value);
}

bool Student::operator!= (const Student& rhs) const
{
	return (this->id != rhs.id);
}

bool Student::operator!= (int value) const
{
	return (this->id != value);
}

bool Student::operator<= (const Student& rhs) const
{
	return (this->id <= rhs.id);
}

bool Student::operator<= (int value) const
{
	return (this->id <= value);
}

bool Student::operator>= (const Student& rhs) const
{
	return (this->id >= rhs.id);
}

bool Student::operator>= (int value) const
{
	return (this->id >= value);
}

bool Student::operator< (const Student& rhs) const
{
	return (this->id < rhs.id);
}

bool Student::operator< (int value) const
{
	return (this->id < value);
}

bool Student::operator> (const Student& rhs) const
{
	return (this->id > rhs.id);
}

bool Student::operator> (int value) const
{
	return (this->id > value);
}

int Student::operator% (int value) const
{
	return (this->id % value);
}

Student& Student::operator= (int value)
{
	this->id = value;
	return *this;
}

void display1Student(Student list)
{
	cout << setw(7) << list.id
		<< setw(30) << list.name 
		<< setw(10) << list.gpa 
		<< setw(10) << list.major << endl;
}

#endif STUDENT_H