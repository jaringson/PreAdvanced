#pragma once
#include "ArenaInterface.h"
using namespace std;

class Arena :
	public ArenaInterface
{
public:
	Arena();
	~Arena();

	bool addFighter(string info);

	bool removeFighter(string name);

	FighterInterface* getFighter(string name);

	int getSize();	

private:
	/*string name;
	string type;
	int max_hit_points;
	int strength;
	int speed;
	int magic;*/
	vector<FighterInterface*> arenas;

};
	

