#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer
{
	char fname[15];
	char lname[15];
	int mileage;
	int years;
	int arrivalNum;
	int priority;

	Customer();
	friend ostream& operator<< (ostream& out, const Customer& data);
	bool operator== (const Customer& rhs) const;
	bool operator== (int value) const;
	bool operator!= (const Customer& rhs) const;
	bool operator!= (int value) const;
	bool operator<= (const Customer& rhs) const;
	bool operator<= (int value) const;
	bool operator>= (const Customer& rhs) const;
	bool operator>= (int value) const;
	bool operator< (const Customer& rhs) const;
	bool operator< (int value) const;
	bool operator> (const Customer& rhs) const;
	bool operator> (int value) const;
	int operator% (int value) const;
	Customer& operator= (int value);
};

Customer::Customer()
{
	priority = 0;
}

ostream& operator<< (ostream& out, const Customer& data)
{
	out << data.priority << setw(10) << "|";
	out << setw(10) << data.fname << setw(5) << "|" << setw(12) << data.lname
		<< setw(5) << "|" << setw(8) << data.arrivalNum << setw(7) << "|" << setw(7)
		<< data.years << setw(7) << "|" << setw(10)
		<< data.mileage << endl;
	return out;
}

bool Customer::operator== (const Customer& rhs) const
{
	return (this->priority == rhs.priority);
}

bool Customer::operator== (int value) const
{
	return (this->priority == value);
}

bool Customer::operator!= (const Customer& rhs) const
{
	return (this->priority != rhs.priority);
}

bool Customer::operator!= (int value) const
{
	return (this->priority != value);
}

bool Customer::operator<= (const Customer& rhs) const
{
	return (this->priority <= rhs.priority);
}

bool Customer::operator<= (int value) const
{
	return (this->priority <= value);
}

bool Customer::operator>= (const Customer& rhs) const
{
	return (this->priority >= rhs.priority);
}

bool Customer::operator>= (int value) const
{
	return (this->priority >= value);
}

bool Customer::operator< (const Customer& rhs) const
{
	return (this->priority < rhs.priority);
}

bool Customer::operator< (int value) const
{
	return (this->priority < value);
}

bool Customer::operator> (const Customer& rhs) const
{
	return (this->priority > rhs.priority);
}

bool Customer::operator> (int value) const
{
	return (this->priority > value);
}

int Customer::operator% (int value) const
{
	return (this->priority % value);
}

Customer& Customer::operator= (int value)
{
	this->priority = value;
	return *this;
}

#endif CUSTOMER_H