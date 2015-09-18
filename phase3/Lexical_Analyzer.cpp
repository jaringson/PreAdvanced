#include "Lexical_Analyzer.h"


Lexical_Analyzer::Lexical_Analyzer()
{
}


Lexical_Analyzer::~Lexical_Analyzer()
{
}

void Lexical_Analyzer::loadTokens(string location)
{

	int line_counter = 1;
	char character;
	/*string location;
	cout << "Where? ";
	cin >> location;*/
	ifstream in_file;//Creating a stream to read in the file
	in_file.open(location);
	if (in_file.is_open())
	{
		while (in_file.get(character))
		{
			if (character == '\n')
			{
				//cout << "hey 1" << endl;
				line_counter++; //Kepps track of what line we are on
			}
			else if (isspace(character))
			{
				character = ' ';
				//cout << "here" << character << "!" << endl;
			}


			else if (character == ',')
			{
				//cout << "hey 2" << endl;
				Token temp_token = Token("COMMA", ",", line_counter);
				token_list.push_back(temp_token);
			}
			else if (character == '.')
			{
				//cout << "hey 3" << endl;
				Token temp_token = Token("PERIOD", ".", line_counter);
				token_list.push_back(temp_token);
			}
			else if (character == '?')
			{
				//cout << "hey 4" << endl;
				Token temp_token = Token("Q_MARK", "?", line_counter);
				token_list.push_back(temp_token);
			}
			else if (character == '(')
			{
				Token temp_token = Token("LEFT_PAREN", "(", line_counter);
				token_list.push_back(temp_token);
			}
			else if (character == ')')
			{
				Token temp_token = Token("RIGHT_PAREN", ")", line_counter);
				token_list.push_back(temp_token);
			}
			else if (character == ':')
			{
				char char_next = in_file.peek();
				if (char_next == '-')
				{
					Token temp_token = Token("COLON_DASH", ":-", line_counter);
					token_list.push_back(temp_token);
					in_file.get(character);
				}
				else
				{
					Token temp_token = Token("COLON", ":", line_counter);
					token_list.push_back(temp_token);
				}
			}

			else if (isalpha(character)) //ID Identifier
			{
				string id = "";
				bool proceed = true;
				while (isalpha(character) || isdigit(character))
				{
					//id.append(character);

					char char_next = in_file.peek();
					if (character == EOF)
					{
						break;
					}
					if (character == '\n')
					{
						break;
					}
				
					id = id + character;
					if (isalpha(char_next) || isdigit(char_next))
					{
						in_file.get(character);
					}
					else
					{
						break;
					}

				}

				if (id == "Schemes")
				{
					Token temp_token = Token("SCHEMES", "Schemes", line_counter);
					token_list.push_back(temp_token);
					proceed = false;
				}
				else if (id == "Facts")
				{
					Token temp_token = Token("FACTS", "Facts", line_counter);
					token_list.push_back(temp_token);
					proceed = false;
				}
				else if (id == "Rules")
				{
					Token temp_token = Token("RULES", "Rules", line_counter);
					token_list.push_back(temp_token);
					proceed = false;
				}
				else if (id == "Queries")
				{
					Token temp_token = Token("QUERIES", "Queries", line_counter);
					token_list.push_back(temp_token);
					proceed = false;
				}
				if (proceed)
				{
					Token temp_token = Token("ID", id, line_counter);
					token_list.push_back(temp_token);
				}


			}
			else if (character == '\'')
			{
				int saved_line = line_counter;
				string str = "";
				str = str + character;
				char char_next;
				while (in_file.get(character))
				{

					char_next = in_file.peek();
					if (char_next == EOF)
					{
						//str = str + "\n";
						line_counter++;
						Token temp_token = Token("UNDEFINED", str, saved_line);
						token_list.push_back(temp_token);
						break;
					}
					if (character == '\n')
					{
						line_counter++;
					}
					if (character == '\'')
					{
						if (char_next != '\'')
						{
							str = str + character;
							Token temp_token = Token("STRING", str, saved_line);
							token_list.push_back(temp_token);
							break;
						}
						str = str + character;
						in_file.get(character);
					}
					str = str + character;
				}
			}

			else if (character == '#')
			{
				int saved_line = line_counter;
				string comment = "";
				comment = comment + character;
				char char_next = in_file.peek();
				if (char_next == '|')
				{
					in_file.get(character);
					comment = comment + character;
					while (in_file.get(character))
					{
						char_next = in_file.peek();
						if (char_next == EOF)
						{
							//comment = comment + "\n";
							line_counter++;
							Token temp_token = Token("UNDEFINED", comment, saved_line);
							//token_list.push_back(temp_token);
							break;
						}
						if (character == '\n')
						{
							line_counter++;
						}
						if (character == '|' && char_next == '#')
						{
							comment = comment + character;
							in_file.get(character);
							comment = comment + character;
							Token temp_token = Token("COMMENT", comment, saved_line);
							//token_list.push_back(temp_token);
							break;
						}
						comment = comment + character;
					}
				}
				else
				{
					while (in_file.get(character))
					{

						if (character == '\n')
						{
							Token temp_token = Token("COMMENT", comment, line_counter);
							//token_list.push_back(temp_token);
							line_counter++;
							break;
						}
						comment = comment + character;
					}
				}

			}
			else
			{
				string temp = "";
				temp = temp + character;
				Token temp_token = Token("UNDEFINED", temp, line_counter);
				token_list.push_back(temp_token);
			}
		}//End of While loop
		Token temp_token = Token("EOF", "", line_counter); //Need this for the end of the file
		token_list.push_back(temp_token);
	}

}

void Lexical_Analyzer::toString()
{
	for (int i = 0; i < token_list.size(); i++)
	{
		cout << "(" << token_list[i].getType() << ",\"" << token_list[i].getStr() << "\"," << token_list[i].getLine_num() << ")" << endl;
	}
	cout << "Total Tokens = " << token_list.size() << endl;
}


Token* Lexical_Analyzer::getnextToken()
{
	Token* cur_token = &token_list[0];
	token_list.erase(token_list.begin());
	return cur_token;
}

Token Lexical_Analyzer::getTokenAt(int spot)
{
	return token_list[spot];
}

int Lexical_Analyzer::getlistSize()
{
	return token_list.size();
}