#include "ExpressionManager.h"
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <math.h>


ExpressionManager::ExpressionManager()
{
}


ExpressionManager::~ExpressionManager()
{
}

//--------------------------------------------------------
const string OPEN = "([{";
const string CLOSE = ")]}";
bool is_open(char ch){
	return OPEN.find(ch) != string::npos;
}

bool is_close(char ch){
	return CLOSE.find(ch) != string::npos;
}

bool ExpressionManager::isBalanced(string expression)
{
	
	stack<char> s;
	bool balanced = true;
	string::const_iterator iter = expression.begin();
	while (balanced && (iter != expression.end())){
		char next_ch = *iter;
		if (is_open(next_ch)){
			s.push(next_ch);
		}
		else if (is_close(next_ch)){
			if (s.empty()){
				balanced = false;
			}
			else {
				char top_ch = s.top();
				s.pop(); 
				balanced =
					OPEN.find(top_ch) == CLOSE.find(next_ch);
			}
		}
		iter++;
	}
	return balanced && s.empty();
}


//--------------------------------------------------------
//Post Fix to In Fix

const string OPERATORS = "+-*/%()";
bool is_operator(char ch){
	return OPERATORS.find(ch) != string::npos;
}

string print_op(char op, stack<string>& operand_stack, bool& test_valid){
	if (operand_stack.empty()){
		test_valid = false;
		return "";
	}
	string rhs = operand_stack.top();
	operand_stack.pop();
	if (operand_stack.empty()){
		test_valid = false;
		return "";
	}
	string lhs = operand_stack.top();
	operand_stack.pop();
	string result = "";
	
	switch (op){
	case '+': result = "( " + lhs + " + " + rhs + " )" ;
		break;
	case '-': result = "( " + lhs + " - " + rhs + " )";
		break;
	case '*': result = "( " + lhs + " * " + rhs + " )";
		break;
	case '/': result = "( " + lhs + " / " + rhs + " )";
		break;
	case '%': result = "( " + lhs + " % " + rhs + " )";
		break;
	case '.': test_valid = false;
	  result = " ";
	  break;
	}
	
	return result;
}
string ExpressionManager::postfixToInfix(string postfixExpression)
{
	stack <string> operand_stack;
	bool test_valid = true;
	string infix = "";
	while (!operand_stack.empty()){
		operand_stack.pop();
	}
	istringstream tokens(postfixExpression);
	char next_char;
	while (tokens >> next_char){
	 
		if (isdigit(next_char)){
	       
		    tokens.putback(next_char);
		    string value;
		    tokens >> value;
		    double double_check = stod(value);
		    if(fmod(double_check, 1) == 0){
		    operand_stack.push(value);
		   
		  }
		  else{
		    return "invalid";
		  }
		
		

		}
		else if(next_char == '\0'){
		  return "invalid";
		}
		else if (is_operator(next_char)){
			string result = print_op(next_char, operand_stack, test_valid);
			if (!test_valid){
				return "invalid";
			}
			infix += result;
			infix += " ";
			operand_stack.push(result);
		}
		
		else{
			return "invalid";
		}
	}
	if (!operand_stack.empty()){
		string string_answer = operand_stack.top();
		operand_stack.pop();
		if (operand_stack.empty()){
			
			return string_answer;
		}
		else {
			return "invalid";
		}
	}
	else {
		return "invalid";
	}
	
	
}


//--------------------------------------------------------
//Infix to PostFix

const int PRECEDENCE[] = { 1, 1, 2, 2, 2, -1, -2};

int precedence(char op){
	return PRECEDENCE[OPERATORS.find(op)];
}

void process_operator(char op, stack<char>& operator_stack, string& postfix, bool& test_valid){
	if (operator_stack.empty() || (op == '(')){
		if (op == ')'){
			test_valid = false;
			return;
		}
		operator_stack.push(op);
	}
	else{
		if (precedence(op) > precedence(operator_stack.top())){
			operator_stack.push(op);
		}
		else{
			//Pop all stacked operators with equal
			//or higher precedence than op
			while (!operator_stack.empty() && (operator_stack.top() != '(') && (precedence(op) <= precedence(operator_stack.top()))){
				postfix += operator_stack.top();
				postfix += " ";
				operator_stack.pop();
			}
			//assert: Operator stack is empty or current
			//			operator precendence > top of stack operator
			//			precedence;
			if (op == ')'){
				if (!operator_stack.empty() && (operator_stack.top() == '(')){
					operator_stack.pop();
				}
				else{
					test_valid = false;
					return;
				}
			}
			else{
				operator_stack.push(op);
			}
			
		}
	}
}

