#pragma once
#include "Fighter.h"
class Robot :
	public Fighter
{
public:
	Robot(string name_var, string type_var, int max_hit_points_var, int strength_var, int speed_var, int magic_var);
	~Robot();
	void reset();
	bool useAbility();
	int getDamage();

private:
	int max_energy;
	int current_energy;
	int bonus_damage;
	double added_damage;

};

