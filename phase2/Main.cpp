#include <iostream>
#include <string>
#include <iomanip>
#include "Token.h"
#include "Lexical_Analyzer.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype> //isaplha isdigit etc
#include <locale>
#include "Datalog_Program.h"

using namespace std;
/*
// for pass off
int main(char* argv[])
{
ifstream in_file(argv[i]);
}
*/
//int argc, char* argv[]

int main(int argc, char* argv[])
{
	//int input;
	//while (cin >> input)
	//{
	/*string location;
	cout << "Where? ";
	cin >> location;*/
	string location = argv[1];
	Lexical_Analyzer list;
	//stringstream ss = in_file;
	list.loadTokens(location);
	//list.toString();
	Datalog_Program step_two = Datalog_Program(list);
	step_two.parse();
	step_two.toString();
	//}
	
	//system("pause");
	return 0;
}
