//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ November 30th, 2014
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool JudgeElem(const vector<int> &ivec, int pos)
{
	if (pos <= 0 || pos > 100) {
		cerr << "Wrong position! ";
		return false;
	}
	return true;
}

void PentaElem(vector<int> &ivec, int pos)
{
	for (int ix = 1; ix <= pos; ++ix)
		ivec.push_back(ix * (3 * ix - 1) / 2);
}

void DisplayElem(const vector<int> &ivec, const string &title)
{
	cout << title << endl;
	for (vector<int>::iterator itr = ivec.begin(), vecEnd = ivec.end(); itr != vecEnd; ++itr)
		cout << *itr << " ";
}

int main(int argc, char *argv[])
{
	vector<int> vecPentagonal;
	int pos;
	cout << "Please enter a position: ";
	cin >> pos;
	const string title("Pentagonal Numeric Series");
	if (JudgeElem(vecPentagonal, pos)) {
		PentaElem(vecPentagonal, pos);
		DisplayElem(vecPentagonal, title);
	}
	return 0;
}