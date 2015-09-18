#include "Rule.h"


Rule::Rule(vector<Predicate> y)
{
	//predicate_head = Predicate(str, vec);
	body = y;
}


Rule::~Rule()
{
}

void Rule::ruletoString()
{
	cout << "  "<<body[0].name << "(";
	for (int j = 0; j < body[0].predicate_data.size(); j++)
	{
		cout << body[0].predicate_data[j].value;
		if (j != body[0].predicate_data.size() - 1)
			cout << ",";
	}
	cout << ") :- ";
	for (int i = 1; i < body.size(); i++)
	{
		cout << body[i].name << "(";
		for (int j = 0; j < body[i].predicate_data.size(); j++)
		{
			cout << body[i].predicate_data[j].value;
			if (j != body[i].predicate_data.size() - 1)
				cout << ",";
		}
		
		if (i != body.size()-1)
			cout << "),";
	}
	cout << ")." << endl;
}