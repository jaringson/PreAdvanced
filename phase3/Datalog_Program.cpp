#include "Datalog_Program.h"
#include <exception>

Datalog_Program::Datalog_Program(Lexical_Analyzer temp)
{
	token_list = temp;
	test = true;
	current_spot = 0;
	schemes_count=0;
	queries_count=0;
	facts_count=0;
	rule_pred_count = 0;
	name_x = "";
}


Datalog_Program::~Datalog_Program()
{
}

void Datalog_Program::ID_List()
{
	/*cout << "here 5" << endl;
	system("pause");*/
	match("ID");
	Parameter temp_para = Parameter(false, token_list.getTokenAt(current_spot-1).getStr());
	parameter_vect.push_back(temp_para);
	if (token_list.getTokenAt(current_spot).getType() == "COMMA")
	{
		match("COMMA");
		ID_List();
	}
}


void Datalog_Program::Scheme()
{
	match("ID");
	string name = token_list.getTokenAt(current_spot - 1).getStr();
	match("LEFT_PAREN");
	ID_List();
	match("RIGHT_PAREN");
	Predicate temp_pred = Predicate(name, parameter_vect);
	schemes.push_back(temp_pred);
	schemes_count++;
	parameter_vect.clear();
}
void Datalog_Program::Scheme_List()
{
	/*cout << "here 2" << endl;
	system("pause");*/
	Scheme();
	if (token_list.getTokenAt(current_spot).getType() != "FACTS")
	{
		Scheme_List();
	}
}
void Datalog_Program::Facts_List()
{
	if (token_list.getTokenAt(current_spot).getType() == "ID")
	{
		Facts();
		Facts_List();
	}
}
void Datalog_Program::Facts()
{
	match("ID");
	string name = token_list.getTokenAt(current_spot - 1).getStr();
	match("LEFT_PAREN");
	String_List();
	match("RIGHT_PAREN");
	match("PERIOD");
	Predicate temp_pred = Predicate(name, parameter_vect);
	facts.push_back(temp_pred);
	facts_count++;
	parameter_vect.clear();
}
void Datalog_Program::String_List()
{
	match("STRING");
	/*bool add = true;
	for (int i = 0; i < domain.size(); i++)
	{
		if (token_list.getTokenAt(current_spot - 1).getStr() == domain[i])
			add = false;
	}
	if (add)*/
	domain.insert(token_list.getTokenAt(current_spot - 1).getStr());
	Parameter temp_para = Parameter(true, token_list.getTokenAt(current_spot - 1).getStr());
	parameter_vect.push_back(temp_para);
	if (token_list.getTokenAt(current_spot).getType() != "RIGHT_PAREN")
	{
		match("COMMA");
		String_List();
	}
}


void Datalog_Program::Rule_List()
{
	if (token_list.getTokenAt(current_spot).getType() != "QUERIES")
	{
		Rule_funct();
		Rule_List();
	}
}
void Datalog_Program::Rule_funct()
{
	Head_Predicate();
	match("COLON_DASH");
	Predicate_List();
	match("PERIOD");
	Rule temp_rule = Rule(rules);
	rule_vect.push_back(temp_rule);
	rules.clear();
}
void Datalog_Program::Head_Predicate()
{
	match("ID");
	string name = token_list.getTokenAt(current_spot - 1).getStr();
	match("LEFT_PAREN");
	ID_List();
	match("RIGHT_PAREN");
	Predicate temp_pred = Predicate(name, parameter_vect);
	/*rule_predicate_vect.push_back(temp_pred);
	predicate_vect.push_back(temp_pred);*/
	rules.push_back(temp_pred);
	parameter_vect.clear();
}
void Datalog_Program::Predicate_List()
{
	Predicate_funct();
	Predicate temp_pred = Predicate(name_x, parameter_vect);
	rules.push_back(temp_pred);
	parameter_vect.clear(); 
	if (token_list.getTokenAt(current_spot).getType() == "COMMA")
	{
		match("COMMA");
		Predicate_List();
	}
}
void Datalog_Program::Predicate_funct()
{
	if (current_spot < token_list.getlistSize())
	{
		match("ID");
		name_x = token_list.getTokenAt(current_spot - 1).getStr();
		//string name = token_list.getTokenAt(current_spot - 1).getStr();
		match("LEFT_PAREN");
		Parameter_List();
		match("RIGHT_PAREN");
		/*Predicate temp_pred = Predicate(name, parameter_vect);
		predicate_vect.push_back(temp_pred);
		rule_predicate_vect.push_back(temp_pred);
		parameter_vect.clear();*/
	}
}
void Datalog_Program::Parameter_List()
{
	Parameter_funct();
	if (token_list.getTokenAt(current_spot).getType() == "COMMA")
	{
		match("COMMA");
		Parameter_List();
	}
}
void Datalog_Program::Parameter_funct()
{
	if (token_list.getTokenAt(current_spot).getType() == "STRING")
	{
		match("STRING");
		Parameter temp_para = Parameter(true, token_list.getTokenAt(current_spot - 1).getStr());
		parameter_vect.push_back(temp_para);
	}
	else
	{
		match("ID");
		Parameter temp_para = Parameter(false, token_list.getTokenAt(current_spot - 1).getStr());
		parameter_vect.push_back(temp_para);
	}
}