string ExpressionManager::infixToPostfix(string infixExpression)
{
	bool test = ExpressionManager::isBalanced(infixExpression);
	if (!test){
		return "invalid";
	}

	istringstream delete_stream(infixExpression);
	string delete_para;
	string expression;
	while (delete_stream >> delete_para){
	  if(delete_para != ")" && delete_para != "("){
	    expression += delete_para;
	    expression += " ";
	  }
	}
	istringstream check_operators(expression);
	string temp_string;
	while(check_operators >> temp_string){
	  if(is_operator(temp_string[0])){
	    string compare = temp_string;
	    check_operators >> temp_string;
	    if(is_operator(temp_string[0])){
	      return "invalid";
	    }
	    else{
	      check_operators.putback(temp_string[0]);
	    }
	  }
	}

	bool test_valid = true;
	stack<char> operator_stack;
	string postfix = "";
	while (!operator_stack.empty()){
		operator_stack.pop();
	}
	istringstream infix_tokens(infixExpression);
	string next_token;
	while (infix_tokens >> next_token){
		if (isdigit(next_token[0])){
		  double check_num = stod(next_token);
		  if(fmod(check_num, 1) == 0){
		    postfix += next_token;
		    postfix += " ";
		  }
		  else{
		    return "invalid";
		  }
		
		}
		else if (is_operator(next_token[0])){
		  
			process_operator(next_token[0], operator_stack, postfix, test_valid);
			if (test_valid == false){
				return "invalid";
			}
		}
		else {
			return "invalid";
		}
	}
	//Pop any remaining operators and append them to postfix
	while (!operator_stack.empty()){
		char op = operator_stack.top();
		operator_stack.pop();
		if (op == '('){
			return "invalid";
		}
		postfix += op;
		if(!operator_stack.empty()){
		postfix += " ";

		}
		
	}
	return postfix;
}


//--------------------------------------------------------
//PostFix Evalutate


int eval_op(char op, stack<int>& operand_stack, bool& test_valid){
	if (operand_stack.empty()){
		test_valid = false;
		return 0;
	}
	int rhs = operand_stack.top();
	
	operand_stack.pop();
	if (operand_stack.empty()){
		test_valid = false;
		return 0;
	}
	int lhs = operand_stack.top();
	operand_stack.pop();
	int result = 0;
	switch (op){
	case '+': result = lhs + rhs;
		break;
	case '-': result = lhs - rhs;
		break;
	case '*': result = lhs * rhs;
		break;
	case '/':
if (rhs == 0){
		test_valid = false;
		break;
	}
 result = lhs / rhs;
		break;
	case '%': result = lhs % rhs;
		break;
	}
	return result;
}

string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	stack <int> operand_stack;
	bool test_valid = true;
	//Empty out the stack
	while (!operand_stack.empty()){
		operand_stack.pop();
	}
	istringstream tokens(postfixExpression);
	char next_char;
	while (tokens >> next_char){
		if (isdigit(next_char)){
			tokens.putback(next_char);
			int value;
			tokens >> value;
			operand_stack.push(value);
		}
		else if (is_operator(next_char)){
			int result = eval_op(next_char, operand_stack, test_valid);
			operand_stack.push(result);
			if (test_valid == false){
				return "invalid";
			}
		}
		else{
			return "invalid";
		}
	}
	if (!operand_stack.empty()){
		int answer = operand_stack.top();
		operand_stack.pop();
		if (operand_stack.empty()){
			string string_answer;
			ostringstream convert;
			convert << answer;
			string_answer = convert.str();
			return string_answer;
		}
		else {
			return "invalid";
		}
	}
	else {
		return "invalid";
	}
}
