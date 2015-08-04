//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ November 27th, 2014
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int number, sum = 0;
	vector<int> vecNumber;
	cout << "Please enter some integers: ";
	while (cin >> number)
		vecNumber.push_back(number);
	for (vector<int>::iterator itr = vecNumber.begin(), vecEnd = vecNumber.end(); itr != vecEnd; ++itr)
		sum += *itr;
	cout << "The sum is " << sum << endl;
	double average = sum / vecNumber.size();
	cout << "The average is " << average << endl;
	return 0;
}