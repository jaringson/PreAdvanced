#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Token
{
private:
	//enum Toktype {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, SCHEMES, FACTS, RULES,
	//QUERIES, ID, STRING, COMMENT, WHITESPACE, UNDEFINED};
	string str;
	int line_num;
	string type;
public:
	Token(string type, string str, int line_num);
	~Token();
	string getType();
	string getStr();
	int getLine_num();
	void toString();
};

