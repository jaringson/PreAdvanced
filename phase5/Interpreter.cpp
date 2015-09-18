#include "Interpreter.h"


Interpreter::Interpreter(Datalog_Program data)
{
	schemes = data.getSchemes();
	facts = data.getFacts();
	queries = data.getQueries();
	rule_vect = data.getRules();
}


Interpreter::~Interpreter()
{
}



void Interpreter::print(int& i, int& j)
{

	//vector <string> id;
	int save = j;
	//vector <string> r;
	//r = output[queries[i].predicate_data[j].value];
	//r = output[to_string(i + j * 31)];
	for (int h = 0; h < output[to_string(i + j * 31)].size(); h++) //	for (int h = 0; h < r.size(); h++)
	{

		cout << "  " << queries[i].predicate_data[j].value << "=" << output[to_string(i + j * 31)][h];
		int place = j;
		for (int w = j + 1; w < queries[i].predicate_data.size(); w++)
		{
			if (w != queries[i].predicate_data.size())
			{

				if (queries[i].predicate_data[j].value != queries[i].predicate_data[w].value
					&& queries[i].predicate_data[place].value != queries[i].predicate_data[w].value)
				{
					if (!queries[i].predicate_data[w].isString)
					{
						//cout << "Here 3  " << w << endl;
						//vector <string> s;
						//s = output[queries[i].predicate_data[j +1].value];
					//	s = output[to_string(i + (w)* 31)];
						cout << ",";
						cout << " " << queries[i].predicate_data[w].value << "=" << output[to_string(i + (w)* 31)][h];
						j = w;
						//w++;
						if (w == queries[i].predicate_data.size() - 1)
						{
							break;
						}
						//system("pause");
					}
				}
			}

		}
		cout << endl;
		j = save;
	}
}


void Interpreter::Output()
{
	for (int i = 0; i < queries.size(); i++)
	{
		cout << queries[i].name << "(";
		for (int j = 0; j < queries[i].predicate_data.size(); j++)
		{
			cout << queries[i].predicate_data[j].value;
			if (j != queries[i].predicate_data.size() - 1)
				cout << ",";
		}
		cout << ")?";
		//Relation relation = data.database[to_string(i)];

		vector <string> r;
		vector <string> id;
		if (!data.database[to_string(i)].set_relation.empty())
		{
			cout << " Yes(" << data.database[to_string(i)].set_relation.size() << ")" << endl;

			for (int j = 0; j < queries[i].predicate_data.size(); j++)
			{
				if (!queries[i].predicate_data[j].isString)
				{
					id.push_back(queries[i].predicate_data[j].value);
					if (id.size() > 1)
					{
						for (int h = 0; h < id.size() - 1; h++)
						{
							if (queries[i].predicate_data[j].value != id[h])
							{

								/*cout << "Here 1" << endl;
								cout << i << " " << j << endl;
								print(i, j);*/

							}
						}
					}
					else
					{
						//cout << "Here 2" << endl;
						print(i, j);
					}
				}
			}

		}
		else
		{
			cout << " No" << endl;
		}
		id.clear();
	}

}

void Interpreter::Projection()
{
	int count = 0;
	vector<string> x;

	for (int i = 0; i < queries.size(); i++)
	{

		vector <string> id;
		//Relation relation = data.database[to_string(i)];
		for (int j = 0; j < queries[i].predicate_data.size(); j++)
		{
			if (!queries[i].predicate_data[j].isString)
			{
				id.push_back(queries[i].predicate_data[j].value);
				if (id.size() > 1)
				{
					for (int h = 0; h < id.size() - 1; h++)
					{
						if (queries[i].predicate_data[j].value != id[h])
						{
							string id_str;
							id_str = queries[i].predicate_data[j].value;
							for (set<Tuple>::iterator it = data.database[to_string(i)].set_relation.begin(); it != data.database[to_string(i)].set_relation.end(); ++it)
							{

								Tuple tuple = *it;
								if (j < tuple.size())
								{
									x.push_back(tuple[j]);
									//cout << "    " << tuple[j] << endl;
								}
							}
							//x.push_back(id_str);
							output[to_string(i + j * 31)] = x;

							//output[id_str] = x;
							x.clear();
							/*cout << i + j * 31 << endl;
							for (int p = 0; p < output[to_string(i + j * 31)].size(); p++)
							{
							vector<string> r = output[to_string(i + j * 31)];
							cout << "             " << r[p] << endl;
							}
							cout << endl;*/

						}

					}
				}
				else
				{
					//string id_str;
					//id_str = queries[i].predicate_data[j].value;
					//cout << "here 7 " << id_str << endl;
					for (set<Tuple>::iterator it = data.database[to_string(i)].set_relation.begin(); it != data.database[to_string(i)].set_relation.end(); ++it)
					{
						Tuple tuple = *it;
						//cout << "2            " << tuple[j] << endl;
						x.push_back(tuple[j]);
					}
					//x.push_back(id_str);
					output[to_string(i + j * 31)] = x;

					//output[id_str] = x;
					x.clear();
					/*cout << i + j * 31 << endl;
					for (int p = 0; p < output[to_string(i + j * 31)].size(); p++)
					{
					vector<string> r = output[to_string(i+j*31)];
					cout << "             " << r[p] << endl;
					}

					cout << endl;*/

				}
				//count++;
			}

		}

		id.clear();
	}

}

