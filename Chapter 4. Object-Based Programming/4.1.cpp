//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 7th, 2014
//

#include <iostream>
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

int main(int argc, char *argv[])
{
	Stack testStack;
	string word;
	cout << "Please enter some strings: ";
	while (cin >> word && !testStack.Full())
		testStack.Push(word);
	if (testStack.Empty())
		cerr << "Sorry, the stack is empty." << endl;
	if (testStack.Peek(word))
		cout << "There are " << testStack.Size() << " strings in the stack." << endl;
	cout << "The reverse order: ";
	while (testStack.Size())
		if (testStack.Pop(word))
			cout << word << " ";
	cout << endl << "There are " << testStack.Size() << " strings in the stack." << endl;
	return 0;
}