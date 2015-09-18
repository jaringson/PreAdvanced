#include "Arena.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"
#include <sstream>
#include <string>
using namespace std;

Arena::Arena()
{
}
Arena::~Arena()
{
}

bool Arena::addFighter(string info)
{
	bool proceed = true;
	string name_var;
	string type_var;
	int max_hit_points_var;
	int strength_var;
	int speed_var;
	int magic_var;
	string rest_of_line; // to check if there is anything extra
	
	stringstream tempstream(info);

	if(tempstream >> name_var >> type_var >> max_hit_points_var >> strength_var >> speed_var >> magic_var)
	  {
	    proceed =true;
	  }
	else
	  {
	    proceed = false;
	    return false;
	  }
	if(type_var == "A" || type_var == "R" || type_var == "C")
	  {
	    proceed = true;
	  }
	else
	  {
	    proceed = false;
	    }
	if (getline(tempstream, rest_of_line))
	{
		proceed = false;
	}
	if (max_hit_points_var <= 0 || strength_var <= 0 || speed_var <= 0 || magic_var <= 0)
	{
		return false;
		proceed = false;
	}
		
	if (proceed)
	{
		for (int i = 0; i < arenas.size(); i++)
		{
			if (arenas[i]->getName() == name_var)
			{
				proceed = false;
				
			}
		}
		if (proceed)
		{
			if (type_var == "A")
			{
				Archer* a = new Archer(name_var, type_var, max_hit_points_var, strength_var, speed_var, magic_var);
				arenas.push_back(a);
				return true;
			}
			if (type_var == "C")
			{
				Cleric* c = new Cleric(name_var, type_var, max_hit_points_var, strength_var, speed_var, magic_var);
				arenas.push_back(c);
				return true;
			}
			if (type_var == "R")
			{
				Robot* r = new Robot(name_var, type_var, max_hit_points_var, strength_var, speed_var, magic_var);
				arenas.push_back(r);
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Arena::removeFighter(string name)
{
	for (int i = 0; i < arenas.size(); i++)
	{
		if (arenas[i]->getName() == name)
		{
			if (i == arenas.size() - 1)
			{
				arenas.pop_back();
				return true;
			}
			for (int j = i; j < arenas.size() - 1; j++)
			{
				arenas[j] = arenas[j + 1];
				arenas.pop_back();
			}
			
			return true;
		}
	}
	return false;
}

FighterInterface* Arena::getFighter(string name)
{
	for (int i = 0; i < arenas.size(); i++)
	{
		if (arenas[i]->getName() == name)
		{
			return arenas[i];
		}
	}
	return NULL;
}

int Arena::getSize()
{
	return arenas.size();
}
