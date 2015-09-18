#include <iostream>

using namespace std;

int main()
/*
My Own Case Tests
People 10000
Tip 95
Large 1428
Medium 1
Small 1
Area 448933
Area/People 44.933
Cost 40915

People 3
Tip 24
Large 0
Medium 1
Small 0
Area 201.062
Area/People 67.0206
Cost 14

People 10
Tip 52
Large 1
Medium 1
Small 0
Area 515.221
Area/People 51.5221
Cost 40
*/

{
	int people = 0;
	double people_original = 0;
	
	int tip = 0;
	int large = 0;
	int medium = 0;
	int small = 0;
	double price_large = 14.68;
	double price_meduim = 11.48;
	double price_small = 7.28;
	const double PI = 3.14159;
	const double RADIUS_LARGE = 10;
	const double RADIUS_MEDIUM = 8;
	const double RADIUS_SMALL = 6;

	cout << "Please enter Number of People Attending Event: ";
	cin >> people;
	people_original = people;      /* Need to have Total Number of 
										People saved for Later*/
	
	cout << "Percent Tip? ";
	cin >> tip;


	while (people > 6)
	{

		large++;
		people = people - 7;
	}

	while (people > 2)
	{

		medium++;
		people = people - 3;

	}

	while (people > 0)
	{

		small++;
		people = people - 1;

	}

	

	cout << "\nNumber of Large Pizzas: \t\t" << large << endl;
	cout << "Number of Medium Pizzas: \t\t" << medium << endl;
	cout << "Number of Small Pizzas: \t\t" << small << endl;

	double total_area = 0;
	total_area = large *PI*RADIUS_LARGE*RADIUS_LARGE + medium
		*PI*RADIUS_MEDIUM*RADIUS_MEDIUM + small*PI*RADIUS_SMALL*RADIUS_SMALL;

	cout << "Area: \t\t\t\t\t" << total_area << "in^2" << endl;
	cout << "Area per Person: \t\t\t" << total_area / people_original <<
		"in^2" << endl;

	double cost = large*price_large + medium *price_meduim + small* price_small;
	double total_cost = cost * tip *.01 + cost;
	cout << "Total Cost: \t\t\t\t$" << floor(total_cost + .5) /* important for 
		rounding! floor ( variable  + .5) */  << endl << endl << endl;

	system("pause");

	return 0;

}