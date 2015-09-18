#pragma once
#include <iostream>
#include <string>
#include "Tuple.h"
#include "Predicate.h"
#include <set>
using namespace std;
class Relation
{
public:
	Relation(Predicate);
	Relation();
	~Relation();
	string name;
	Predicate scheme;
	set <Tuple> set_relation;
	Parameter value = Parameter(0, "");
};

