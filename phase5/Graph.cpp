#include "Graph.h"


Graph::Graph(vector<Rule> var_rule_vect)
{
	rule_vect = var_rule_vect;
	post_num = 0;
}
Graph::Graph()
{
}

Graph::~Graph()
{
}


bool Graph::DFS(Node& node, map<int, Node>& x)
{

	if (node.visited == false)
	{
		sub_scc.insert(node.number);
	}
	node.visited = true;
	
	//cout << "Here 1" << endl;
	//system("pause");
	for (set<int>::iterator it = node.adj_nodes.begin(); it != node.adj_nodes.end(); ++it)
	{
		//cout << "Here 2" << endl;
		if (x[*it].visited == false)
		{
			//cout << "Here 3 " << *it << endl;

			if (DFS(x[*it], x))
			{
				stack.push_back(*it);
				//cout << "    " << *it << endl;
				
			}
		}
	}
	return true;
}

void Graph::DFSforest(map<int, Node>& x)
{
	for (map<int, Node>::iterator it = x.begin(); it != x.end(); ++it)
	{
		//cout << it->first << endl;
		if (it->second.visited == false)
		{
			bool test = DFS(it->second, x);
			stack.push_back(it->first);
			//cout << "    " << it->first << endl;
		}
		//else
			//cout << "    not here" << endl;
	}
	//cout << "----------------------" << endl;
	SCC();
}
void Graph::printscc()
{
	for (int i = 0; i < scc.size(); i++)
	{
		pair<bool, set<int>> temp = scc[i];
		for (set<int>::iterator it = temp.second.begin(); it != temp.second.end(); ++it)
		for (int i = 0; i < temp.second.size();i++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}

bool Graph::isCyclic(set<int>& x)
{
	for (set<int>::iterator it = x.begin(); it != x.end(); ++it)
	//for (int i = 0; i < x.size();i++)
	{
		Node node = myGraph[*it];
		//Node node = myGraph[i];
		//cout << "    " << *it << endl;
		for (set<int>::iterator it2 = node.adj_nodes.begin(); it2 != node.adj_nodes.end(); ++it2)
		{
			//cout << node.post_num << " " << myGraph[*it2].post_num << endl;
			if (node.post_num < myGraph[*it2].post_num)
			{
				return false;
			}
		}
	}
	return true;
}


void Graph::SCC()
{
	int size = stack.size();
	for (int j = 0; j < stack.size(); j++)
	{
		myGraph[stack[j]].post_num = j;
		myGraph[stack[j]].number = stack[j];
		size--;
	}
	scc.clear();
	for (int i = stack.size() - 1; i > -1; i--)
	{
		sub_scc.clear();
		bool test = DFS(myGraph[stack[i]], myGraph);
		if (sub_scc.size() > 0)
		{
			pair<bool, set<int>> temp (false, sub_scc);
			scc.push_back(temp);
		}
	}
	/*printscc();
	for (int i = scc.size()-1; i >-1; i--)
	{
		pair<bool, set<int>> n = scc[i];
		bool test = isCyclic(n.second);
		if (test)
		{
			//scc[i].first = true;
			//cyclic.push_back(scc[i]);
			//cout << "true" << endl;
		}
		else
			//cout << "false" << endl;
	}*/
}

void Graph::calcrevGraph()
{
	for (int i = 0; i < rule_vect.size(); i++)
	{
		revGraph[i];
	}
	for (map<int, Node>::iterator it = myGraph.begin(); it != myGraph.end(); ++it)
	{
		Node x = it->second;
		int i = it->first;
		set<int> y = x.adj_nodes;
		for (set<int>::iterator it2 = y.begin(); it2 != y.end(); ++it2)
		{
			int num = *it2;
			revGraph[num].adj_nodes.insert(i);
		}
	}
	//cout << "Reverse" << endl;
	//print(revGraph);
	DFSforest(revGraph);
}

void Graph::depGraph()
{
	vector<string> bodystr;

	for (int i = 0; i < rule_vect.size(); i++)
	{
		names.push_back(rule_vect[i].body[0].name);
	}
	cout << "Dependency Graph" << endl;
	for (int i = 0; i < rule_vect.size(); i++)
	{
		Node x;
		for (int j = 1; j < rule_vect[i].body.size(); j++)
		{
			for (int k = 0; k < names.size(); k++)
			{
				if (rule_vect[i].body[j].name == names[k])
				{
					x.adj_nodes.insert(k);
				}
			}
		}
		myGraph[i] = x;
	}
	print(myGraph);
	calcrevGraph();
}

void Graph::print(map<int, Node>& myGraph)
{
	for (map<int, Node>::iterator it = myGraph.begin(); it != myGraph.end(); ++it)
	{
		Node x = it->second;
		int count = 0;
		set<int> y = x.adj_nodes;
		cout << "R" << it->first << ":";
		for (set<int>::iterator it2 = y.begin(); it2 != y.end(); ++it2)
		{
			cout << "R" << *it2;
			count++;
			int size = y.size();
			if (count != size)
				cout << ",";
		}
		cout << endl;
	}
	cout << endl;
}

vector<pair<bool, set<int>>> Graph::getSCC()
{
	return scc;
}
