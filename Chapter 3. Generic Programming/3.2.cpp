//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 5th, 2014
//
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LessThan
{
public:
	bool operator()(const string &s1, const string &s2)
	{
		return s1.size() < s2.size();
	}
};

void InitVector(vector<string> &svec, ifstream &ifile)
{
	string word;
	while (ifile >> word)
		svec.push_back(word);
}

void DisplayVector(vector<string> &svec, ofstream &ofile)
{
	int i = 1;
	for (vector<string>::iterator itr = svec.begin(), vecEnd = svec.end(); itr != vecEnd; ++itr)
		ofile << *itr << ((i++ % 5) ? ' ' : '\n');
}

int main(int argc, char *argv[])
{
	ifstream readFile("TestFile_3.2.txt");
	ofstream writeFile("TestFile_3.2.vector");
	if (!readFile.is_open() || !writeFile.is_open()) {
		cerr << "Sorry, the file fails to read!" << endl;
		return -1;
	}
	vector<string> vecWord;
	InitVector(vecWord, readFile);
	sort(vecWord.begin(), vecWord.end(), LessThan());
	DisplayVector(vecWord, writeFile);
	return 0;
}