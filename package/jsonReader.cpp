/**
The json reader methond, designed to read the json files generated 
from the TMS page using crawling algorithm

@author Duc Le
@date 5/19/2015

*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "instructionType.h"
#include "timeConverter.cpp"
using namespace std;

#ifndef JSON_READER
#define JSON_READER
//read the fileName, construct instructionType objects and push
//those that has the satisfied lookUp to the vector.
//The function will read the jsonFile, then:
// 	if no instructionType object of the same code (MATH200Lecture) has
// 	been created, we will create a new one and push to the vector
//		if an instructionType already existed, we will modify it.
vector<instructionType> jsonReader(const char* fileName, string lookUp)
{
	//vector<instructionType> res();
	std::ifstream ifs(fileName, std::ifstream::in);
	for (int i = 0; i < 19; i++)
	{
		string s;
		getline(ifs, s, ',');
		//cout << s << endl;
	}
	string courseNum, day, instructor, method, section, subject, time, title,
			 type;
	string CRN, s;

	bool sameName = false;
	bool getAllSect = false;

	vector<instructionType> res = vector<instructionType>();

	while(!getAllSect && ifs)					//not found all of them and still
	  													// things	to	read
	{
	//cout << "Enter another while loop." << endl;
		// read to the end of file
		getline(ifs, s, ',');		//strip off the CRN href links
		getline(ifs, s, ',');		//"text": "32399"
		CRN = s.substr(8, 5);
		getline(ifs, s, ',');		//"Course Number: "100"
		courseNum = s.substr(17, 3);
		getline(ifs, s, ',');		//"Day": "TR"
		day = s.substr(7, s.size() - 8);

		getline(ifs, s, '\"');
//		cout << s << endl;
		getline(ifs, s, '\"');
//		cout << s << endl;
		getline(ifs, s, '\"');
//		cout << s << endl;
		getline(ifs, s, '\"');
//		cout << s << endl;
		instructor = s;
		getline(ifs, s, ',');
		/**
		vector<string> instr = vector<string>();
		if (s.find(',') < 0)			//only 1 instructor
			instr.push_back(s);
		else 
		{
			istringstream ss(s);
			string token;
			while(getline(ss, token, ','))
				instr.push_back(token);
		}
		//getline(ifs, s, delim);		//"Instructor": "some one"
		//instructor = s.substr(14, s.size() - 14);
**/

		getline(ifs, s, ',');		//"Method": "Face to Face"
		method = s.substr(10, s.size() - 11);
		getline(ifs, s, ',');		//"Section": "001"
		section = s.substr(11, s.size() - 12);
		getline(ifs, s, ',');		//"Subject Code": "MATH"
		subject = s.substr(16, s.size() - 17);

		//string check = subject + courseNum;

		getline(ifs, s, ',');		//"Time": "..."
		time = s.substr(8, s.size() - 9);

 		getline(ifs, s, '\"');
 //    cout << s << endl;
       getline(ifs, s, '\"');
		 //    cout << s << endl;
		 getline(ifs, s, '\"');
				 //    cout << s << endl;
		getline(ifs, s, '\"');
						 //    cout << s << endl;
		title = s;
		getline(ifs, s, ',');

		//getline(ifs, s, ',');		//"Title": "..."
		//title = s.substr(9, s.size() - 10);
		getline(ifs, s, ',');
		type = s.substr(8, s.size() - 10);

/**		
 cout << "CRN: " << CRN << endl << "Course Number: " << courseNum << endl <<
	 "Day: " << day << endl;
      cout << "Instructor: " << instructor << endl << "Instruction Method: "
			<< method << endl << "Section: " << section << endl;
	        cout << "Subject: " << subject << endl << "Time: " << time <<
				  endl <<"Title: " <<  title << endl << "Type: " << type
				  << endl;
		      cout << endl;
	**/	

		string check = subject + courseNum;
		if (day == "TBD" || time == "TBD")		//unprovided time
			continue;
//		cout << check << " ";
		if (check != lookUp)
		{
	//		cout << "Current Course is: " << check << " so we skipped." <<
	//			endl;
			if (sameName)		//we are on the sameName area, but this is where
									//we should stop.
			{
	//			cout << "Reach the end of the lookUp course, stop reading." <<
	//				endl;
				break;
			}
			continue;
		}
	//	cout << "Continue after we stopped." << endl;

		cout << "Ha! Caught One!" << endl;
		check = check + type;
		sameName = true;			//we have found the treasure.
		//finish reading in, now we construct the instructionType object.
		vector< vector<int> > converted = convert(day, time);
	/***
		cout << "day is: " << day << endl;
		cout << "time is: " << time << endl;

		cout << "Converted the time: " << endl;
		for (int i = 0; i < converted[0].size(); i++)
			cout << converted[0][i] << " ";
		cout << endl;
		for (int i = 0; i < converted[1].size(); i++)
			cout << converted[1][i] << " ";
		cout << endl;
***/
		//vector<string> listCRN = vector<string>();
		//listCRN.push_back(CRN);

		//cout << "Add the CRN string." << endl;

		//vector<string> instr = vector<string>();
		//instr.push_back(instructor);

		//cout << "Add the instructor string." << endl;

		instructionType addNew = instructionType(check, converted[0], converted[1], CRN, instructor, title);

		//cout << "Complete constructing, start pusing to vector." << endl;
		res.push_back(addNew);
		/***
		if (res.size() == 0)				//empty list
		{
			cout << "Empty list, add: " << check << " to the beginning." <<
				endl;
			res.push_back(addNew);
			cout << "Push successfully" << endl;
		}
		else
		for (int i = 0; i < res.size(); i++)
		{
			cout << "Enter the searching loop." << endl;
			if (res[i].merge(addNew))			//found a brother
			{
				cout << "List is not empty, but a brother is found." << endl;
				break;
			}
			//now, the instructionType has not existed inside the list.
			if (i == res.size() - 1)		//reach the end of list.
			{
				cout << "Non-empty list, brother not found, add new to the end."
					<< endl;
				res.push_back(addNew);
			}
		}
		**/
		
		/**
		cout << CRN << endl << courseNum << endl << day << endl;
		cout << instructor << endl << method << endl << section << endl;
		cout << subject << endl << time << endl << title << endl << type <<
			endl;
		cout << endl;
		**/
	//	break;
		
		//return res;
	}
	return res;
}

#include <time.h>

/***
int main()
{
	clock_t t1, t2;
	t1 = clock();
	vector<instructionType> check = jsonReader("SAS.json", "PHYS102");
	t2 = clock();
	cout << "Finish parsing function, check size is: " << check.size() <<
		endl;
	for (int i = 0; i < check.size(); i++)
	{
		cout << "InstructionType: " << check[i].getName() << endl;
		cout << "Title: " << check[i].getTitle() << endl;
		cout << "Start time list: " << endl;
		for (int j = 0; j < check[i].getSize(); j++)
			cout << check[j].getStart(j) << " ";
		cout << endl << "End time list: " << endl;
		for (int j = 0; j < check[i].getSize(); j++)
			cout << check[j].getEnd(j) << " ";
	  cout << endl << "CRN List: " << endl;
  		//for (int j = 0; j < check[i].getSize(); j++)
	 		cout << check[i].getCRN()	<< " ";
		//cout << endl << "Instructor List: " << endl;
		//for (int j = 0; j < check[i].getSize(); j++)
			cout << check[i].getInstructor() << " ";
		cout << endl;	
	}
	float diff = ((float)t2 - (float)t1);
	cout << "Running time: " << diff / CLOCKS_PER_SEC << endl;
	return 0;
}
***/

#endif
