//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ November 26th, 2014
//
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	vector<string> vecName(2);
	cout << "Please enter your first name: ";
	cin >> vecName[0];
	cout << "Please enter your last name: ";
	cin >> vecName[1];
	for (vector<string>::iterator itr = vecName.begin(), vecEnd = vecName.end(); itr != vecEnd; ++itr)
		cout << *itr << " ";
	return 0;
}