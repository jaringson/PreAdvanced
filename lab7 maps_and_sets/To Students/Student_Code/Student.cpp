#include "Student.h"
#include <iomanip> 


Student::Student(unsigned long long int id, string name, string address, string phone_number)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone_number = phone_number;
	str_gpa = "0.00";
	num_gpa = 0;
	sum_gpa = 0;
	classes_taken = 0;
}


Student::~Student()
{

}

unsigned long long int Student::getID()
{
	return id;
}

string Student::getName()
{
	return name;
}

string Student::getGPA()
{
	return str_gpa;
}

void Student::addGPA(double classGrade)
{
	classes_taken++;
	sum_gpa = sum_gpa + classGrade;
	num_gpa = sum_gpa / classes_taken;
	ostringstream convert;
	convert << num_gpa;
	str_gpa = convert.str();
}
string Student::toString()
{
	
	ostringstream output;
	output << id << endl;
	output << Student::getName() << endl;
	output << address << endl;
	output << phone_number << endl;
	output << setprecision(2) << fixed << num_gpa;
	return output.str();
}
