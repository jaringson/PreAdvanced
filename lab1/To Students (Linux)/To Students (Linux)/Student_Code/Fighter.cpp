#include "Fighter.h"
#include <math.h>


Fighter::Fighter(string name_var, string type_var, int max_hit_points_var, int strength_var, int speed_var, int magic_var)
{
	name = name_var;
	type = type_var;
	max_hit_points = max_hit_points_var;
	current_hit_points = max_hit_points_var;
	strength = strength_var;
	speed = speed_var;
	magic = magic_var;
}


Fighter::~Fighter(){}

string Fighter::getName()
{
        return name;
}

int Fighter::getMaximumHP()
{
	return max_hit_points;

}

int Fighter::getCurrentHP()
{
	return current_hit_points;
}

int Fighter::getStrength()
{
	return strength;
}	

int Fighter::getSpeed()
{
	return speed;
}

int Fighter::getMagic()
{
	return magic;
}


void Fighter::takeDamage(int damage)
{
 double speed_calc = round(speed / 4);
int damage_taken = damage - speed_calc;
	if (damage_taken >1)
	{
		current_hit_points = current_hit_points - damage_taken;
	}
	else
	{
		current_hit_points = current_hit_points - 1;
	}
}

void Fighter::regenerate()
{
int add_hit_points= ((strength / 6));
 
	if(add_hit_points < 1 )
	  {
	    add_hit_points = 1;
	  }
	/*	if(add_hit_points >= 0 && add_hit_points <1.6)
	  {
	    add_hit_points = 1;
	    }*/
	/*		if (add_hit_points >1.6&& add_hit_points<1.7)
	  {
	    add_hit_points = 2;
	    } */
	if (max_hit_points-current_hit_points < add_hit_points)
		  {
		    add_hit_points =  max_hit_points-current_hit_points;
		  }

	if (current_hit_points + add_hit_points <= max_hit_points && current_hit_points + 1 <= max_hit_points)
	{
		if (add_hit_points >= 1)
		{
			current_hit_points = current_hit_points + add_hit_points;
		}
	
		else 
		  {
		    current_hit_points = current_hit_points + 1;
		  }
        
	}
	
}
