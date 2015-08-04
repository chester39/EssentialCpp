//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 29th, 2014
//

#ifndef LIFO_STACK_H_
#define LIFO_STACK_H_

#include <vector>
#include "Stack.h"

class LIFO_Stack : public Stack
{
public:
	LIFO_Stack(int room = 0) : topStack(0)
	{
		if (room)
			vecStack.reserve(room);
	}
	~LIFO_Stack() {}
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
	bool Peek(int num, string &elem)
	{
		return false;
	}
	bool Pop(string &elem);
	bool Push(const string &elem);
	void Print(ostream &os = cout) const;

private:
	vector<string> vecStack;
	int topStack;
};

bool LIFO_Stack::Pop(string &elem)
{
	if (Empty()) {
		cerr << "Sorry, the stack is empty." << endl;
		return false;
	}
	elem = vecStack[--topStack];
	vecStack.pop_back();
	return true;
}

bool LIFO_Stack::Push(const string &elem)
{
	if (Full()) {
		cerr << "Sorry, the stack is full." << endl;
		return false;
	}
	vecStack.push_back(elem);
	++topStack;
	return true;
}

void LIFO_Stack::Print(ostream &os) const
{
	for (vector<string>::const_reverse_iterator itr = vecStack.rbegin(), vecEnd = vecStack.rend(); itr != vecEnd; ++itr)
		os << *itr << " ";
	os << endl;
}

#endif