#pragma once
#include "FighterInterface.h"
class Fighter :
	public FighterInterface
{
public:
	Fighter(string name_var, string type_var, int max_hit_points_var, int strength_var, int speed_var, int magic_var);
	~Fighter();

	virtual string getName();
	virtual int getMaximumHP();
	virtual int getCurrentHP();
	virtual int getStrength();
	virtual int getSpeed();
	virtual int getMagic();
	virtual int getDamage() = 0;
	virtual void takeDamage(int damage);
	virtual void reset() = 0;
	virtual void regenerate();
	virtual bool useAbility() =0;

protected:

	string name;
	string type;
	int max_hit_points;
	int current_hit_points;
	int strength;
	int speed;
	int magic;
	
	int damage;
};

