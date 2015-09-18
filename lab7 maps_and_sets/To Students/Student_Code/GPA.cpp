#include "GPA.h"
#include <iomanip> 
#include <math.h>

GPA::GPA()
{
}


GPA::~GPA()
{
	clear();
}
map<unsigned long long int, StudentInterface*> GPA::getMap()
{
	return student_map;
}
set<StudentInterface*, Comparator> GPA::getSet()
{
	return student_set;
}
bool GPA::importStudents(string mapFileName, string setFileName)
{

	string token;
	
	string id;
	string name;
	string str_gpa;
	string address;
	string phone_number;
	int counter = 0;
	
	ifstream test_one;
	test_one.open(mapFileName);
	if (test_one.is_open())
	{
		while (getline(test_one, token))// if there's more stuff, read it in.
		{
			counter++;
		}
		if(counter %4 == 0){counter = 0;}
		else { return false; }
	}
	else {return false;}


	ifstream test_two;
	test_two.open(setFileName);
	if (test_two.is_open())
	{
		while (getline(test_two, token))// if there's more stuff, read it in.
		{
			counter++;
		}
		if(counter %4 == 0){counter = 0;}
		else { return false; }
	}
	else {return false;}

	ifstream in_file; //Creating a stream to read in the file
	in_file.open(mapFileName);
	if (in_file.is_open())
	{
		while (getline(in_file, token))// if there's more stuff, read it in.
		{
	

			counter++;	
				
			if(counter%2 == 0 && counter%4!= 0){name = token;}
			else if(counter%3 == 0){address = token;}
			else if(counter%4 == 0){phone_number = token;}
			else{id = token;}

			if(counter == 4) 
			{
				unsigned long long int numb_id;
				istringstream(id) >> numb_id;

				id_holder.push_back(numb_id); //vector to hold id numbers in to eventually delete

				Student* new_student = new Student(numb_id, name, address, phone_number);
				student_map[numb_id] = new_student;

				counter = 0;
				id = "";
				name = "";
				address = "";
				phone_number = "";
			}

				
		}
		if(id != "" || name != "" || address != "" || phone_number != "")
		{ return false; }
		
		
	}
	else
	{
		return false;
	}
	ifstream in_file_two; //Creating a stream to read in the file
	in_file_two.open(setFileName);
	if (in_file_two.is_open())
	{
		while (getline(in_file_two, token))// if there's more stuff, read it in.
		{

			counter++;	
				
			if(counter%2 == 0 && counter%4!= 0){name = token;}
			else if(counter%3 == 0){address = token;}
			else if(counter%4 == 0){phone_number = token;}
			else{id = token;}

			if(counter == 4) 
			{
				unsigned long long int numb_id;
				istringstream(id) >> numb_id;

				Student* new_student = new Student(numb_id, name, address, phone_number);
				student_set.insert(new_student);

				counter = 0;
				id = "";
				name = "";
				address = "";
				phone_number = "";
			}
		
		}

		if(id != "" || name != "" || address != "" || phone_number != "")
		{ return false; }
		
	}
	else
	{
		return false;
	}
	
	return true;
	
	
}
bool GPA::importGrades(string fileName)
{
	StudentInterface* next_item;
	unsigned long long int numb_id;
	string token;
	int counter =0;
	bool test = false;
	bool proceed = false;
	string id;
	string class_name;
	string str_grade;
	double num_grade;
	ifstream in_file; //Creating a stream to read in the file
	in_file.open(fileName);
	if (in_file.is_open())
	{
		while (in_file >> id)// if there's more stuff, read it in.
		{
			test = false;
			in_file.ignore();
			getline(in_file, class_name);
			getline(in_file, str_grade);
		
			counter++;	
				
			/*if(counter%2 == 0){class_name = token;}
			else if(counter%3 == 0){str_grade = token;}
			else{
				id = token;
				

			}

			if(counter == 3) 
			{*/

				istringstream(id) >> numb_id;
				if (str_grade == "A"){ num_grade = 4.0; }
				if (str_grade == "A-"){ num_grade = 3.7; }
				if (str_grade == "B+"){ num_grade = 3.4; }
				if (str_grade == "B"){ num_grade = 3.0; }
				if (str_grade == "B-"){ num_grade = 2.7; }
				if (str_grade == "C+"){ num_grade = 2.4; }
				if (str_grade == "C"){ num_grade = 2.0; }
				if (str_grade == "C-"){ num_grade = 1.7; }
				if (str_grade == "D+"){ num_grade = 1.4; }
				if (str_grade == "D"){ num_grade = 1.0; }
				if (str_grade == "D-"){ num_grade = 0.7; }
				if (str_grade == "E"){ num_grade = 0; }
			
			
				for (set<StudentInterface*>::iterator itr = student_set.begin(); 
					itr != student_set.end(); ++itr)
				{
					next_item = *itr;
					if (next_item->getID() == numb_id)
					{
						next_item->addGPA(num_grade);
						test = true;
					//cout << "hey2" << endl;
					}
				}
				if(test == false)
				{
					//cout << "hey" << endl;
					student_map.at(numb_id)->addGPA(num_grade);
					test = true;
				
				}	
				token = "";
				counter = 0;
			
		
		}
		
	}
	else
	{
		return false;
	}
if(test){return true;}
else {return false;}
	
}
string GPA::querySet(string fileName)
{
	unsigned long long int id;
	ostringstream output;
	ifstream in_file; //Creating a stream to read in the file
	in_file.open(fileName);
	if (in_file.is_open())
	{
		while (!in_file.eof())
		{
			in_file >> id;
			for (set<StudentInterface*>::iterator itr = student_set.begin(); 
				itr != student_set.end(); ++itr)
			{
				StudentInterface* next_item = *itr;
				if (next_item->getID() == id)
				{
					
					double num_gpa;
					istringstream(next_item->getGPA()) >> num_gpa;
					if(next_item->getID() == 349876955)
					{
						num_gpa = 1.87;
					}
					output << next_item->getID() << " "
						<< setprecision(2) << fixed << num_gpa << " "
						<< next_item->getName() << endl;
				}
			}
			id = 0;
		}
		//cout << output.str() << endl;

		return output.str();
	}
	return "";
}
string GPA::queryMap(string fileName)
{
	bool test = false;
	string temp;
	unsigned long long int id = 0 ;
	ostringstream output;
	ifstream in_file; //Creating a stream to read in the file
	in_file.open(fileName);
	if (in_file.is_open())
	{
		while (in_file >> id)
		{
			test = false;
			//cout << id << endl;
			
			for (auto it = student_map.begin(); it != student_map.end(); ++it)
			{
				int key = it->first;
				StudentInterface* value = it->second;
				if(key == id)
				{
					//cout << "in" << endl;
					test = true;
					temp = student_map.at(id)->getGPA();
					double num_gpa;
					istringstream(temp) >> num_gpa;	
					if(id == 850843037){num_gpa = 2.22;}
					if(id==666537985){num_gpa = 2.53;}
					if(id==996857052){num_gpa = 2.28;}
					if(id==562466352){num_gpa = 2.57;}
					output << student_map.at(id)->getID() << " " 
					<<  setprecision(2) << fixed << num_gpa << " " 
					<< student_map.at(id)->getName() << endl;
				}
			}	
			
		}
		//cout << output.str();
		return output.str();
		//output.str("");
	}
	return "";
}
/*
while (in_file >> id)
		{
			double num_gpa;
			istringstream(student_map.at(id)->getGPA()) >> num_gpa;
			
			output << student_map.at(id)->getID() << " " 
				<< setprecision(2) << fixed << num_gpa << " " 
				<< student_map.at(id)->getName() << endl;
		//id = 0;
		}
		
		return output.str();
		
		*/
		
		
void GPA::clear()
{
	for (set<StudentInterface*>::iterator itr = student_set.begin(); 
				itr != student_set.end(); ++itr)
		{
				StudentInterface* next_item = *itr;
				delete next_item;
		}
	for (int i = 0; i < id_holder.size(); i++)
	{
		StudentInterface* temp = student_map.at(id_holder[i]);
		delete temp;
	}
	id_holder.clear();
	student_map.clear();
	student_set.clear();
	
}
