//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 22nd, 2014
//

#ifndef USERPROFILE_H_
#define USERPROFILE_H_

#include <string>
#include <map>

using namespace std;

class UserProfile
{
public:
	enum userLevel { 
		Beginner, 
		Intermediate, 
		Advanced, 
		Guru
	};
	UserProfile();
	UserProfile(string login, userLevel = Beginner);
	string UserLogin() const
	{
		return userLogin;
	}
	string UserName() const
	{
		return userName;
	}
	int LoginCount() const
	{
		return timesLogged;
	}
	int GuessCount() const
	{
		return timesGuessed;
	}
	int GuessCorrect() const
	{
		return correctGuessed;
	}
	void ResetLogin(const string &val)
	{
		userLogin = val;
	}
	void UserName(const string &val)
	{
		userName = val;
	}
	void ResetLevel(const string &str);
	void ResetLevel(userLevel newLevel)
	{
		nowLevel = newLevel;
	}
	void ResetLoginCount(int val)
	{
		timesLogged = val;
	}
	void ResetGuessCount(int val)
	{
		timesGuessed = val;
	}
	void ResetGuessCorrect(int val)
	{
		correctGuessed = val;
	}
	void BumpLoginCount(int num = 1)
	{
		timesLogged += num;
	}
	void BumpGuessCount(int num = 1)
	{
		timesGuessed += num;
	}
	void BumpGuessCorrect(int num = 1)
	{
		correctGuessed += num;
	}
	bool operator==(const UserProfile &temp);
	bool operator!=(const UserProfile &temp);
	double GuessAverage() const;
	string UserLevel() const;
	
private:
	string userLogin;
	string userName;
	int timesLogged;
	int timesGuessed;
	int correctGuessed;
	userLevel nowLevel;
	static map<string, userLevel> levelMap;
	static void InitLevelMap();
	static string GuestLogin();
};

#endif