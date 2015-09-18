#include <iostream>
#include <string>

using namespace std;

/*Answer to Extra Credit= 166.6667 or 500/3 mpg*/

/* Test Cases

#1
Miles/Year: 200
Gallons of Gas: 3.00

Hybrid Cost: 42000
Hybrid Fuel Efficency: 50
Hybrid Resale: 20000

Non-Hybrid Cost: 36000
Non-Hybrid Fuel Efficency: 20
Non-Hybrid Resale: 10000

Choose Gas or Total: Gas
 
Hybrid Total Gas: 20
Hybrid Total Cost: 22060
Non-Hybrid Total Gas: 50
Non-Hybrid Total Cost: 26150



#2
Miles/Year: 50000
Gallons of Gas: 3.87

Hybrid Cost: 50000
Hybrid Fuel Efficency: 60
Hybrid Resale: 25000

Non-Hybrid Cost: 20000
Non-Hybrid Fuel Efficency: 15
Non-Hybrid Resale: 10000

Choose Gas or Total: Total

Hybrid Total Cost: 41125
Hybrid Total Gas: 4166.67
Non-Hybrid Total Cost: 74500
Non-Hybrid Total Gas: 16666.7


#3
Miles/Year: 35688
Gallons of Gas: 4.56

Hybrid Cost: 100000
Hybrid Fuel Efficency: 45
Hybrid Resale: 50000

Non-Hybrid Cost: 22000
Non-Hybrid Fuel Efficency: 18
Non-Hybrid Resale: 11000

Choose Gas or Total: Total

Non-Hybrid Total Cost: 56204.8
Non-Hybrid Total Gas: 9913.33
Hybrid Total Cost: 68081.9
Hybrid Total Gas: 3965.33



*/

