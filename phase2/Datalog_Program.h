#pragma once
#include <set>
#include "Lexical_Analyzer.h"
#include "Token.h"
#include "Parameter.h"
#include "Predicate.h"
#include "Rule.h"

class Datalog_Program
{
private:
	Lexical_Analyzer token_list;
	bool test;
	int current_spot;
	vector<Parameter> parameter_vect;
	vector<Rule> rule_vect;
	/*vector<Predicate> predicate_vect;
	vector<Predicate> rule_predicate_vect;*/
	vector<Predicate> queries;
	vector<Predicate> facts;
	vector<Predicate> schemes;
	vector<Predicate> rules;
	int schemes_count;
	int queries_count;
	int facts_count;
	int rule_pred_count;
	string name_x;
	set<string> domain;
public:
	Datalog_Program(Lexical_Analyzer);
	~Datalog_Program();
	void parse();
	void match(string);

	void Scheme_List();
	void Scheme();
	void ID_List();
	void ID();

	void Facts_List();
	void Facts();
	void String_List();

	void Rule_List();
	void Rule_funct();
	void Head_Predicate();

	void Predicate_List();
	void Predicate_funct();
	void Parameter_List();
	void Parameter_funct();
	
	void Query_List();
	void Query();

	void toString();
};

