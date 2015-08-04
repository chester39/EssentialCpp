//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ November 30th, 2014
//
 
#include <iostream>

using namespace std;

bool FibonElem(int pos, int &elem)
{

	if (pos <= 0 || pos > 1024) {
		cerr << "Wrong position! ";
		elem = 0;
		return false;
	}
	elem = 1;
	int n_2 = 1, n_1 = 1;
	for (int ix = 3; ix <= pos; ++ix) {
		elem = n_2 + n_1;
		n_2 = n_1;
		n_1 = elem;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int pos;
	char continueFibon = 'y';
	while (continueFibon == 'y') {
		cout << "Please enter a position: ";
		cin >> pos;
		int elem;
		if (FibonElem(pos, elem))
			cout << "Element # " << pos << " is " << elem << endl;
		else
			cout << "Sorry, could not calculate this element # " << pos << endl;
		continueFibon = 'n';
		cout << "Would you like to try again(y/n)? ";
		cin >> continueFibon;
	}
	return 0;
}