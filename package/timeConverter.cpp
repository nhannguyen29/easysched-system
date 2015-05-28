

/*****
Time Converter, converting the time string of TMS into weekly timeSlot

Duc Le
4/30/2015
Version One

*****/

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#ifndef TIME_CONVERT
#define TIME_CONVERT

vector<int> timeConvert(string day, string hour)
{
	vector<int> time = vector<int>();
	int weekDay;
	
	//convert hour to the time in the day. Each day will be divided into 30-minute slots from 8am to 10pm
	// in this version, we assume that the time is similar for everyday the class meets. 
	// Sample string: 09:30 am - 12:20 pm
	string whichHalfStart = hour.substr(6,2);
	string startHour = hour.substr(0,2);
	string startHalf = hour.substr(3,2);
	string whichHalfEnd = hour.substr(17,2);
	string endHour = hour.substr(11,2);
	string endHalf = hour.substr(14,2);
	
	int start, end, halfHour;
	int baseHour = 0;
	int morningStart = 8;
	int afternoonStart = 0;
	if (whichHalfStart == "pm")
	{
		baseHour = 8;		// number of morning 30-minute slots.
	}
	halfHour = 0;
	int temp;
	stringstream(startHalf) >> temp;
	if (temp >= 30)
		halfHour = 1;
	if (whichHalfStart == "am")
	{
		stringstream(startHour) >> temp;
		start = 2 * (temp - morningStart) + halfHour;
	}
	else if (whichHalfStart == "pm")
	{
		stringstream(startHour) >> temp;
		start = baseHour + 2 * (temp % 12) + halfHour;		// we take the remainder by 12, so that the 12pm will obey the same 
																				// rule as 1pm, 2pm, ...
	}
	
	if (whichHalfEnd == "pm")
	{
		baseHour = 8;		// number of morning 30-minute slots.
	}
	halfHour = 0;
	stringstream(endHalf) >> temp;
	if (temp >= 30)
		halfHour = 1;
	if (whichHalfEnd == "am")
	{
		stringstream(endHour) >> temp;
		end = 2 * (temp - morningStart) + halfHour;
	}
	else if (whichHalfEnd == "pm")
	{
		stringstream(endHour) >> temp;
		end = baseHour + 2 * (temp % 12) + halfHour;		// we take the remainder by 12, so that the 12pm will obey the same 
																				// rule as 1pm, 2pm, ...
	}
	
	//Note: end will indicate the timeSlot at the start of the end hour.
		if (day ==  "M")
			weekDay = 0;
		else if (day == "T")
			weekDay = 1;
		else if (day == "W")
			weekDay = 2;
		else if (day == "R")
			weekDay = 3;
		else if (day == "F")
			weekDay = 4;

	int slotPerday = 16;
	start = start + weekDay * slotPerday;
	end = end + weekDay * slotPerday;
	vector<int> out = vector<int>();
	out.push_back(start);
	out.push_back(end);
	return out;
	
}

vector< vector<int> > convert(string day, string hour)
{
	//the above function deals with single day. this function will take on
	//strings of days ("MTW")
	vector< vector<int> > allDay = vector< vector<int> >();
	if (day == "TBD")
		return allDay;
	vector<int> start = vector<int>();
	vector<int> end = vector<int>();

	// testing purpose
	for (int i = 0; i < day.size(); i++)
	{
	//	cout << "Iterate through day string." << endl;
		string s = day.substr(i,1);
		vector<int> temp = timeConvert(s, hour);
		start.push_back(temp[0]);
		end.push_back(temp[1]);
	}

	/**
	for (int i = 0; i < start.size(); i++)
		cout << start[i] << " ";
	cout << endl;

	for (int i = 0; i < end.size(); i++)
		cout << end[i] << " ";
	cout << endl;
	**/
	
	allDay.push_back(start);
	allDay.push_back(end);

	/** testing purpose
	cout << "allDay size: " << allDay.size() << endl;
	for (int i = 0; i < allDay.size(); i++)
	{
		for (int j = 0; j < allDay[i].size(); j++)
			cout << allDay[i][j] << " ";
		cout << endl;
	}
	**/
	return allDay;
}

/**
int main()
{
	cout << "Start" << endl;
    vector< vector<int> > output = convert("TMW", "09:00 am - 01:00 pm");
    cout << "start at: " << output[0][0] << " " << output[0][1] << " " <<
		 output[0][2] << endl;
	cout << " end at: " << output[1][0] << output[1][1] << output[1][2] << endl;
    return 1;
}
***/
#endif
