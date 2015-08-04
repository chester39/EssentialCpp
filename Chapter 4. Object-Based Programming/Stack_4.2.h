//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 7th, 2014
//

#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <vector>

using namespace std;

class Stack
{
public:
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
	bool Push(const string &elem);
	bool Pop(string &elem);
	bool Peek(string &elem);
	bool Find(const string &elem) const;
	int Count(const string &elem) const;

private:
	vector<string> vecStack;
};

#endif