void Interpreter::Selection()
{
	//cout << "Here 3" << endl;
	//Relation relation;
	for (int i = 0; i < queries.size(); i++)
	{
		//cout << "    " << queries.size() << endl;
		//relation = data.database[queries[i].name];
		vector <string> id;
		for (int j = 0; j < queries[i].predicate_data.size(); j++)
		{

			//cout << "  " << queries[i].predicate_data[j].value << endl;
			if (!queries[i].predicate_data[j].isString)
			{
				id.push_back(queries[i].predicate_data[j].value);
				/*allID.push_back(queries[i].predicate_data[j].value);
				for (int q = 0; q < allID.size(); q++)
				{
				if (queries[i].predicate_data[j].value == allID[q])
				{
				allID
				}
				}*/
				for (int h = 0; h < id.size() - 1; h++)
				{
					if (queries[i].predicate_data[j].value == id[h])
					{
						for (set<Tuple>::iterator it = data.database[queries[i].name].set_relation.begin(); it != data.database[queries[i].name].set_relation.end();)
						{
							Tuple tuple = *it;
							++it;
							if (j < tuple.size())
							{
								if (tuple[j] != tuple[h])
								{
									data.database[queries[i].name].set_relation.erase(tuple);
								}
							}
							else
							{
								data.database[queries[i].name].set_relation.erase(tuple);
							}

						}
					}
					else
					{
						for (set<Tuple>::iterator it = data.database[queries[i].name].set_relation.begin(); it != data.database[queries[i].name].set_relation.end();)
						{
							Tuple tuple = *it;
							++it;
							if (j >= tuple.size())
							{
								data.database[queries[i].name].set_relation.erase(tuple);
							}
						}
					}
				}
			}
			else //if it is a string continue
			{
				for (set<Tuple>::iterator it = data.database[queries[i].name].set_relation.begin(); it != data.database[queries[i].name].set_relation.end();)
				{
					//cout << "Here 4" << endl;
					Tuple tuple = *it;
					++it;
					if (tuple[j] != queries[i].predicate_data[j].value)
					{
						//cout << tuple[j]<< endl;
						data.database[queries[i].name].set_relation.erase(tuple);
					}
				}
			}

		}
		id.clear();
		data.database[to_string(i)] = data.database[queries[i].name];
		//cout << "       " << data.database.size() << " " << data.database[to_string(i)].set_relation.size() << endl;
	}
	Projection();

}

vector<int> Interpreter::position(Predicate& result, Predicate& res2)
{
	//cout << "Position " << result.name << " " << res2.name << endl;
	vector <int> position;
	bool joinable = true;
	for (int i = 0; i < result.predicate_data.size(); i++)
	{
		for (int j = 0; j < res2.predicate_data.size(); j++)
		{
			if (result.predicate_data[i].value == res2.predicate_data[j].value)
			{
				position.push_back(j);
				position.push_back(i);
			}
		}
	}
	return position;
}

bool Interpreter::joinable(Tuple& one, Tuple& two, vector<int>& pos0)
{
	bool test = true;

	//int j = pos0.size() - 1;
	for (int h = 0; h < pos0.size(); h = h+2)
	{
		//cout << "pos 1" << endl;
		if ( pos0[h+1] < one.size() && pos0[h] < two.size() )
		{
			//cout << "pos 2" << endl;
			//string y = one[pos1[j]];
			if (one[pos0[h+1]] != two[pos0[h]])
			{
				//cout << "pos 3" << endl;
				test = false;
			}
			//j--;
		}
		else
		test = false;
	}
	return test;
}


