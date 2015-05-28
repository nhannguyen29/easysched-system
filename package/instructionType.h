/**
This script holds the information about the instructionType objects (helper objects for the scheduling algorithm)

Duc Le
5/1/2015
Version One

**/

#include <vector>
#include <iostream>
using namespace std;

#ifndef _instr_
#define _instr_

//class Course;
class instructionType
{
	private:
		string name; //CS265Lab, CS265Lecture, ...
		vector<int> startTime;
		vector<int> endTime;
		string CRN;
		string instructor;
		string title;
		//Course* original;    //pointer to the original course object, which contains more miscellanous information (department, ...)
	public:
		//Constructor
		instructionType();
		instructionType(const instructionType & mirror);
		instructionType(string theName, vector<int> &start, vector<int> &end,
				string CRN, string instructor, string title);	
		instructionType(string jsonFile, string targetClass);		//read the json file extracted from the TMS and construct		
		//Inspector
		string getName() const;
		int getSize() const;			//return the number of available sections in the object.
		int getStart(int index) const; 	//inspect the time vectors
		int getEnd(int index) const;
		string getCRN() const;
		string getInstructor() const;
		string getTitle() const;
				
		//Mutator
		void addStartTime(int x);
		void addEndTime(int y);
		void addCRN(string s);
		void addInstructor(string s);
//		bool merge(instructionType &brother);	//add 2 instructionType of the
															//same name, but different 
															//start and end time vectors.

		//Destructor
		~instructionType();
		
};

#endif
