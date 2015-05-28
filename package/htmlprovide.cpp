#include<string>
#include<fstream>
#include<iostream>
#include<math.h>
#include <vector>
//#include <windows.h>
using namespace std;
int output(const char* fileName)
{
	
	ifstream fin(fileName);
	
	string begin = "<!DOCTYPE html><html><body><table border = \"1\" style = \"width:100%\"><tr><td>Time </td><td>Monday</td><td>Tuesday</td><td>Wednesday</td><td>Thursday</td><td>Friday</td><td>Saturday</td><td>Sunday</td></tr>";
		const string dayName[] = { "<tr><td>08:00 </td >",
		"<td >1 </td >",
		"</tr>" };
	int timehour = 8;//This is used for automatic to change time.
	int halfhour = 0;//This is used for check is this half hourex: 8:30
	int cout = 0;//This is used for check whether it need to be close one row 
	vector< string> s;
	s.push_back(begin);
	string day ;
	string detail ;
	string end1 ;
	string time;
	string dayclass;
	string k = "<tr><td>08:00 am </td >";
	s.push_back(k);
	while (!fin.eof())
	{
		 day = dayName[0];//begin of a row 
		 detail = dayName[1];//blank for class
		 end1 = dayName[2];//end of one row 
		 time = to_string(timehour);
		 if (cout == 7)
		 {
			 cout = 0;
			 if (halfhour == 30)
			 {
				 s.push_back(end1);
				 timehour++;
				 if (timehour > 12)
				 {
					 int newhour = timehour - 12;
					 if (newhour >= 10)

					 {
						 time = to_string(newhour) + ":00 pm";
					 }
					 else{
						 time = "0" + to_string(newhour) + ":00 pm";
					 }
					 day = day.replace(8, 5, time);
					 
				 }
				 else
				 {
					 if (timehour >= 10)

					 {
						 time = to_string(timehour) + ":00 am";
					 }
					 else{
						 time = "0" + to_string(timehour) + ":00 am";
					 }
					
				 day = day.replace(8, 5, time);//"<tr><td>08:00  am</td >"
			 }
				 s.push_back(day);
				 halfhour = 0;
				 cout = 0;
			 }
			 else
			 {
				
				 s.push_back(end1);
				
				 if (timehour > 12)
				 {
					 int newhour = timehour - 12;
					 if (newhour >= 10)

					 {
						 time =  to_string(newhour) + ":00 pm";
					 }
					 else{
						 time = "0" + to_string(newhour) + ":00 pm";
					 }
					 day = day.replace(8, 5, time);
					 day = day.replace(11, 2, "30");
				 }
				 else
				 {
					 if (timehour >= 10)

					 {
						 time = to_string(timehour) + ":00 am";
					 }
					 else{
						 time = "0" + to_string(timehour) + ":00 am";
					 }
					
					 day = day.replace(8, 5, time);
					 day = day.replace(11, 2, "30");
				 }
				 halfhour = 30;
				 cout = 0;
				 s.push_back(day);
			 }
			 
		 }
		
		fin >> dayclass;
		if (dayclass == "0")
		{
			dayclass = " ";
		}
		detail.replace(5,1, dayclass);//"<td>1 </td >",
		s.push_back(detail);
		cout++;

	}
	/*for (unsigned int i = 0; i < s.size()-7; i++)
	{
		int cout = 1;
		if (s[i] == "</tr>" || s[i] == " </td >" || s[i] == begin )
		{ }
		else
		{
			for (unsigned int k = i + 10; k < s.size() - 7; k = k + 10)

			{
				if (s[i] == s[k])
				{
					cout++;
					s.erase(s.begin() + k);
				}

			}
			string number = to_string(cout);
			s[i].replace(4, 1, " rowspan='" + number + "'>");
		}
	}*/
	string end = "</table></body></html>";//end of html file 
	s.push_back(end);
	ofstream file("sched.html");
	for (unsigned int i = 0; i < s.size(); i++)
	{
		file << s[i] << endl;
	}
	file.close();
	//This is used to let c++ open html file.
	//LPCTSTR helpFile = "help\helpFile.html";
	//ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
	//system("PAUSE");
	return 0;
}
