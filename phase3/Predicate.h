#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Parameter.h"
using namespace std;
class Predicate
{
private:
	
public:
	string name;
	vector<Parameter> predicate_data;
	Predicate(string name, vector<Parameter>);
	Predicate();
	~Predicate();
};

