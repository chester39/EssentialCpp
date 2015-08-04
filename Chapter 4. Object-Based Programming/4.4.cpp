//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 22nd, 2014
//
 
#include <iostream>
#include <cstdlib>
#include "UserProfile.h"

using namespace std;

inline UserProfile::UserProfile() : userLogin("guest"), nowLevel(Beginner), timesLogged(1), timesGuessed(0), correctGuessed(0)
{
	static int id = 0;
	char buffer[16];
	_itoa(id++, buffer, 10);
	userLogin += buffer;
}

inline UserProfile::UserProfile(string login, userLevel level) : userLogin(login), nowLevel(level), timesLogged(1), timesGuessed(0), correctGuessed(0) {}

inline bool UserProfile::operator==(const UserProfile &temp)
{
	if (userLogin == temp.userLogin && userName == temp.userName)
		return true;
	else
		return false;
}

inline bool UserProfile::operator!=(const UserProfile &temp)
{
	return !(*this == temp);
}

inline double UserProfile::GuessAverage() const
{
	return timesGuessed ? (double)correctGuessed / (double)timesGuessed * 100 : 0.0;
}

inline string UserProfile::UserLevel() const
{
	static string levelTable[] = { 
		"Beginner", 
		"Intermediate", 
		"Advanced", 
		"Guru" 
	};
	return levelTable[nowLevel];
}

map<string, UserProfile::userLevel> UserProfile::levelMap;

ostream &operator<<(ostream &os, const UserProfile &rhs)
{
	os << "Username: " << rhs.UserLogin() << endl
		<< "User Level: " << rhs.UserLevel() << endl
		<< "User Login Times: " << rhs.LoginCount() << endl
		<< "User Guess Times: " << rhs.GuessCount() << endl
		<< "User Correct Guess: " << rhs.GuessCorrect() << endl
		<< "User Guess Average: " << rhs.GuessAverage() << endl;
	return os;
}

inline void UserProfile::ResetLevel(const string &level)
{
	if (levelMap.empty())
		InitLevelMap();
	map<string, userLevel>::iterator itr;
	nowLevel = ((itr = levelMap.find(level)) != levelMap.end()) ? itr->second : Beginner;
}
void UserProfile::InitLevelMap()
{
	levelMap["Beginner"] = Beginner;
	levelMap["Intermediate"] = Intermediate;
	levelMap["Advanced"] = Advanced;
	levelMap["Guru"] = Guru;
}

istream &operator>>(istream &is, UserProfile &rhs)
{
	string login, level;
	is >> login >> level;
	int lcount, gcount, gcorrect;
	is >> lcount >> gcount >> gcorrect;
	rhs.ResetLogin(login);
	rhs.ResetLevel(level);
	rhs.ResetLoginCount(lcount);
	rhs.ResetGuessCount(gcount);
	rhs.ResetGuessCorrect(gcorrect);
	return is;
}

int main(int argc, char *argv[])
{
	UserProfile newMan;
	cout << newMan;
	UserProfile anotherMan;
	cout << anotherMan;
	UserProfile otherMan("ChesterC", UserProfile::Guru);
	cout << otherMan;
	otherMan.BumpGuessCount(27);
	otherMan.BumpGuessCorrect(25);
	otherMan.BumpLoginCount();
	cout << otherMan;
	cout << "Please enter user profile data to see if we can read it\n";
	cin >> newMan;
	cout << newMan;
	return 0;
}