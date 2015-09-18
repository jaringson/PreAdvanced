/*

Test Cases
#1
6
Invalid Input Try Again

1
Chick-fil-a, Olive Garden, Pizza Hut, Panda Express, Jimmy Johns, Cook Out, Golden Corral, Smithfields

5
(Match Happens)
(Program Quits)

#2
Q
(Program Quits)

#3

2
(Adds Resturant: Some thing)
Some thing

3
Some thing Else
(Some thing  is still in there)

4
(shuffles)
4 x 10
(all shuffles to different spots)

5
(error happens)

3
Some thing

5
(tournament happens and program shuts off)



*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string out_source(vector<string> vec)
{
	string out;

	for (int i = 0; i < vec.size(); i++)
	{
		if (i < vec.size() - 1)
		{
			out = out + vec[i] + ", ";
		}
		else
		{
			out = out + vec[i];
		}
	}
	return out;
}

double find(string finding_resturant, vector<string> resturants)
{
	for (int i = 0; i < resturants.size(); i++)
	{
		if (resturants[i] == finding_resturant)
		{
			return i;
		}
	}
	return -1;
}

void add(vector<string>& resturants)
{
	cout << "Please enter the Resturant You Want to Add: ";
	string finding_resturant;
	getline(cin, finding_resturant);
	double number = 0;
	number = find(finding_resturant, resturants);
	if (number == -1)
	{
		resturants.push_back(finding_resturant);
		cout << "Resturant was Added To the Vector \n\n";
	}
	if (number > -1)
	{
		cout << "That Resturant is already in Index: " << number + 1 << endl << endl;
	}
	
}

void remove(vector<string>& resturants)
{
	cout << "Please enter the Resturant You Want to Remove: ";
	string finding_resturant;
	getline(cin, finding_resturant);
	double number = 0;
	number = find(finding_resturant, resturants);
	if (number > -1)
	{

		for (int i = number; i < resturants.size() - 1; i++)
		{
			resturants[i] = resturants[i + 1];
		}
		resturants.pop_back();
	}
	cout << "Finished! \n" << out_source(resturants) << "\n\n";
}

void shuffle(vector<string>& resturants)
{
	random_shuffle(resturants.begin(), resturants.end());
	cout << "Ok it is now done shuffling: \n" << out_source(resturants) << "\n";
}

bool tournament(vector <string> resturants, double rounds, int counter)
{
	int round_int = rounds;
	counter++;

	if (resturants.size() == 1)
	{
		cout << "The winner is: " << resturants[0] << "\n\n";
		system("pause");
		return false;
	}
	else
	{
		vector<string> holding;
		int test = 1;
		if (rounds == round_int)
		{
			int number_of_runs = resturants.size() / 2;

			for (int i = 0; i < resturants.size() / 2; i++)
			{
				test = 1;
				while (test == 1)
				{
					cout << "Match " << i + 1 << "/" << resturants.size() / 2 << ", " << "Round " << counter << "/" << rounds << " --- ";
					cout << resturants[2 * i] << " or " << resturants[(2 * i) + 1] << ": ";
					string input;
					getline(cin, input);
					if (input == resturants[2 * i] || input == resturants[(2 * i) + 1])
					{
						holding.push_back(input);
						test = 0;
					}
					else
					{
						cout << "Invalid Response" << "(" << input << ")" << "\n\n";
						test = 1;
					}
					if (i == (resturants.size() / 2) - 1)
					{
						tournament(holding, rounds, counter);
					}
				}
			}
		}
		else
		{
			cout << "Error!! You Do not Have an Appropriate Number of Resturants to have a Complete Tournament \n";
			return true;
		}
	}
}

int main()
{
	srand(time(0)); //Randomizer

	vector<string> resturants(8);
	resturants[0] = "Chick-fil-a";
	resturants[1] = "Olive Garden";
	resturants[2] = "Pizza Hut";
	resturants[3] = "Panda Express";
	resturants[4] = "Jimmy Johns";
	resturants[5] = "Cook Out";
	resturants[6] = "Golden Corral";
	resturants[7] = "Smithfields";
	bool test = true;

	while (test == true)
	{
		cout <<
			"Menu:\n" <<
			"Please Choose one of the Following Options\n" <<
			"Display all Resturants:\t 1\n" <<
			"Add a Resturant: \t 2\n" <<
			"Remove a Resturant: \t 3\n" <<
			"Shuffle the Vector: \t 4\n" <<
			"Begin the Tournament: \t 5\n" <<
			"Quit the Program: \t Q\n\n";

		string input;
		getline(cin, input);

		if (input == "Q" || input == "q")
		{
			test = false;
		}
		else if (input == "1")
		{
			for (int i = 0; i < resturants.size(); i++)
			{
				cout << resturants[i];
				if (i < resturants.size() - 1)
				{
					cout << ", ";
				}
			}
			cout << endl << endl;
			test = true;
		}
		else if (input == "2")
		{
			add(resturants);
			test = true;
		}
		else if (input == "3")
		{
			remove(resturants);
			test = true;
		}
		else if (input == "4")
		{
			shuffle(resturants);
			test = true;
		}
		else if (input == "5")
		{
			double rounds = (log(resturants.size()) / (log(2)));
			int counter = 0;
			
			test = tournament(resturants, rounds, counter);
		}
		else
		{
			cout << "Invalid Input Try Again\n\n";
			test = true;
		}
		cin.clear();
	}


	return 0;
}