int main() 
{

	double miles_driven_a_year = 0;
	double price_gallons_of_gas = 0;

	double cost_hybrid = 0;
	double hybrid_miles_per_gallon = 0;
	double resale_hybrid = 0;

	double cost_nonhybrid = 0;
	double nonhybrid_miles_per_gallon = 0;
	double resale_nonhybrid = 0;

	const double YEARS = 5;
	double total_cost_hybrid;
	double total_cost_nonhybrid;
	double total_gas_hybrid;
	double total_gas_nonhybrid;


	//Input 
	cout << "Please Input Your Estimated Miles Driven Per Year: ";
	cin >> miles_driven_a_year;
	if (miles_driven_a_year < 0)
	{
		cout << "Error: Must be a Positive Number!\n";
		cout << "Please Input Estimate Miles Driven Per Year: ";
		cin >> miles_driven_a_year;
	}

	cout << "Please Input Price of a Gallon of Gas: ";
	cin >> price_gallons_of_gas;
	if (price_gallons_of_gas < 0)
	{
		cout << "Error: Must be a Positive Number!\n";
		cout << "Please Input Price of a Gallon of Gas: ";
		cin >> price_gallons_of_gas;
	}

	cout << endl; //Extra Space
	cout << "Please Input Cost of the Hybrid Car: ";
	cin >> cost_hybrid;
	if (cost_hybrid < 0)
	{
		cout << "Error: Must be a Positive Number!\n";
		cout << "Please Input Cost of the Hybrid Car: ";
		cin >> cost_hybrid;
	}

	cout << "Please Input Hybrid Car Fuel Efficiency: ";
	cin >> hybrid_miles_per_gallon;
	if (hybrid_miles_per_gallon < 0)
	{
		cout << "Error: Must be a Positive Number!\n";
		cout << "Please Input Hybrid Car Fuel Efficiency: ";
		cin >> hybrid_miles_per_gallon;
	}

	cout << "Please Input Estimate Resale Value of the Hybrid After 5 Years: ";
	cin >> resale_hybrid;
	if (resale_hybrid < 0)
	{
		cout << "Error: Must be a Positive Number!\n";
		cout << "Please Input Estimate Resale Value of the Hybrid After 5 Years: ";
		cin >> resale_hybrid;
	}

	cout << endl; //Extra Space
	cout << "Please Input Cost of the Non-Hybrid Car: ";
	cin >> cost_nonhybrid;
	if (cost_nonhybrid < 0)
	{
		cout << "Error: Must be a Positive Number!\n";
		cout << "Please Input Cost of the Non-Hybrid Car: ";
		cin >> cost_nonhybrid;
	}

	cout << "Please Inpute Non-Hyrid Car Fuel Efficiency: ";
	cin >> nonhybrid_miles_per_gallon;
	if (nonhybrid_miles_per_gallon < 0)
	{
		cout << "Error: Must be a Positive Number!\n";
		cout << "Please Input Non-Hyrid Car Fuel Efficiency: ";
		cin >> nonhybrid_miles_per_gallon;
	}

	cout << "Please Input Estimate Resale Value of the Non-Hybrid Car After 5 years: ";
		cin >> resale_nonhybrid;
	if (resale_nonhybrid < 0)
	{
		cout << "Error: Must be a Positive Number!\n";
		cout << "Please Input Estimate Resale Value of the Non-Hybrid Car After 5 years: ";
		cin >> resale_nonhybrid;
	}

	/* Hybrid */
	total_gas_hybrid = (YEARS * miles_driven_a_year) / hybrid_miles_per_gallon;
	
	total_cost_hybrid = total_gas_hybrid * price_gallons_of_gas + cost_hybrid - resale_hybrid;

	/*Non-Hybrid*/
	total_gas_nonhybrid = (YEARS * miles_driven_a_year) / nonhybrid_miles_per_gallon;

	total_cost_nonhybrid = total_gas_nonhybrid * price_gallons_of_gas + cost_nonhybrid - resale_nonhybrid;

	//Choose which Option to do: gas or total
	string gas;

	cout << endl; //Extra Space

	cout << "Please Choose Gas or Total as your choice of input: ";

	cin >> gas;

	cout << endl; //Extra Space

	if (gas == "gas" || gas == "Gas")
		
	{
		if (total_gas_hybrid < total_gas_nonhybrid)
		{
			cout << "Hybrid's Total Gas Consuption: " << total_gas_hybrid << endl;
			cout << "Hybrid's Total Cost: " << total_cost_hybrid << endl;
			cout << "Non-Hybrid's Total Gas Consuption: " << total_gas_nonhybrid << endl;
			cout << "Non-Hybrid's Total Cost: " << total_cost_nonhybrid << endl;
		}
		else
		{ 
			cout << "Non-Hybrid's Total Gas Consuption: " << total_gas_nonhybrid << endl;
			cout << "Non-Hybrid's Total Cost: " << total_cost_nonhybrid << endl;
			cout << "Hybrid's Total Gas Consuption: " << total_gas_hybrid << endl;
			cout << "Hybrid's Total Cost: " << total_cost_hybrid << endl;
		}
	}

	else
	{
		if (total_cost_hybrid < total_cost_nonhybrid)
		{
			cout << "Hybrid's Total Cost: " << total_cost_hybrid << endl;
			cout << "Hybrid's Total Gas Consuption: " << total_gas_hybrid << endl;
			cout << "Non-Hybrid's Total Cost: " << total_cost_nonhybrid << endl;
			cout << "Non-Hybrid's Total Gas Consuption: " << total_gas_nonhybrid << endl;
		}
		else
		{
			cout << "Non-Hybrid's Total Cost: " << total_cost_nonhybrid << endl;
			cout << "Non-Hybrid's Total Gas Consuption: " << total_gas_nonhybrid << endl;
			cout << "Hybrid's Total Cost: " << total_cost_hybrid << endl;
			cout << "Hybrid's Total Gas Consuption: " << total_gas_hybrid << endl;
		}
	}
	
	cout << endl; //Extra Space

	system("pause");
	return 0;


}