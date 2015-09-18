#pragma once
#include "Fighter.h"
class Archer :
	public Fighter
{
public:
	Archer(string name_var, string type_var, int max_hit_points_var, int strength_var, int speed_var, int magic_var);
	~Archer();
	void reset();
	bool useAbility();
	int getDamage();

private:
	int original_speed;
};

