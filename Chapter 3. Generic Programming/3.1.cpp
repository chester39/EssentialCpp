//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 5th, 2014
//
 
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

void InitExclusionSet(set<string> &sset)
{
	string exclusionWord[10] = { "a", "an", "or", "the", "and", "but", "to", "you", "I", "of" };
	sset.insert(exclusionWord, exclusionWord + 10);
}

void ProcessFile(map<string, int> &simap, const set<string> &sset, ifstream &ifile)
{
	string word;
	while (ifile >> word) {
		if (sset.count(word))
			continue;
		simap[word]++;
	}
}

void UserQuery(map<string, int> &simap)
{
	string queryWord;
	cout << "Please enter the word you want to query: ";
	cin >> queryWord;
	int i = 0;
	for (map<string, int>::iterator itr = simap.begin(), mapEnd = simap.end(); itr != mapEnd; ++itr) {
		i++;
		if (itr->first == queryWord) {
			cout << "The word " << itr->first << " has appeared " << itr->second << " times." << endl;
			break;
		}
	}
	if (i >= simap.size())
		cout << "Sorry, the word " << queryWord << " is not found." << endl;
}

void DisplayWordCount(map<string, int> &simap, ofstream &ofile)
{
	for (map<string, int>::iterator itr = simap.begin(), mapEnd = simap.end(); itr != mapEnd; ++itr)
		ofile << itr->first << "-" << itr->second << endl;
}

int main(int argc, char *argv[])
{
	ifstream readFile("TestFile_3.1.txt");
	ofstream writeFile("TestFile_3.1.map");
	if (!readFile.is_open() || !writeFile.is_open()) {
		cerr << "Sorry, the file fails to read!" << endl;
		return -1;
	}
	map<string, int> mapWord;
	set<string> setExclusion;
	InitExclusionSet(setExclusion);
	ProcessFile(mapWord, setExclusion, readFile);
	UserQuery(mapWord);
	DisplayWordCount(mapWord, writeFile);
	return 0;
}