//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 29th, 2014
//

#include "LIFO_Stack.h"
#include "Peekback_Stack.h"

using namespace std;

void Peek(Stack &myStack, int num)
{
	string str;
	if (myStack.Peek(num, str))
		cout << "Peek: " << str << endl;
	else
		cerr << "Peek failed!" << endl;
}

int main(int argc, char *argv[])
{
	LIFO_Stack lifoStack;
	Peekback_Stack peekbackStack;
	string str;
	cout << "Please enter some strings: ";
	while (cin >> str && !lifoStack.Full())
		lifoStack.Push(str);
	cout << "Peek() of LIFO_Stack: " << endl;
	Peek(lifoStack, lifoStack.Top() - 1);
	cout << lifoStack;
	while (!lifoStack.Empty()) {
		string temp;
		if (lifoStack.Pop(temp))
			peekbackStack.Push(temp);
	}
	cout << "Peek() of Peekback_Stack: " << endl;
	Peek(peekbackStack, peekbackStack.Top() - 1);
	cout << peekbackStack;
	return 0;
}