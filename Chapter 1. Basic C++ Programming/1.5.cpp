//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ November 26th, 2014
//
 
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string userName;
	cout << "Please enter your name: ";
	cin >> userName;
	if (userName.size() <= 2)
		cout << "Your name is too short!" << endl;
	else
		cout << "Nice name, hello " << userName << "!" << endl;
	return 0;
}