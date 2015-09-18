#include "PathfinderInterface.h"
class Pathfinder :
	public PathfinderInterface
{
private:
	const int X_SIZE = 5;
	const int Y_SIZE = 5;
	const int Z_SIZE = 5;
	vector<string> vect_maze;
	int maze_array[5][5][5];
	int copy_array[5][5][5];
	int* pointer;
	string str_maze;
public:
	Pathfinder();
	~Pathfinder();
	string getMaze();
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
};

