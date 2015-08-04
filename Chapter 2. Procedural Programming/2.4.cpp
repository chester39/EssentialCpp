//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ November 30th, 2014
//

#include <iostream>
#include <vector>

using namespace std;

inline bool JudgeElem(int pos)
{
	if (pos <= 0 || pos > 100) {
		cerr << "Wrong position! ";
		return false;
	}
	return true;
}

const vector<int> *PentaFunc(int pos)
{
	static vector<int> ivec;
	if ((JudgeElem(pos)) && (pos > ivec.size()))
		for (int ix = ivec.size(); ix <= pos; ++ix)
			ivec.push_back(ix * (3 * ix - 1) / 2);
	return &ivec;
}

bool PentaElem(int pos, int &elem)
{
	const vector<int> *ivec = PentaFunc(pos);
	if (!JudgeElem(pos)) {
		cerr << "Wrong position! ";
		elem = 0;
		return false;
	}
	elem = (*ivec)[pos - 1];
	return true;
}

int main(int argc, char *argv[])
{
	int pos, elem;
	cout << "Please enter a position: ";
	cin >> pos;
	if (JudgeElem(pos)) {
		PentaElem(pos + 1, elem);
		cout << "Element # " << pos << " is " << elem << endl;
	}
	return 0;
}