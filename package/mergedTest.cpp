/**
  The functioning merged program, from start to finish
@author Duc Le
@version one
@date 5/25/2015

*/
#include <map>
#include <fstream>
#include <vector>
#include "instructionType.cpp"
#include "schedVer2.cpp"
#include "jsonReader.cpp"
#include "get_json_file.cpp"
#include "htmlprovide.cpp"
using namespace std;

int main()
{
	const char* testFile = "testInput";	//contains the name of the 5 courses
	std::ifstream readFile(testFile);
	string line;
	vector<string> courseList;
	vector<string> subjectCode;
	while(getline(readFile, line))
	{
		int check = line.find(" ");
		string subject = line.substr(0, check);
		string courseCode = line.substr(0, check) + line.substr(check + 1);
		courseList.push_back(courseCode);
		subjectCode.push_back(subject);
	}
	vector<string> fileList = json_files(subjectCode);

	vector<instructionType> allCourse = vector<instructionType>();
	for (int i = 0; i < fileList.size(); i++)
	{
		const char* temp = fileList[i].c_str();
		vector<instructionType> section = jsonReader(temp,
				courseList[i]);
		for (int j = 0; j < section.size(); j++)
			allCourse.push_back(section[j]);
	}
	
	vector<string> finalSched(200, "");
	vector<string> listCRN = vector<string>();
	map<string, vector<instructionType> > check = grouping(allCourse);
	map<string, vector<instructionType> >::iterator it;
	it = check.begin();
	bool dummy = schedule(finalSched, listCRN, check, it);
	cout << "The needed CRN are: " << endl;
	for (int i = 0; i < listCRN.size(); i++)
		cout << listCRN[i] << " ";
	cout << endl;
  
 	cout << "The actual schedule: " << endl;
	ofstream myfile;
	myfile.open("temp.txt");
	 for (int i = 0; i < 16; i++)
 	 {
		 for (int j = 0; j < 7; j++)
		 {
			 if (finalSched[i + 16 * j] == "")
				 myfile << "0" << endl;
			 else  myfile << finalSched[i + 16 * j] << endl;
	    }
	//cout << endl;
	}
	int dum = output("temp.txt");
	cout << endl;
	return 0;
	
}
