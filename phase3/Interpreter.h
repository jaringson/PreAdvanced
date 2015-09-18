#pragma once
#include "Datalog_Program.h"
#include "Database.h"
#include "Relation.h"
#include "Tuple.h"
class Interpreter
{
private:
	//vector<Database> database_vect;
	vector<Predicate> schemes;
	vector<Predicate> facts;
	vector<Predicate> queries;
	//vector<vector<string>> output;
	map <string, vector <string>>  output;
	Database data;
	vector<string> allID;
public:

	Interpreter(Datalog_Program data);
	~Interpreter();
	void Interpret();
	void Selection();
	void Projection();
	void Output();
	void print(int& i, int& j);
};

