//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 29th, 2014
//

#ifndef PEEKBACK_STACK_H_
#define PEEKBACK_STACK_H_

#include "Stack.h"

class Peekback_Stack : public Stack
{
public:
	Peekback_Stack(int room = 0) : Stack(room) {}
	~Peekback_Stack() {}
	virtual bool Peek(int num, string &elem);
};

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

#endif