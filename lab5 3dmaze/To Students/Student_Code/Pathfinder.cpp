#include "Pathfinder.h"
#include <sstream>
#include <fstream>
#include <sstream>
//Test
Pathfinder::Pathfinder()
{
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int z = 0; z < 5; z++)
			{
				maze_array[x][y][z] = 1;
			}
		}
	}
}


Pathfinder::~Pathfinder()
{

}

string Pathfinder::getMaze()
{
	stringstream holder;
	for (int z = 0; z < 5; z++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
			  holder << maze_array[x][y][z] << " ";
			}
			holder << endl;
		}
		holder << endl << endl;
	}
	return holder.str();
}
void Pathfinder::createRandomMaze()
{
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int z = 0; z < 5; z++)
			{
				maze_array[x][y][z] = rand() % 2;
			}
		}
	}
	maze_array[0][0][0] = 1;
	maze_array[4][4][4] = 1;
}
bool Pathfinder::importMaze(string file_name)
{
	int value;
  int counter = 0;
  bool proceed = false;
	ifstream in_file; //Creating a stream to read in the file
	in_file.open(file_name);
	if (in_file.is_open())
	  {

		for (int z = 0; z < 5; z++)
		{
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 5; x++)
				{
				  if(in_file >> value)
				    {
				      if(value == 1 || value == 0)
					{
					  if(value == 1)
					    {
					  
					      copy_array[x][y][z] = value;
					      proceed = true;
					      counter++;
					    }
					  else 
					    {
					      copy_array[x][y][z] = value;
					      proceed = true;
					    }
					}
				      else 
					{
					  return false;
					}
				    }
				  else 
				    {
				      return false;
				    }
				}
			}
		}
		if(in_file >> value)
		  {
		    return false;
		  }
		if( copy_array[0][0][0]!= 1 ||  copy_array[4][4][4]!= 1)
		  {
		    return false;
		  }
		/*	if(counter== 125)
		  {proceed = false;}*/
		if(proceed)
		  {
		    for (int z = 0; z < 5; z++)
		      {
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 5; x++)
				{
				  maze_array[x][y][z]= copy_array[x][y][z];
				}
			}
		      }
		    return true;
		  }
		else
		  {
		    return false;
		  }
	}
	else
	{
	  //	cout << "Invalid File Location: " << file_name << endl;
		return false;
	}
}

bool find_path(int copy_array[][5][5],  vector<string>& vect_maze, int x, int y, int z)
{
 
	//2 = Path
	if (x < 0 || x > 4 || y < 0 || y > 4 || z < 0 || z > 4)
	{	
		return false;
	}
	
	else if (copy_array[x][y][z] != 1)
	{
		return false;
	}
	else if (x == 4 && y == 4 && z == 4)
	{
	
		copy_array[x][y][z] = 2;
		stringstream output;
		output << "(" << x << ", " << y << ", " << z << ")";
		vect_maze.push_back(output.str());
		return true;
	}
	else
	{
		
		copy_array[x][y][z] = 2;
		if (find_path(copy_array, vect_maze, x, y, z + 1) || find_path(copy_array, vect_maze, x, y, z - 1) ||
			find_path(copy_array, vect_maze, x, y + 1, z) || find_path(copy_array, vect_maze, x, y - 1, z) ||
			find_path(copy_array, vect_maze, x + 1, y, z) || find_path(copy_array, vect_maze, x - 1, y, z))
		{
			stringstream output;
			output << "(" << x << ", " << y << ", " << z << ")";
			vect_maze.push_back(output.str());
			return true;
		}
		else
		{
			copy_array[x][y][z] = -1;
			return false;
		}
	}
}


vector<string> Pathfinder::solveMaze()
{
	for (int z = 0; z < 5; z++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
			  while(!vect_maze.empty())
			    {
			      vect_maze.pop_back();
			    }

				copy_array[x][y][z] = maze_array[x][y][z];
			}
		}
	}
	
	bool var = find_path(copy_array, vect_maze, 0 ,0,0 );
	//	return vect_maze;
	vector<string> vect_holder;
	for(int i = 1; i <= vect_maze.size(); i++)
	  {
	    vect_holder.push_back(vect_maze[vect_maze.size()-i]);
	  }
	      return vect_holder;
}
