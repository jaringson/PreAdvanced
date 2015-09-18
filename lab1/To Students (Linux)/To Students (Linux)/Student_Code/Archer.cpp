#include "Archer.h"


Archer::Archer(string name_var, string type_var, int max_hit_points_var, int strength_var, int speed_var, int magic_var)
	:Fighter(name_var, type_var, max_hit_points_var, strength_var, speed_var, magic_var)
{
	damage = speed_var;	
	original_speed = speed_var;
}


Archer::~Archer()
{
}

int Archer::getDamage()
{
	return speed;
}

void Archer::reset()
{
	current_hit_points = max_hit_points;
        speed = original_speed;
}

bool Archer::useAbility()
{
	speed = speed + 1;
	return true;
}
