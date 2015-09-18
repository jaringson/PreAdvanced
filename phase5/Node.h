#pragma once
#include <set>
#include <map>

using namespace std;
class Node
{
public:
	Node();
	~Node();
	int number;
	set<int> adj_nodes;
	bool visited;
	int post_num;
};