void Datalog_Program::Query_List()
{
	Query();
	if (current_spot < token_list.getlistSize() && token_list.getTokenAt(current_spot).getType() != "EOF")
	{
		Query_List();
	}
}
void Datalog_Program::Query()
{
	Predicate_funct();
	match("Q_MARK");
	queries_count++;
	Predicate temp_pred = Predicate(name_x, parameter_vect);
	queries.push_back(temp_pred);
	parameter_vect.clear();
	name_x = "";
}
void Datalog_Program::match(string type)
{
	if (current_spot < token_list.getlistSize() && token_list.getTokenAt(current_spot).getType() == type)
	{
		current_spot++;
	}
	else throw token_list.getTokenAt(current_spot).getStr();
	
}
void Datalog_Program::parse()
{
	try
	{
		match("SCHEMES");
		match("COLON");
		Scheme_List();
		match("FACTS");
		match("COLON");
		Facts_List();
		match("RULES");
		match("COLON");
		Rule_List();
		match("QUERIES");
		match("COLON");
		Query_List(); 
		match("EOF");
	}
	catch (string e)
	{
		cout << "Failure! " <<  endl << "  ";
		token_list.getTokenAt(current_spot).toString();
		test = false;
	}
}

void Datalog_Program::toString()
{
	if (test)
	{
		cout << "Success!" << endl;
		cout << "Schemes(" << schemes_count << "):" << endl;
		for (int i = 0; i < schemes_count; i++)
		{
			cout << "  " << schemes[i].name << "(";
			for (int j = 0; j < schemes[i].predicate_data.size(); j++)
			{
				cout <<  schemes[i].predicate_data[j].value;
				if (j != schemes[i].predicate_data.size() - 1)
				{
					cout << ",";
				}
			}
				cout << ")" << endl;
		}
		cout << "Facts(" << facts_count << "):" << endl;
		for (int i = 0; i < facts_count; i++)
		{
			cout << "  " << facts[i].name << "(";
			for (int j = 0; j < facts[i].predicate_data.size(); j++)
			{
				cout <<  facts[i].predicate_data[j].value;
				if (j != facts[i].predicate_data.size() - 1)
					cout << ",";
			}
			cout << ")." << endl;
		}
		
		int total_rule = 0;
		cout << "Rules(" << rule_vect.size() << "):" << endl;
		if (rule_vect.size() != 0)
		{
			
			for (int j = 0; j < rule_vect.size(); j++)
			{
				//total_rule = total_rule + rule_vect[j].body.size();
				rule_vect[j].ruletoString();
			}
		}
		
		cout << "Queries(" << queries_count << "):" << endl;
		for (int i = 0; i < queries_count; i++)
		{
			cout << "  " << queries[i].name << "(";
			for (int j = 0; j < queries[i].predicate_data.size(); j++)
			{
				cout << queries[i].predicate_data[j].value;
				if (j != queries[i].predicate_data.size() - 1)
					cout << ",";
			}
			cout << ")?" << endl;
		}
		cout << "Domain(" << domain.size() << "):" << endl;
		for (set<string>::iterator it = domain.begin(); it != domain.end(); ++it)
			cout << "  " << *it <<  endl;
		/*for (int i = 0; i < domain.size(); i++)
		{
			cout << "  " << domain[i] << endl;
		}*/
	}

}

vector<Predicate> Datalog_Program::getSchemes()
{
	return schemes;
}
vector<Predicate> Datalog_Program::getFacts()
{
	return facts;
}
vector<Predicate> Datalog_Program::getQueries()
{
	return queries;
}