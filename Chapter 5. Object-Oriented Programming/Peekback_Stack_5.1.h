//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 29th, 2014
//

#ifndef PEEKBACK_STACK_H_
#define PEEKBACK_STACK_H_

#include <vector>
#include "Stack.h"

class Peekback_Stack : public Stack
{
public:
	Peekback_Stack(int room = 0) : topStack(0)
	{
		if (room)
			vecStack.reserve(room);
	}
	~Peekback_Stack() {}
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
	bool Pop(string &elem);
	bool Push(const string &elem);
	bool Peek(int num, string &elem);
	void Print(ostream &os = cout) const;

private:
	vector<string> vecStack;
	int topStack;
};

bool Peekback_Stack::Pop(string &elem)
{
	if (Empty()) {
		cerr << "Sorry, the stack is empty." << endl;
		return false;
	}
	elem = vecStack[--topStack];
	vecStack.pop_back();
	return true;
}

bool Peekback_Stack::Push(const string &elem)
{
	if (Full()) {
		cerr << "Sorry, the stack is full." << endl;
		return false;
	}
	vecStack.push_back(elem);
	++topStack;
	return true;
}

bool Peekback_Stack::Peek(int num, string &elem)
{
	if (Empty()) {
		cerr << "Sorry, the stack is empty." << endl;
		return false;
	}
	if (num < 0 || num >= Size()) {
		cerr << "Sorry, the number is wrong." << endl;
		return false;
	}
	elem = vecStack[num];
	return true;
}

void Peekback_Stack::Print(ostream &os /* = cout */) const
{
	for (vector<string>::const_reverse_iterator itr = vecStack.rbegin(), vecEnd = vecStack.rend(); itr != vecEnd; ++itr)
		os << *itr << " ";
	os << endl;
}

#endif