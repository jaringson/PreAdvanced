#include "Robot.h"
#include <cmath>


Robot::Robot(string name_var, string type_var, int max_hit_points_var, int strength_var, int speed_var, int magic_var)
	: Fighter(name_var, type_var, max_hit_points_var, strength_var, speed_var, magic_var)
{
        
	max_energy = 2 * magic_var;
	current_energy = max_energy;
}


Robot::~Robot()
{
}

int Robot::getDamage()
{
	int turns_damage = strength + bonus_damage;
	bonus_damage = 0;
	return turns_damage;
}

void Robot::reset()
{
	current_hit_points = max_hit_points;
	current_energy = max_energy;
	bonus_damage = 0;
}

bool Robot::useAbility()
{
	if (current_energy >= ROBOT_ABILITY_COST)
	{
	  double added_damage = strength  * (pow((1.0 * current_energy / max_energy), 4));
		bonus_damage = added_damage;
		current_energy = current_energy -  ROBOT_ABILITY_COST;
		return true;
	}
	else
	{
		return false;
	}
	
}
