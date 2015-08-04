//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ January 12th, 2014
//

bool Stack::Pop(string &elem)
{
	if (Empty()) {
		throw PopEmpty();
		return false;
	}
	elem = vecStack[--topStack];
	vecStack.pop_back();
	return true;
}

bool Stack::Push(const string &elem)
{
	if (Full()) {
		throw PushFull();
		return false;
	}
	vecStack.push_back(elem);
	++topStack;
	return true;
}

class StackException : public logic_error
{
public:
	StackException(const char *what) :myWhat(what) {}
	const char *What() const
	{
		return myWhat.c_str();
	}

protected:
	string myWhat;
};

class PopEmpty : public StackException
{
public:
	PopEmpty() : StackException("Sorry, the stack is empty.") {}
};

class PushFull : public StackException
{
public:
	PushFull() : StackException("Sorry, the stack is full.") {}
};
