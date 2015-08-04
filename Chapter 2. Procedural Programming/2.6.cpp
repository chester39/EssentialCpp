//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ November 30th, 2014
//
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Type>
Type max(Type x1, Type x2)
{
	return x1 > x2 ? x1 : x2;
}

template <typename vecType>
vecType max(const vector<vecType> &ivec)
{
	return *max_element(ivec.begin(), ivec.end());
}

template <typename arrayType>
arrayType max(const arrayType *array, int size)
{
	return *max_element(array, array + size);
}

int main(int argc, char *argv[])
{
	int intArray[] = { 5, 10, 15, 20, 25 };
	vector<int> intVec(intArray, intArray + 5);
	double douArray[] = { 5.1, 5.5, 10.3, 15.6, 20.8 };
	vector<double> douVec(douArray, douArray + 5);
	string strArray[] = { 
		"we", 
		"were", 
		"going", 
		"to", 
		"school"
	};
	vector<string> strVec(strArray, strArray + 5);
	int intMax = max(max(intVec), max(intArray, 5));
	double douMax = max(max(douVec), max(douArray, 5));
	string strMax = max(max(strVec), max(strArray, 5));
	cout << "The max of integers is " << intMax << endl;
	cout << "The max of doubles is " << douMax << endl;
	cout << "The max of strings is " << strMax << endl;
	return 0;
}