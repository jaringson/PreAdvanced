#pragma once
#include "StudentInterface.h"
#include <iostream>
#include <sstream>
class Student :
	public StudentInterface
{
private:
	unsigned long long int id;
	string str_id;
	string name;
	string str_gpa;
	double sum_gpa;
	double num_gpa;
	string address;
	string phone_number;
	int classes_taken;

public:
	Student(unsigned long long int id, string name, string address, string phone_number);
	~Student();
	unsigned long long int getID();
	string getName();
	string getGPA();
	void addGPA(double classGrade);
	string toString();
};

