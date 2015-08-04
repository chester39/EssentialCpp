//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 29th, 2014
//

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack
{
public:
	Stack(int room = 0) : topStack(0)
	{
		if (room)
			vecStack.reserve(room);
	}
	virtual ~Stack() {}
	bool Empty() const
	{
		return vecStack.empty();
	}
	bool Full() const
	{
		return vecStack.size() >= vecStack.max_size();
	}
	int Size() const
	{
		return vecStack.size();
	}
	int Top() const
	{
		return topStack;
	}
	virtual bool Peek(int num, string &elem)
	{
		return false;
	}
	bool Pop(string &elem);
	bool Push(const string &elem);
	void Print(ostream &os = cout) const;

protected:
	vector<string> vecStack;
	int topStack;
};

bool Stack::Pop(string &elem)
{
	if (Empty()) {
		cerr << "Sorry, the stack is empty." << endl;
		return false;
	}
	elem = vecStack[--topStack];
	vecStack.pop_back();
	return true;
}

bool Stack::Push(const string &elem)
{
	if (Full()) {
		cerr << "Sorry, the stack is full." << endl;
		return false;
	}
	vecStack.push_back(elem);
	++topStack;
	return true;
}

void Stack::Print(ostream &os /* = cout */) const
{
	for (vector<string>::const_reverse_iterator itr = vecStack.rbegin(), vecEnd = vecStack.rend(); itr != vecEnd; ++itr)
		os << *itr << " ";
	os << endl;
}

ostream &operator<<(ostream &os, const Stack &myStack)
{
	myStack.Print();
	return os;
}

#endif