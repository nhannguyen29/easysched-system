//--------------------------------------------------
// Nguyen Nhat Anh
// This is a file that includes the function used to 
// acquire the name of the json file that stores the
// necessary data
//--------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#ifndef GET_FILE
#define GET_FILE
string get_json_file_name( string & subject)
{
	string college;
	string json_name;
	int college_ID;
	if (( subject == "ADGD") ||
		( subject == "ANIM") ||
		( subject == "ARCH") ||
		( subject == "ARTH") ||
		( subject == "AADM") ||
		( subject == "DANC") ||
		( subject == "DSMR") ||
		( subject == "DIGM") ||
		( subject == "EAM") ||
		( subject == "EVGD") ||
		( subject == "FASH") ||
		( subject == "FMVD") ||
		( subject == "FMST") ||
		( subject == "GMAP") ||
		( subject == "VSCM") ||
		( subject == "INTR") ||
		( subject == "MUSL") ||
		( subject == "MUSC") ||
		( subject == "MIP") ||
		( subject == "PHTO") ||
		( subject == "PTM") ||
		( subject == "PROD") ||
		( subject == "RETL") ||
		( subject == "SCRP") ||
		( subject == "SAPA") ||
		( subject == "TVIE") ||
		( subject == "TVIT") ||
		( subject == "TVPR") ||
		( subject == "TVST") ||
		( subject == "TVMN") ||
		( subject == "THTR") ||
		( subject == "VSST") ||
		( subject == "WEST") ||
		( subject == "WMGD") ||
		( subject == "WBDV"))
		{ college = "Antoinette Westphal COMAD"; json_name = "SA.json";}
	else if (( subject == "AFAS") ||
		( subject == "ANTH") ||
		( subject == "ARBC") ||
		( subject == "AS-I") ||
		( subject == "BIO") ||
		( subject == "CHEC") ||
		( subject == "CHEM") ||
		( subject == "CHIN") ||
		( subject == "COM") ||
		( subject == "CJ" ) ||
		( subject == "CJS") ||
		( subject == "ENGL") ||
		( subject == "ESL") ||
		( subject == "ENVP") ||
		( subject == "ENVS") ||
		( subject == "ENSS") ||
		( subject == "FREN") ||
		( subject == "GEO") ||
		( subject == "GER") ||
		( subject == "GREC") ||
		( subject == "HBRW") ||
		( subject == "HIST") ||
		( subject == "HUM") ||
		( subject == "IAS") ||
		( subject == "IST") ||
		( subject == "AS-A") ||
		( subject == "ITAL") ||
		( subject == "JAPN") ||
		( subject == "JUDA") ||
		( subject == "KOR") ||
		( subject == "LANG") ||
		( subject == "LING") ||
		( subject == "MATH") ||
		( subject == "PHIL") ||
		( subject == "PHYS") ||
		( subject == "PHEV") ||
		( subject == "PSCI") ||
		( subject == "PORT") ||
		( subject == "PSY") ||
		( subject == "PLCY") ||
		( subject == "PMGT") ||
		( subject == "RUSS") ||
		( subject == "SOC") ||
		( subject == "SPAN") ||
		( subject == "WMST") ||
		( subject == "WRIT")) 
		{ college = "Arts and Sciences"; json_name = "SAS.json"; college_ID = 1;}
	else if (( subject == "ACCT") ||
		( subject == "STAT") ||
		( subject == "ECON") ||
		( subject == "FIN") ||
		( subject == "BUSN") ||
		( subject == "HRMT") ||
		( subject == "INTB") ||
		( subject == "BLAW") ||
		( subject == "MGMT") ||
		( subject == "MIS") ||
		( subject == "MKTG") ||
		( subject == "OPM") ||
		( subject == "OPR") ||
		( subject == "ORGB") ||
		( subject == "TAX") ||
		( subject == "POM"))
		{ college = "Bennett S. LeBow College of Business"; json_name = "SB.json"; college_ID = 2;}
	else if ( subject == "CIVC" ) // done
		{ college = "Center for Civic Engagement"; json_name = "SCV.json"; college_ID = 3;}
	else if ( subject == "ENTP" ) // done
		{ college = "Close School of Entrepreneurship"; json_name = "SC.json"; college_ID = 4;}
	else if (( subject == "CS") ||
		( subject == "CT") ||
		( subject == "CI") ||
		( subject == "CST") ||
		( subject == "EMS") ||
		( subject == "EMER") ||
		( subject == "HSM") ||
		( subject == "INFO") ||
		( subject == "SE"))
		{ college = "College of Computing & Informatics"; json_name = "SCI.json"; college_ID = 5;}
	else if (( subject ==  "AE") || 
		( subject ==  "BET") ||
		( subject ==  "CHE") ||
		( subject ==  "CAE") ||
		( subject ==  "CIVE") ||
		( subject ==  "CAEE") ||
		( subject ==  "CMGT") ||
		( subject ==  "ECEC") ||
		( subject ==  "ECEE") ||
		( subject ==  "ECEP") ||
		( subject ==  "ECES") ||
		( subject ==  "ECE") ||
		( subject ==  "ECEL") ||
		( subject ==  "ECET") ||
		( subject ==  "EET") ||
		( subject ==  "EGEO") ||
		( subject ==  "EGMT") ||
		( subject ==  "ET") ||
		( subject ==  "ENGR") ||
		( subject ==  "ENVE") ||
		( subject ==  "INDE") ||
		( subject ==  "MET") ||
		( subject ==  "MATE") ||
		( subject ==  "MEM") ||
		( subject ==  "MHT") ||
		( subject ==  "PROJ") ||
		( subject ==  "PRMT") ||
		( subject ==  "REAL") ||
		( subject ==  "SYSE")) // done
		{ college = "College of Engineering"; json_name = "SE.json"; college_ID = 6; }
	else if (( subject ==  "CULA") || 
		( subject ==  "FDSC") ||
		( subject ==  "HRM") ||
		( subject ==  "SMT")) // done
		{ college = "Hospitality & Sport Management"; json_name = "SSH.json"; college_ID = 7;}
	else if (( subject ==  "CIE") ||
		( subject ==  "EXAM") ||
		( subject ==  "MLSC"))
		{ college = "Miscellaneous"; json_name = "SX.json"; college_ID = 8;}
	else if (( subject ==  "ANAT") ||
		( subject ==  "ARTS") ||
		( subject ==  "BACS") ||
		( subject ==  "CVPT") ||
		( subject ==  "CIT") ||
		( subject ==  "CFTP") ||
		( subject ==  "HSCI") ||
		( subject ==  "HSAD") ||
		( subject ==  "HLSO") ||
		( subject ==  "ICVT") ||
		( subject ==  "IPS") ||
		( subject ==  "MBC") ||
		( subject ==  "MFTP") ||
		( subject ==  "NEUR") ||
		( subject ==  "NURS") ||
		( subject ==  "NHP") ||
		( subject ==  "NFS") ||
		( subject ==  "PA") ||
		( subject ==  "PHGY") ||
		( subject ==  "PTRS") ||
		( subject ==  "RADI") ||
		( subject ==  "RHAB") ||
		( subject ==  "RSCH") ||
		( subject ==  "STS")) // done
		{ college = "Nursing & Health Professions"; json_name = "SNH.json"; college_ID = 9;}
	else if (( subject ==  "CSDN") || 
		( subject ==  "UNIV") ||
		( subject ==  "HNRS") ||
		( subject ==  "LEAD"))
		{ college = "Pennoni Honors College"; json_name = "SPE.json"; college_ID = 10;} 
	else if ( subject ==  "BMES")
		{ college = "School of Biomedical Engineering, Sciences & Health"; json_name = "SR.json"; college_ID = 11;}
	else if (( subject ==  "CRTV") || 
		( subject ==  "ELL") ||
		( subject ==  "EDGI") ||
		( subject ==  "EDGE") ||
		( subject ==  "EHRD") ||
		( subject ==  "EDLT") ||
		( subject ==  "EDAM") ||
		( subject ==  "EDAE") ||
		( subject ==  "EIT") ||
		( subject ==  "EDLS") ||
		( subject ==  "EDPO") ||
		( subject ==  "EDHE") ||
		( subject ==  "MTED") ||
		( subject ==  "MUSM") ||
		( subject ==  "ESTM") ||
		( subject ==  "EDEX") ||
		( subject ==  "EDUC"))
		{ college = "School of Education"; json_name = "ST.json"; college_ID = 12;}
	else if ( subject ==  "PBHL")
		{ college = "School of Public Health"; json_name = "SPH.json"; college_ID = 13;}
	else if (( subject ==  "CAT") || 
		( subject ==  "CUST") ||
		( subject ==  "GSTD") ||
		( subject ==  "PRST"))
		{ college = "Goodwin School of Technology & Prof Studies"; json_name = "SG.json"; college_ID = 14;}
	return json_name;
}

vector<string> json_files( vector<string> & subjects)
{
	vector<string> result( subjects.size());
	for( int i = 0; i < subjects.size(); i++)
	{
		result[i] = get_json_file_name( subjects[i]);
	}
	
	return result;
}

/******
int main()
{
	vector<string> test(5);
	test[0] = "MATH";
	test[1] = "DIGM";
	test[2] = "CHIN";
	test[3] = "ENGR";
	test[4] = "ECON";
	
	vector<string> result;
	result = json_files( test);
	for (int i=0; i<result.size(); i++)
	{
		cout << result[i] << endl;
	}
	
	return 0;
}
***/
#endif
