//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 5th, 2014
//
 
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

class EvenNum
{
public:
	bool operator()(int num)
	{
		return num % 2 ? false : true;
	}
};

int main(int argc, char *argv[])
{
	ofstream writeOddFile("TestFile_3.4.odd");
	ofstream writeEvenFile("TestFile_3.4.even");
	if (!writeOddFile.is_open() || !writeEvenFile.is_open()) {
		cerr << "Sorry, the file fails to read!" << endl;
		return -1;
	}
	vector<int> vecInput;
	cout << "Please enter some numbers: ";
	istream_iterator<int> inItr(cin), eos;
	copy(inItr, eos, back_inserter(vecInput));
	vector<int>::iterator itr = partition(vecInput.begin(), vecInput.end(), EvenNum());
	ostream_iterator<int> oddItr(writeOddFile, " "), evenItr(writeEvenFile, "\n");
	copy(vecInput.begin(), itr, evenItr);
	copy(itr, vecInput.end(), oddItr);
	return 0;
}