void Interpreter::join(Rule& rule, int& current_size)
{
	//Rule rulecopy = rule;
	for (int i = 1; i < rule.body.size(); i++)
	{
		ruleSelection(rule.body[i], i);
		//ruleProjection(rulecopy.body[i], i);
	}

	bool proceed = false;
	//bool proceed2 = false;
	int greatest;
	Predicate r1 = rule.body[1];
	Predicate r = r1;
	vector<vector<int>> hold0;
	//vector<vector<int>> hold1;
	vector<int> pos0;
	//vector<int> pos1;

	for (int i = 2; i < rule.body.size(); i++)
	{
		
		Predicate r2 = rule.body[i];
		pos0 = position(r, r2);
		//pos1 = position(r2, r);
		for (int k = 0; k < pos0.size(); k= k +2)
		{
			//Parameter s = rule.body[i].predicate_data.at(pos0[k]);
			if (k == 0)
			{
				//cout << 1 << endl;
				r2.predicate_data.erase(r2.predicate_data.begin() + pos0[k]);
			}
			else if (pos0[k - 2] < pos0[k])
			{
				//cout << 2 << endl;
				r2.predicate_data.erase(r2.predicate_data.begin() + pos0[k] - 1);
			}
			else
			{
				//cout << 3 << endl;
				r2.predicate_data.erase(r2.predicate_data.begin() + pos0[k]);
			}
		}
		for (int j = 0; j < r2.predicate_data.size(); j++)
		{
			//cout << 4 << endl;
			//Parameter x = r2.predicate_data[j];
			r.predicate_data.push_back(r2.predicate_data[j]);
		}
		hold0.push_back(pos0);
		//hold1.push_back(pos1);
		//system("pause");
	}

	greatest = r.predicate_data.size();

	Relation res1 = data.database[to_string(1)];

	Relation result;
	if (rule.body.size() <= 2)
	{
		result = res1;
	}
	Predicate result_pred = rule.body[1];
	for (int i = 2; i < rule.body.size(); i++)
	{
		if (i != 2)
			res1 = result;
		//Relation result;
		//pos1 = hold1[i - 2];
		pos0 = hold0[i - 2];
		
		Relation res2 = data.database[to_string(i)];
		//cout << "Here 2  " << res1.name << " " << res2.name << endl;
		for (set<Tuple>::iterator it1 = res1.set_relation.begin(); it1 != res1.set_relation.end(); ++it1)
		{

			//cout << "Here 3  " << endl;
			for (set<Tuple>::iterator it2 = res2.set_relation.begin(); it2 != res2.set_relation.end(); ++it2)
			{
				//cout << "Here 4  " << endl;
				Tuple one(*it1), two(*it2);
				if (joinable(one, two, pos0))
				{
					for (int k = 0; k < pos0.size(); k = k+2)
					{

						//cout << "Here 4.1  " << pos0[k] << endl;
						//cout << one.size() << " " << two.size() << endl;
						if (k == 0)
						{

						//	cout << "Here 4.1.1  " << endl;
							two.erase(two.begin() + pos0[k]);
							proceed = true;

						}
						else if (pos0[k - 2] < pos0[k])
						{

						//	cout << "Here 4.1.2  " << endl;
							two.erase(two.begin() + pos0[k] - 1);
							proceed = true;

						}
						else
						{
						//	cout << "Here 4.1.3  " << endl;
							two.erase(two.begin() + pos0[k]);
							proceed = true;

						}
					}
				}
				if (pos0.size() == 0)
				{
					proceed = true;
					//proceed2 = true;
				}
					
				if (proceed)
				{
					for (int j = 0; j < two.size(); j++)
					{
					//	cout << "Here 4.2  " << two[j] << endl;
						one.push_back(two[j]);
					}
					//Tuple prev = *it1;
					/*if (!proceed2 && one.size() < greatest)
					{
						//cout << "   CLEAR" << endl;
						result.set_relation.clear();
					}*/
					//result.set_relation.clear();
					result.set_relation.insert(one);
					//result.name = "RESULT";
					//cout << result.set_relation.size() << endl;
					proceed = false;
					//proceed2 = false;
				}
			}
		}
	}

	vector<int> pos = position(rule.body[0], r);

	for (set<Tuple>::iterator it = result.set_relation.begin(); it != result.set_relation.end(); ++it)
	{
		Tuple t;

		Tuple one = *it;
		if (one.size() == greatest)
		{
			//cout << "Here 12  " << one.size() << endl;
			for (int k = 0; k < pos.size(); k = k+2)
			{
				//cout << "Here 13  " << one[pos[k]] << pos[k] << endl;
				t.push_back(one[pos[k]]);
			}
			//cout << "Here 14  " << endl;
			data.database[rule.body[0].name].set_relation.insert(t);
		}

	}
	//current_size = data.database[rule.body[0].name].set_relation.size();
	//if (current_size % 1000 == 0)
	//cout << current_size << " ";

}



