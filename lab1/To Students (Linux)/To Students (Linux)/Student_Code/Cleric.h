#pragma once
#include "Fighter.h"
class Cleric :
	public Fighter
{
public:
	Cleric(string name_var, string type_var, int max_hit_points_var, int strength_var, int speed_var, int magic_var);
	~Cleric();
	void reset();
	void regenerate();
	bool useAbility();
	int getDamage();

private:
	int max_mana;
	int current_mana;
};


