//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 29th, 2014
//

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <string>

using namespace std;

class Stack
{
public:
	virtual ~Stack() {}
	virtual bool Pop(string &elem) = 0;
	virtual bool Push(const string &elem) = 0;
	virtual bool Peek(int num, string &elem) = 0;
	virtual bool Empty() const = 0;
	virtual bool Full() const = 0;
	virtual int Size() const = 0;
	virtual int Top() const = 0;
	virtual void Print(ostream &os = cout) const = 0;
};

ostream &operator<<(ostream &os, const Stack &myStack)
{
	myStack.Print();
	return os;
}

#endif