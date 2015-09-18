#pragma once
#include <set>
#include <map>
#include "Node.h"
#include "Rule.h"
#include <vector>

using namespace std;
class Graph
{
public:
	Graph(vector<Rule> rule_vect);
	Graph();
	~Graph();
	vector< int> stack;//first int is the post number second in the Node
	vector<string> names;
	map<int, string> depRules;
	vector<set<int>> depPos;
	vector<Rule> rule_vect;
	map<int, Node> myGraph;
	map<int, Node> revGraph;
	int post_num; 
	vector<pair<bool, set <int>>> scc;
	set<int> sub_scc;
	vector<set<int>> cyclic;

	void createForest();
	void createReverseForest();
	void depGraph();
	void calcrevGraph();
	void print(map<int, Node>& myGraph);
	void DFSforest(map<int, Node>& x);
	bool DFS(Node& node, map<int, Node>& x);
	void SCC();
	void printscc();
	bool isCyclic(set<int>& x);
	vector<pair<bool, set<int>>> getSCC();
};

