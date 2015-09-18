#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Token.h"
using namespace std;
class Parameter
{
private:
	
public:
	string value;
	bool isString;
	//Parameter();
	Parameter(bool isString, string value);
	~Parameter();
};

