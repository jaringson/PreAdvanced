#pragma once
#include "Datalog_Program.h"
#include "Database.h"
#include "Relation.h"
#include "Tuple.h"
#include "Rule.h"
#include "Graph.h"

class Interpreter
{
private:
	//vector<Database> database_vect;
	vector<Predicate> schemes;
	vector<Predicate> facts;
	vector<Predicate> queries;
	vector<Rule> rule_vect;
	//vector<vector<string>> output;
	map <string, vector <string>>  output;
	map <string, vector <string>>  ruleoutput;
	Database data;
	vector<string> allID;
	map<int, string> depRules;
	vector<set<int>> depPos;
public:

	Interpreter(Datalog_Program data);
	~Interpreter();
	void Interpret();
	void Selection();
	void Projection();
	void Output();
	void print(int& i, int& j);
	void evaluateRules();
	void join(Rule&, int&);
	void join2(Rule& rule, bool& big);
	vector<int> position(Predicate& result, Predicate& res2);
	int getCurrentSize();
	bool joinable(Tuple& one, Tuple& two, vector<int>& pos0);
	void ruleSelection(Predicate& pred, int& num);
	
};

