/*
Jaron Ellingson
CS 235 Winter 2015 Midterm
*/
#include <iostream>
#include "CircularDLL.h"
#include "Factory.h"
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	CircularDLL my_list;
	bool test = true;
	string input;
	while (test)
	{
		cout << "Please Choose One of the Following Options: " 
			"\n Import a File = One " 
			"\n Display the Roster with Indices = Two" 
			"\n Prepend Names to the Roster = Three"
			"\n Append Names to the Roster = Four"
			"\n Remoce a Name by Index = Five"
			"\n Randomly Shuffle the Roster= Six"
			"\n Calculate the Safe Index = Seven"
			"\n Dispand the Band = Eight"
			"\n Quit the Program = Quit" << endl;

		cin >> input;

		if (input == "Quit" || input == "quit" || input == "q")
		{
			cout << "Shalom" << endl;
			system("pause");
			test = false;
		}
		else if (input == "One" || input == "one" || input == "1")
		{
			bool result;
			string location;
			ifstream in_file; //Creating a stream to read in the file

			cout << "Where would you like to read the data from?";

			cin >> location;

			in_file.open(location);

			if (in_file.is_open()){


				while (!in_file.eof()) { // if there's more stuff, read it in.

					string name;
					// grab a whole line
					getline(in_file, name);
					result = my_list.insertTail(name);
					if (result)
					{
						cout << "Added Player: " << name << endl;
					}
				}
			}
			else
			{
				cout << "Invalid File Location: " << location << endl;
			}
			cout << endl;
			test = true;
			
		}
		else if (input == "Two" || input == "two" || input == "2")
		{
			bool proceed = true;
		
			if (my_list.size() == 0)
			{
				cout << "No People Currently in the List" << endl;
				proceed = false;
			}
			
			if (proceed)
			{
				for (int i = 0; i < my_list.size(); i++)
				{
					cout << i << "-" << my_list.atFromHead(i) << endl;
				}
			}
		}
		else if (input == "Three" || input == "three" || input == "3")
		{
			cout << "Name: ";
			string name;
			cin >> name;
			bool result;
			result = my_list.insertHead(name);
			if (result)
			{
				cout << name << " was added" << endl;
			}
			else
			{
				cout << name << " was not Added" << endl;
				
			}
		}
		else if (input == "Four" || input == "four" || input == "4")
		{
			cout << "Name: ";
			string name;
			cin >> name;
			bool result;
			result = my_list.insertTail(name);
			if (result)
			{
				cout << name << " was added" << endl;
			}
			else
			{
				cout << name << " was not Added" << endl;

			}

		}
		else if (input == "Five" || input == "five" || input == "5")
		{
			cout << "Enter Index: ";
			int index;
			cin >> index;
			string name_removed = my_list.atFromHead(index);
			if (my_list.removeAt(index))
			{
				cout << name_removed << " was removed" << endl;
			}
			else
			{
				cout << "Out of Bounds Index: " << index << endl;
			}

			cin.ignore();
			cin.clear();
		}
		else if (input == "Six" || input == "six" || input == "6")
		{
			bool proceed = true;
			bool proceed_two = false;
			CircularDLL temp_list;
			if (my_list.size() == 0)
			{
				proceed = false;
				proceed_two = true;
			}
			vector<int> number_holding_vector(my_list.size());
			for (int i = 0; i < my_list.size(); i++)
			{
				number_holding_vector[i] = -1; //Using -1 becuase the random number generator will never get to -1
			}
			for (int i = 0; i < my_list.size(); i++)
			{
				number_holding_vector[i] = rand() % my_list.size();
				if (i > 0)
				{
					for (int j = 0; j < my_list.size(); j++)
					{
						if (i > 0 && j != i && number_holding_vector[i] == number_holding_vector[j])
						{
							i--;
						}
					}
				}
			}
			for (int i = 0; i < my_list.size(); i++)
			{
				bool variable = temp_list.insertTail(my_list.atFromHead(number_holding_vector[i]));
			}
			my_list.clear();
			for (int i = 0; i < temp_list.size(); i++)
			{
				//cout << temp_list.atFromHead(i) << endl;
				bool variable = my_list.insertTail(temp_list.atFromHead(i));
			}
			temp_list.clear();

		}
		else if (input == "Seven" || input == "seven" || input == "7")
		{
			bool proceed = true;
			bool proceed_two = false;
			vector<int> temp_list;
			/*	if (my_list.size() == 0)
			{
				proceed = false;
				proceed_two = true;
				}*/
		
			int size;
			//int total_size;
			int count;
			int delete_index = 0;
		

			while (!proceed_two)
			{
			  cout << "Enter Count: ";
			  cin >> count;
			  cout << "Enter Size: ";
			  cin >>size;
				
				if (count >= 1 && count <= size)
				{
					proceed_two = true;
				}
				else
				{
					cout << " Out of Bounds Numbers" << endl;
					proceed_two = false;
				}
			}
			for (int i = 0; i < size; i++)
			{
				temp_list.push_back(i);
			}
			int temp_size = size;
			int counter = 0;
			if (proceed)
			{
				for (int i = 0; i < size - 1; i++)
				{
					delete_index = delete_index + count;
					while (delete_index > temp_size)
					{
						delete_index = delete_index - temp_size;
					}
					int erase = delete_index - 1;
					temp_list.erase(temp_list.begin()+erase);
					temp_size--;
					delete_index--;
				}
				int safety_index= temp_list[0];
				/*	for (int i = 0; i < size; i++)
				{
					if (my_list.atFromHead(i) == temp_list.atFromHead(0))
					{
						safety_index = i;
					}
					}*/
				cout << "The Size of the Group is: " << size << endl;
				cout << "The Count was: " << count << endl;
				cout << "The Safety Index is: " << safety_index << endl;
			}
			temp_list.clear();
			
		}
		else if (input == "Eight" || input == "eight" || input == "8")
		{
			bool proceed = true;
			bool proceed_two = false;
			if (my_list.size() == 0)
			{
			  cout << "You have no People in Your List" << endl;
				proceed = false;
				proceed_two = true;
			}
	
			int size = my_list.size();
			int total_size;
			int count;
			int delete_index = 0;

			while (!proceed_two)
			{
				cout << "Enter Count: ";
				cin >> count;

				if (count >= 1 && count <= my_list.size())
				{
					proceed_two = true;
				}
				else
				{
					cout << " Out of Bounds Numbers" << endl;
					proceed_two = false;
				}
			}
			int temp_size = size;
			int counter = 0;
			if (proceed)
			{
				for (int i = 0; i < size - 1; i++)
				{
					delete_index = delete_index + count;
					while (delete_index > temp_size)
					{
						delete_index = delete_index - temp_size;
					}
					cout << "Removed: " << my_list.atFromHead(delete_index - 1) << endl;
					bool another_variable = my_list.removeAt(delete_index - 1);
					temp_size--;
					delete_index--;
				}
				cout << "The Survivor is: " << my_list.atFromHead(0) << endl;
			}
			my_list.clear();
		}
		else
		{
			cout << "Invalid Response: " << input << endl;
		}
		cin.ignore();
		cin.clear();
	}

	
	return 1;
};
