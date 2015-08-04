//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ November 27th, 2014
//
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream readFile("TestFile_1.7.txt");
	if (! readFile.is_open())
		cerr << "Sorry, the file fails to read!" << endl;
	string word;
	vector<string> vecWord;
	while (readFile >> word)
		vecWord.push_back(word);
	cout << "Original text: ";
	for (vector<string>::iterator itr = vecWord.begin(), vecEnd = vecWord.end(); itr != vecEnd; ++itr)
		cout << *itr << " ";
	sort(vecWord.begin(),vecWord.end());
	cout << endl << "Sorted text: ";
	for (vector<string>::iterator itr = vecWord.begin(), vecEnd = vecWord.end(); itr != vecEnd; ++itr)
		cout << *itr << " ";
	return 0;
}