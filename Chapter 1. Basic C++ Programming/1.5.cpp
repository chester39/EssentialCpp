/**************************************************
 *              Essential C++                     *
 *                Stanley Lippman                 *
 *                Chen Chen @ November 27th, 2014 *
 **************************************************/
 
 
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string username;
	cout << "Please enter your name: ";
	cin >> username;
	if (username.size() <= 2)
	{
		cout << "Your name is too short!" << endl;
	}
	else
	{
		cout << "Nice name, hello " << username << "!" << endl;
	}
	return 0;
}
