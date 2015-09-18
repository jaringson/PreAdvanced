#include "Cleric.h"


Cleric::Cleric(string name_var, string type_var, int max_hit_points_var, int strength_var, int speed_var, int magic_var)
	:Fighter(name_var, type_var, max_hit_points_var, strength_var, speed_var, magic_var)
{
	damage = magic_var;
	max_mana = magic_var * 5;
	current_mana = max_mana;
}


Cleric::~Cleric()
{
}

int Cleric::getDamage()
{
	return magic;
}

void Cleric::reset()
{
	current_hit_points = max_hit_points;
	current_mana = max_mana;
}

void Cleric::regenerate()
{
	Fighter::regenerate();
	int add_mana = (magic / 5);
	if (current_mana + add_mana <= max_mana || current_mana + 1 <= max_mana)
	{
		if (add_mana >= 1)
		{
			current_mana = current_mana + add_mana;
		}
		else
		{
			current_mana = current_mana + 1;
		}

	}
}

bool Cleric::useAbility()
{
	if (current_mana > CLERIC_ABILITY_COST)
	{

		int add_hit_points = (magic / 3);	
		current_mana = current_mana - CLERIC_ABILITY_COST;

		if (current_hit_points + add_hit_points <= max_hit_points || current_hit_points + 1 <= max_hit_points)
		{
			if (add_hit_points >= 1)
			{
				current_hit_points = current_hit_points + add_hit_points;
			}
			else
			{
				current_hit_points = current_hit_points + 1;
			}

			return true;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
