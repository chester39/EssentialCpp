//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 7th, 2014
//

#ifndef GLOBALDATA_H_
#define GLOBALDATA_H_

#include <string>

using namespace std;

class GlobalData
{
public:
	GlobalData();
	~GlobalData();
	static string ProgramName()
	{
		return program_name;
	}
	static string VersionStamp()
	{
		return version_stamp;
	}
	static int VersionNumber()
	{
		return version_number;
	}
	static int TestsRun()
	{
		return tests_run;
	}
	static int TestsPassed()
	{
		return tests_passed;
	}
	static void ProgramName(const string &strName)
	{
		program_name = strName;
	}
	static void VersionStamp(const string &strStamp)
	{
		version_stamp = strStamp;
	}
	static void VersionNumber(const int &intNumber)
	{
		version_number = intNumber;
	}
	static void TestsRun(const int &intRun)
	{
		tests_run = intRun;
	}
	static void TestsPassed(const int &intPassed)
	{
		tests_passed = intPassed;
	}

private:
	static string program_name;
	static string version_stamp;
	static int version_number;
	static int tests_run;
	static int tests_passed;
};

string GlobalData::program_name;
string GlobalData::version_stamp;
int GlobalData::version_number;
int GlobalData::tests_run;
int GlobalData::tests_passed;

#endif