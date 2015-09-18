#include "Interpreter.h"


Interpreter::Interpreter(Datalog_Program data)
{
	schemes = data.getSchemes();
	facts = data.getFacts();
	queries = data.getQueries();
}


Interpreter::~Interpreter()
{
}

void Interpreter::print(int& i, int& j)
{
	//vector <string> id;
	int save = j;
	vector <string> r;
	//r = output[queries[i].predicate_data[j].value];
	r = output[to_string(i + j * 31)];
	for (int h = 0; h < r.size(); h++) //	for (int h = 0; h < r.size(); h++)
	{

		cout << " " << queries[i].predicate_data[j].value << "=" << r[h];
int place = j;
		for (int w = j + 1; w < queries[i].predicate_data.size(); w++)
		{
			if (w != queries[i].predicate_data.size() )
			{
				if (queries[i].predicate_data[j].value != queries[i].predicate_data[w].value
				&& queries[i].predicate_data[place].value != queries[i].predicate_data[w].value)
				{
					if (!queries[i].predicate_data[w].isString)
					{
						//cout << "Here 3  " << w << endl;
						vector <string> s;
						//s = output[queries[i].predicate_data[j +1].value];
						s = output[to_string(i + (w)* 31)];
						cout << ",";
						cout << " " << queries[i].predicate_data[w].value << "=" << s[h];
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
		Relation relation = data.database[to_string(i)];

		vector <string> r;
		vector <string> id;
		if (!relation.set_relation.empty())
		{
			cout << " Yes(" << relation.set_relation.size() << ")" << endl;

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
		Relation relation = data.database[to_string(i)];
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
							for (set<Tuple>::iterator it = relation.set_relation.begin(); it != relation.set_relation.end(); ++it)
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
					string id_str;
					id_str = queries[i].predicate_data[j].value;
					//cout << "here 7 " << id_str << endl;
					for (set<Tuple>::iterator it = relation.set_relation.begin(); it != relation.set_relation.end(); ++it)
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
	Relation relation;
	for (int i = 0; i < queries.size(); i++)
	{
		//cout << "    " << queries.size() << endl;
		relation = data.database[queries[i].name];
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
						for (set<Tuple>::iterator it = relation.set_relation.begin(); it != relation.set_relation.end();)
						{
							Tuple tuple = *it;
							++it;
							if (j < tuple.size())
							{
								if (tuple[j] != tuple[h])
								{
									relation.set_relation.erase(tuple);
								}
							}
							else
							{
								relation.set_relation.erase(tuple);
							}

						}
					}
					else
					{
						for (set<Tuple>::iterator it = relation.set_relation.begin(); it != relation.set_relation.end();)
						{
							Tuple tuple = *it;
							++it;
							if (j >= tuple.size())
							{
								relation.set_relation.erase(tuple);
							}
						}
					}
				}
			}
			else //if it is a string continue
			{
				for (set<Tuple>::iterator it = relation.set_relation.begin(); it != relation.set_relation.end();)
				{
					//cout << "Here 4" << endl;
					Tuple tuple = *it;
					++it;
					if (tuple[j] != queries[i].predicate_data[j].value)
					{
						//cout << tuple[j]<< endl;
						relation.set_relation.erase(tuple);
					}

				}
			}

		}
		id.clear();
		data.database[to_string(i)] = relation;
		//cout << "       " << data.database.size() << " " << data.database[to_string(i)].set_relation.size() << endl;

	}
	Projection();

}

void Interpreter::Interpret()
{

	string name;
	for (int i = 0; i < schemes.size(); i++)
	{
		name = schemes[i].name;
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
	Selection();
	Output();
}
