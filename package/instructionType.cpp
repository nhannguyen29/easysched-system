/**
This script holds the information about the instructionType objects (helper objects for the scheduling algorithm)

Duc Le
5/1/2015
Version One

**/

#include <vector>
#include <iostream>
#include "instructionType.h"
//#include "Course.h"
using namespace std;

/**
  string name; //CS265Lab, CS265Lecture, ...
        vector<int> startTime;
		        vector<int> endTime;
				        vector<string> CRN;
						  `	vector<string> instructor;
						        string title;
*/

class Course;

instructionType::instructionType()
{
	name = "";
	startTime = vector<int>();
	endTime = vector<int>();
	CRN = "";
	instructor = "";
	title = "";
//	original = NULL;
}

instructionType::instructionType(const instructionType &mirror)
{
	name = mirror.name;
	startTime = mirror.startTime;
	endTime = mirror.endTime;
	CRN = mirror.CRN;
//	original = mirror.original;
	instructor = mirror.instructor;
	title = mirror.title;
}

/**
instructionType::instructionType(int index, Course *mother)
{
	name = mother -> getCourseCode() + mother -> getInstrType(index);
	vector< vector<int> > time = mother -> getTimeList(mother ->
			getInstrType(index));
	startTime = time[0];
	endTime = time[1];
	CRN = mother -> getListCRN(index);
	original = mother;
}
*/

instructionType::instructionType(string theName, vector<int> &start,
		vector<int> &end, string listCRN, string instr,
		string courseName)
{
	name = theName;
	startTime = start;
	endTime = end;
	CRN = listCRN;
	title = courseName;
	//original = mother;
	instructor = instr;
}


int instructionType::getSize() const
{
	return startTime.size();
}

string instructionType::getTitle() const
{
	return title;
}

string instructionType::getInstructor() const
{
	return instructor;
}

string instructionType::getName() const
{
	return name;
}

int instructionType::getStart(int index) const
{
	return startTime[index];
}

int instructionType::getEnd(int index) const
{
	return endTime[index];
}

string instructionType::getCRN() const
{
	return CRN;
}

/***
Course* instructionType::getMaster() const
{
	return original;
}
*/

void instructionType::addStartTime(int x)
{
	startTime.push_back(x);
}

void instructionType::addEndTime(int x)
{
	endTime.push_back(x);
}

void instructionType::addCRN(string x)
{
	CRN = x;
}

void instructionType::addInstructor(string x)
{
	instructor = x;
}

/**
bool instructionType::merge(instructionType &brother)
{
	if (name != brother.getName())		//not a brother
		return false;
	for (int i = 0; i < brother.getSize(); i++)
	{
		addStartTime(brother.getStart(i));
		addEndTime(brother.getEnd(i));
		addCRN(brother.getCRN(i));
		addInstructor(brother.getInstructor(i));
	}
	return true;
}
**/


instructionType::~instructionType()
{
//	original = NULL;
}
//int main()
//{
//	return 0;
//}

