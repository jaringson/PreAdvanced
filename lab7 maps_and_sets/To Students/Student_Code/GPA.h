#pragma once
#include "GPAInterface.h"
#include "Student.h"
#include <fstream>
#include <sstream>
#include <vector>
class GPA :
	public GPAInterface
{
private:
	
public:
	vector<int> id_holder;
	map < unsigned long long int, StudentInterface* > student_map;
	set < StudentInterface*, Comparator> student_set;
	GPA();
	~GPA();
	map<unsigned long long int, StudentInterface*> getMap();
	set<StudentInterface*, Comparator> getSet();
	bool importStudents(string mapFileName, string setFileName);
	bool importGrades(string fileName);
	string querySet(string fileName);
	string queryMap(string fileName);
	void clear();
};

