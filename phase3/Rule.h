#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Token.h"
#include "Predicate.h"
using namespace std;
class Rule
{
private:
	
public:
	Predicate predicate_head;
	vector<Predicate> body;
	Rule(vector<Predicate> body);
	~Rule();
	void ruletoString();
};

