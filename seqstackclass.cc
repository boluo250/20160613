 ///
 /// @file    seqstackclass.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-17 13:15:52
 ///
#include "seqstackclass.h" 
#include <iostream>
#include <stdlib.h> 
using namespace std;

Seqstack::Seqstack(int size)
:_size(size)
,_top(-1)
,_parr(new int[size])
{}
Seqstack::~Seqstack()
{
	delete [] _parr;
}

bool Seqstack::full()
{
	return _top == _size-1;
}
bool Seqstack::empty()
{
	return -1 == _top;
}
void Seqstack::push(int num)
{
	if(!full())
	{
		_parr[++_top] = num;
	}
	else
	{
		cout << "stack aready full"  << endl;
	}
}
void Seqstack::pop()
{
	if(!empty())
	{
		--_top;
	}
	else
	{
		cout << "stack aready empty" << endl;
	}
}
int Seqstack::top()
{
	if(!empty())
	{
		return _parr[_top];
	}
	else
		exit(-1);
}
int Seqstack::size()
{
	return _top +1;
}

int main()
{
	Seqstack ss(5);
    cout <<	ss.empty() << endl;
	ss.push(1);
	ss.pop();
	ss.push(2);
	cout << ss.top() << endl;

	return 0;
}
