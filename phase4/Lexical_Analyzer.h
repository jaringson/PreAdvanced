#pragma once
#include "Token.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "Lexical_Analyzer.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype> //isaplha isdigit etc
#include <locale>
class Lexical_Analyzer
{
private:
	vector <Token> token_list;
public:

	Lexical_Analyzer();
	~Lexical_Analyzer();
	void loadTokens(string location);
	void toString();
	Token* getnextToken();
	Token getTokenAt(int);
	int getlistSize();
};

