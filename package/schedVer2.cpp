/**
  Version 2 of the scheduling algorithm.
  The function will read in vector<instructionType>, grouping elements
  to groups of similar name (MATH200Lecture), then schedule.

  @author: Duc Le
  @date: 5/21/2015
  @Version Two

***/

#include <iostream>
#include <map>
#include <vector>
#include "instructionType.h"
#include "jsonReader.cpp"
using namespace std;

#ifndef SCHEDULING
#define SCHEDULING

//grouping the instructionType into a dictionary with string keys.
map< string, vector<instructionType> > grouping(vector<instructionType> &theList)	
{
	map< string, vector<instructionType> > res = map< string,
		vector<instructionType> >();
	map< string, vector<instructionType> >::iterator it;

	for (int i = 0; i < theList.size(); i++)
	{
		it = res.find(theList[i].getName());
		if (it == res.end())		//the instructionType is not yet in the map.
		{
			vector<instructionType> addNew = vector<instructionType>();
			addNew.push_back(theList[i]);
			res.insert(std::pair<string, vector<instructionType>
					>(theList[i].getName(), addNew));
		}
		else
		{
			//the instructionType already existed, we only add to the vector
			(it -> second).push_back(theList[i]);
		}
	}
	
	return res;
}

/**
  schedule
  @param finalSched is the final output.
  @param courseList is the list of sections we need to schedule
  @param listCRN is the CRN list of the selected sections.
  @param it is the iterator used to traverse through courseList. We will
  call the function with it as courseList.begin()
  @return true and modify the finalSched if we can schedule.
  			false if we cannot successfully schedule for some reason.

***/

bool schedable(vector<string> &finalSched, instructionType &check)
{
	for (int i = 0; i < check.getSize(); i++)
	{
		int start = check.getStart(i);
		int end = check.getEnd(i);
		for (int j = start; j < end; j++)
			if (finalSched[j] != "")		//something there already
				return false;
	}
	//pass all the test
	return true;
}

void putInSchedule(vector<string> &finalSched, vector<string> &listCRN,
		instructionType &check)
{
	for (int i = 0; i < check.getSize(); i++)		//fill the schedule
	{
		int start = check.getStart(i);
		int end = check.getEnd(i);
		for (int j = start; j < end; j++)
			finalSched[j] = check.getName();
		listCRN.push_back(check.getCRN());
        cout << "Increased CRN size: " + check.getCRN() << endl;

	}
}

//remove the trace of removeHim from finalSched and listCRN.
//Note: because cleanUp will be called immediately after schedule,
//we only need to pop_back the CRN, because it is the last added.
void cleanUp(vector<string> &finalSched, vector<string> &listCRN,
		instructionType &check)
{
	cout << "Cleaning up the last added elements." << endl;	
	for (int i = 0; i < check.getSize(); i++)
	{
		int start = check.getStart(i);
		int end = check.getEnd(i);
		for (int j = start; j < end; j++)
			finalSched[j] = "";
        cout << "Reduced CRN size: " << endl;
		listCRN.pop_back();
	}
}

bool schedule(vector<string> &finalSched, vector<string> &listCRN, map< string,
		vector<instructionType> > &courseList, map< string,
		vector<instructionType> >::iterator it)
{
	if (it == courseList.end())
	{
		cout << "We have reached the end." << endl;
		return true;
	}
	cout << "Currently scheduling for: " << it -> first << endl;
	vector<instructionType> list = it -> second;
	for (int i = 0; i < list.size(); i++)
	{
		if (schedable(finalSched, list[i]))
		{
			putInSchedule(finalSched, listCRN, list[i]);  //we can sched this
			it++;
			if (schedule(finalSched, listCRN, courseList, it))
				return true;
			
			//if we reach this point, the current section is impossible to
			//put into finalSched. So we backtrack.
			cleanUp(finalSched, listCRN, list[i]);
			it--;
		}
	}
	return false;
}


/*****
int main()
{
	//test the grouping function
	vector<instructionType> physics = jsonReader("SAS.json", "PHYS102");
	vector<instructionType> chinese = jsonReader("SAS.json", "CHIN101");
	for (int i = 0; i < chinese.size(); i++)
		physics.push_back(chinese[i]);
	vector<instructionType> math = jsonReader("SAS.json", "MATH200");
	for (int i = 0; i < math.size(); i++)
		physics.push_back(math[i]);
	map<string, vector<instructionType> > check = grouping(physics);
	map<string, vector<instructionType> >::iterator it;

	//
	for (it = check.begin(); it != check.end(); ++it)
	{
		cout << it->first << " has " << (it->second).size() << " sections" <<
			endl;
		for (int i = 0; i < (it->second).size(); i++)
		{
			cout << "Section " << i << ": " << endl;
			cout << "\tStart time: ";
			for (int j = 0; j < (it->second)[i].getSize(); j++)
				cout << (it->second)[i].getStart(j) << " ";
			cout << endl << "\tEnd time: ";
			for (int j = 0; j < (it->second)[i].getSize(); j++)
				cout << (it->second)[i].getEnd(j) << " ";
			cout << endl;
		}
	}
	

	vector<string> finalSched (200, "");
	cout << "FinalSched vector OK." << endl;
	vector<string> listCRN = vector<string>();
	cout << "ListCRN OK." << endl;
	it = check.begin();
	cout << "So far so good." << endl;
	bool dummy = schedule(finalSched, listCRN, check, it);
	cout << "Finish scheduling." << endl;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (finalSched[i + 16 * j] == "")
				cout << "1 ";
			else cout << finalSched[i + 16 * j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < 200; i++)
	{
		if (i % 7 == 0)
			cout << endl;
		if (finalSched[i] == "")
			cout << "1 ";
		else
		cout << finalSched[i] << " ";
	}
	
}
**/
#endif
