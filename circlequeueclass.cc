 ///
 /// @file    circlequeueclass.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-17 14:09:43
 ///
#include "circlequeueclass.h" 
#include <iostream>
#include <stdlib.h> 
using namespace std;

Circlequeue::Circlequeue(int size)
:_front(0)
,_rear(0)
,_size(size)
,_parr(new int[size])
{}
Circlequeue::~Circlequeue()
{
	delete [] _parr;
}

bool Circlequeue::full() const
{
	return (_rear+1)%_size == _front;
}
bool Circlequeue::empty() const
{
	return _rear == _front;
}
void Circlequeue::push(int num)
{
	if(!full())
	{
		_parr[_rear] = num;
		_rear = (_rear+1) % _size;
	}
	else
	{
		cout << "queue aready full" << endl;
	}
}
void Circlequeue::pop()
{
	if(!empty())
	{
		_front = (_front+1) % _size;
	}
	else
	{
		cout << "queue already empty" << endl;
	}
}
int Circlequeue::front() const
{
	if(!empty())
		return _parr[_front];
	else
		exit(-1);
}

int Circlequeue::back() const
{
	if(!empty())
		return _parr[(_rear-1+_size)%_size];
	else
		exit(-1);
}

int main()
{
	Circlequeue cq(5);
	cq.push(1);
	cq.pop();
	cq.pop();
	cout << cq.empty() << endl;
	return 0;
}

