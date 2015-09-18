#pragma once
#include "ExpressionManagerInterface.h"
#include<stack>
#include<string>
#include <iostream>

class ExpressionManager :
	public ExpressionManagerInterface
{
public:
	ExpressionManager();
	~ExpressionManager();
	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);

private:
	
	
};

