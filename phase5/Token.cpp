#include "Token.h"


Token::Token(string type, string str, int line_num)
{
	this->type = type;
	this->line_num = line_num;
	this->str = str;
}


Token::~Token()
{
}

string Token::getType()
{
	return type;
}
string Token::getStr()
{
	return str;
}
int Token::getLine_num()
{
	return line_num;
}
void Token::toString()
{
	cout << "(" << getType() << ",\"" << getStr() << "\"," << getLine_num() << ")" << endl;
}