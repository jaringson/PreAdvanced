#pragma once
#include "Relation.h"
#include <map>
class Database
{
public:
	Database();
	~Database();
	void insertRelation();
	map<string, Relation> database;
};

