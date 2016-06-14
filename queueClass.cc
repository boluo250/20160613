 ///
 /// @file    queueClass.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-14 17:28:07
 ///
#include "queueClass.hh" 
#include <iostream>
#include <stdlib.h> 
using namespace std;

Queue::Queue()
{
	_queue->front = NULL;
	_queue->rear = NULL;
}

Queue::~Queue()
{
	while(!empty())
		pop();
}

void Queue::push(ElemType data)
{
	LNode *new_node = new LNode;
	new_node->data = data;
	new_node->next = NULL;
	if(_queue->front == NULL)
	{
		_queue->front = new_node;
		_queue->rear = new_node;
	}
	else
	{
		_queue->rear->next = new_node;
		_queue->rear = new_node;
	}
}

void Queue::pop()
{
	if(empty())
		exit(-1);
	LNode *del;
	del = _queue->front;
	_queue->front = del->next;
	delete del;
}

ElemType Queue::front()
{
	if(empty())
		exit(-1);
	return _queue->front->data;
}

ElemType Queue::rear()
{
	if(empty())
		exit(-1);
	return _queue->rear->data;
}

bool Queue::empty()
{
	if(NULL == _queue->front)
		return 1;
	return 0;
}

int main()
{
	Queue que;
	cout << "empty=" << que.empty() << endl;
	que.push(1);
	cout << "front()" << que.front() << endl;
	cout << "rear()" << que.rear() << endl;
	que.pop();
	cout << "empty=" << que.empty() << endl;
	que.push(2);
	cout << "front()" << que.front() << endl;

	return 0;
}
