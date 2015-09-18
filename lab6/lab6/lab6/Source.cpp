#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

const int ROWS = 20;
const int COLUMNS = 20;
const double PARAMETER = .1;

void assignment(double array[][COLUMNS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			array[i][j] = 0;
			if ((i == 0 || i == ROWS - 1) && j > 0 && j < COLUMNS - 1)
			{
				array[i][j] = 100;
			}
		}
	}
}

double print(double hot_plate_array[][COLUMNS])
{

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << fixed << setprecision(2) << setw(8) << hot_plate_array[i][j];
		}
		cout << endl;
	}
	return 1;
}

double average(double hot_plate_array[][COLUMNS], double holding_array[][COLUMNS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (i > 0 && i < ROWS - 1 && j > 0 && j < COLUMNS - 1)
			{
				double average = (hot_plate_array[i - 1][j] + hot_plate_array[i + 1][j] + hot_plate_array[i][j - 1] + hot_plate_array[i][j + 1]) / 4;
				holding_array[i][j] = average;
			}
		}
	}
	return 1;
}

double switcher(double hot_plate_array[][COLUMNS], double holding_array[][COLUMNS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			hot_plate_array[i][j] = holding_array[i][j];
		}
	}
	return 1;
}


double checker(double hot_plate_array[][COLUMNS], double holding_array[][COLUMNS])
{
	double highest_number = 0;
	for (int i = 1; i < ROWS - 1; i++)
	{
		for (int j = 1; j < COLUMNS - 1; j++)
		{
			double number = holding_array[i][j] - hot_plate_array[i][j];

			if (highest_number < number)
			{
				highest_number = number;
			}

			if (i == ROWS - 2 && j == COLUMNS - 2)
			{
				if (highest_number < PARAMETER && highest_number > 0)
				{
					double random = print(holding_array);
					return 0;
				}
				double random = switcher(hot_plate_array, holding_array);
				random = average(hot_plate_array, holding_array);
				return 1;
			}
		}
	}
	return 1;
}

void out_source(double holding_array[][COLUMNS])
{
	ofstream out_file("hotplate.csv");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			out_file << holding_array[i][j] << ",";
		}
		out_file << endl;
	}

}

int main()

{
	double random = 0;
	double hot_plate_array[ROWS][COLUMNS];
	double holding_array[ROWS][COLUMNS];
	double check = 1;

	assignment(hot_plate_array);
	random = print(hot_plate_array);
	system("pause");

	assignment(holding_array);
	random = average(hot_plate_array, holding_array);
	random = print(holding_array);
	system("pause");
	cout << endl;

	do
	{
		check = checker(hot_plate_array, holding_array);
	} while (check == 1);


	out_source(holding_array);


	system("pause");
	return 0;
}