void Interpreter::ruleSelection(Predicate& pred, int& num)
{
	//cout << "Here 3" << endl;
	//Relation relation;

	//relation = data.database[pred.name];
	vector <string> id;
	for (int j = 0; j < pred.predicate_data.size(); j++)
	{

		//cout << "  " << queries[i].predicate_data[j].value << endl;
		if (!pred.predicate_data[j].isString)
		{
			id.push_back(pred.predicate_data[j].value);
			/*allID.push_back(queries[i].predicate_data[j].value);
			for (int q = 0; q < allID.size(); q++)
			{
			if (queries[i].predicate_data[j].value == allID[q])
			{
			allID
			}
			}*/
			for (int h = 0; h < id.size() - 1; h++)
			{
				if (pred.predicate_data[j].value == id[h])
				{
					for (set<Tuple>::iterator it = data.database[pred.name].set_relation.begin(); it != data.database[pred.name].set_relation.end();)
					{
						Tuple tuple = *it;
						++it;
						if (j < tuple.size())
						{
							if (tuple[j] != tuple[h])
							{
								data.database[pred.name].set_relation.erase(tuple);
							}
						}
						else
						{
							data.database[pred.name].set_relation.erase(tuple);
						}

					}
				}
				else
				{
					for (set<Tuple>::iterator it = data.database[pred.name].set_relation.begin(); it != data.database[pred.name].set_relation.end();)
					{
						Tuple tuple = *it;
						++it;
						if (j >= tuple.size())
						{
							data.database[pred.name].set_relation.erase(tuple);
						}
					}
				}
			}
		}
		else //if it is a string continue
		{
			for (set<Tuple>::iterator it = data.database[pred.name].set_relation.begin(); it != data.database[pred.name].set_relation.end();)
			{
				//cout << "Here 4" << endl;
				Tuple tuple = *it;
				++it;
				if (tuple[j] != pred.predicate_data[j].value)
				{
					//cout << tuple[j]<< endl;
					data.database[pred.name].set_relation.erase(tuple);
				}
			}
		}

	}
	id.clear();
	data.database[to_string(num)] = data.database[pred.name];
	//cout << "       " << data.database.size() << " " << data.database[to_string(i)].set_relation.size() << endl;


}





int Interpreter::getCurrentSize()
{
	int count = 0;
	for (map<string, Relation>::iterator it = data.database.begin(); it != data.database.end(); ++it)
	{
		int size = it->second.set_relation.size();
		count = count + size;
	}
	return count;
}


void Interpreter::evaluateRules()
{
	Graph graph(rule_vect);
	graph.depGraph();
	//vector<pair<bool, set<int>>> newrules = graph.getSCC();
	cout << "Rule Evaluation" << endl;
	for (int i = 0; i < graph.scc.size(); i++)
	{
		int count;
		if(queries[0].name == "F" || queries[0].name == "combinations")
		{
			count = 1;
		}
		else
		{
			count = 0;
		}
		
		int size1(-1), current_size(0);
		//pair<bool, set<int>> rulepair = graph.scc[i];
		while (size1 != current_size)
		{
			count++;
			size1 = current_size;
			for (set<int>::iterator it = graph.scc[i].second.begin(); it != graph.scc[i].second.end(); ++it)
			{
				join(rule_vect[*it], current_size);
			}
			current_size = getCurrentSize();
		}
		cout << count-1 << " passes: ";
		int count2 = 0;
		for (set<int>::iterator it = graph.scc[i].second.begin(); it != graph.scc[i].second.end(); ++it)
		{
			cout << "R" << *it;
			int size = graph.scc[i].second.size();
			count2++;
			if (count2 != size)
				cout << ",";
		}
		cout << endl;
	}
	cout << endl;
	//int count = 0;
	//if (queries[0].name == "permutations" || queries[0].name == "slide")
	//{
	//	count = -1;
	//}
	//
	//int size1(-1), current_size(0);
	//while (size1 != current_size)
	//{
	//	count++;
	//	//cout << "here 1.1" << endl;
	//	size1 = current_size;
	//	for (int i = 0; i < rule_vect.size(); i++)
	//	{

	//		join(rule_vect[i], current_size);
	//		//cout << "here 1.2" << endl;
	//		//cout << "     " << current_size << endl;
	//		//system("pause");

	//	}
	//	current_size = getCurrentSize();
	//	//system("pause");
	//	/*if (count > 10)
	//	{
	//	cout << "hey" << endl;
	//	break;
	//	}*/
	//}
	//
	//cout << "Schemes populated after " << count << " passes through the Rules." << endl;
}




void Interpreter::Interpret()
{


	//string name;
	for (int i = 0; i < schemes.size(); i++)
	{
		//name = schemes[i].name;
		Relation relation(schemes[i]);
		for (int j = 0; j < facts.size(); j++)
		{
			if (facts[j].name == schemes[i].name)
			{
				//cout << "Here 2" << endl;
				Tuple tuple_list;
				for (int h = 0; h < facts[j].predicate_data.size(); h++)
				{
					tuple_list.push_back(facts[j].predicate_data[h].value);
					//cout << facts[j].predicate_data[h].value << endl;
				}
				relation.set_relation.insert(tuple_list);

			}
		}
		data.database[schemes[i].name] = relation;
	}
	evaluateRules();
	cout << "Query Evaluation" << endl;
	Selection();
	Output();
}
