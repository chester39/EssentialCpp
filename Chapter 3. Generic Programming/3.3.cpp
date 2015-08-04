//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 5th, 2014
//
 
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void InitMap(map<string, vector<string> > &svmap, ifstream &ifile)
{
	string textline;
	while (getline(ifile, textline, '\n')) {
		string familyName;
		vector<string> child;
		string::size_type nowPos = 0, prevPos = 0, textSize = textline.size();
		if (!textSize)
			continue;
		while ((nowPos = textline.find_first_of(' ', nowPos)) != string::npos) {
			string::size_type endPos = nowPos - prevPos;
			if (!prevPos)
				familyName = textline.substr(prevPos, endPos);
			else
				child.push_back(textline.substr(prevPos, endPos));
			prevPos = ++nowPos;
		}
		if (prevPos < textSize)
			child.push_back(textline.substr(prevPos, nowPos - prevPos));
		if (!svmap.count(familyName))
			svmap[familyName] = child;
		else
			cerr << "Sorry, we already have a "<< familyName << " family in our map!\n";
	}
}

void DisplayMap(map<string, vector<string> > &svmap, ofstream &ofile)
{
	for (map<string, vector<string> >::iterator itr = svmap.begin(), mapEnd = svmap.end(); itr != mapEnd; ++itr) {
		ofile << "The " << itr->first << " family ";
		if (itr->second.empty())
			ofile << "has no children." << endl;
		else {
			ofile << "has " << itr->second.size() << " children: ";
			for (vector<string>::iterator itrvec = itr->second.begin(), vecEnd = itr->second.end(); itrvec != vecEnd; ++itrvec)
				ofile << *itrvec << " ";
			ofile << endl;
		}
	}
}

void UserQuery(map<string, vector<string> > &svmap)
{
	string queryName;
	cout << "Please enter a family name you want to query: ";
	cin >> queryName;
	int i = 0;
	for (map<string, vector<string> >::iterator itr = svmap.begin(), mapEnd = svmap.end(); itr != mapEnd; ++itr) {
		i++;
		if (itr->first == queryName) {
			cout << "The " << itr->first << " family has " << itr->second.size() << " children: ";
			for (vector<string>::iterator itrvec = itr->second.begin(), vecEnd = itr->second.end(); itrvec != vecEnd; ++itrvec)
				cout << *itrvec << " ";
			break;
		}
	}
	if (i >= svmap.size())
		cout << "Sorry, the " << queryName << " family is not found." << endl;
}

int main(int argc, char *argv[])
{
	ifstream readFile("TestFile_3.3.txt");
	ofstream writeFile("TestFile_3.3.map");
	if (!readFile.is_open() || !writeFile.is_open()) {
		cerr << "Sorry, the file fails to read!" << endl;
		return -1;
	}
	map<string, vector<string> > mapFamily;
	InitMap(mapFamily, readFile);
	DisplayMap(mapFamily, writeFile);
	UserQuery(mapFamily);
	return 0;
}