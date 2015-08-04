//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 7th, 2014
//

#include <iostream>
#include <algorithm>
#include "Stack.h"

using namespace std;

bool Stack::Push(const string &elem)
{
	if (Full())
		return false;
	vecStack.push_back(elem);
	return true;
}

bool Stack::Pop(string &elem)
{
	if (Empty())
		return false;
	elem = vecStack.back();
	vecStack.pop_back();
	return true;
}

bool Stack::Peek(string &elem)
{
	if (Empty())
		return false;
	elem = vecStack.back();
	return true;
}

bool Stack::Find(const string &elem) const
{
	return ::find(vecStack.begin(), vecStack.end(), elem) != vecStack.end();
}

int Stack::Count(const string &elem) const
{
	return ::count(vecStack.begin(), vecStack.end(), elem);
}

int main(int argc, char *argv[])
{
	Stack testStack;
	string word;
	cerr << "Please enter some strings: ";
	while (cin >> word && !testStack.Full())
		testStack.Push(word);
	if (testStack.Empty())
		cout << "Sorry, the stack is empty." << endl;
	if (testStack.Peek(word))
		cout << "There are " << testStack.Size() << " strings in the stack." << endl;
	cin.clear();
	cout << "Please enter the word you want to query: ";
	cin >> word;
	bool testFind = testStack.Find(word);
	int testCount = testFind ? testStack.Count(word) : 0;
	if (testFind)
		cout << "The word " << word << " is in the stack, and it occurs " << testCount << " times." << endl;
	else
		cout << "The word " << word << " is not in the stack." << endl;
	return 0;
}