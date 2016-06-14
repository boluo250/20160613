 ///
 /// @file    stackClass.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-13 23:21:50
 ///
 
#include  "stackClass.hh"
#include <stdlib.h> 
#include <iostream>

using namespace std;
Stack::Stack(int capacity)
:_capacityStack(capacity)
{
	_stack->top = NULL;
	_stack->sizeStack = 0;
}
Stack::~Stack()
{
	while(!empty())
		pop();
}
void Stack::push(ElemType value)
{
	if(_stack->sizeStack == _capacityStack)
		exit(OVERFLOW);
	LNode *new_top = new LNode;
	new_top->value = value;
	new_top->next = _stack->top;
	_stack->top = new_top;
	_stack->sizeStack++;
	cout << "push:" << value << endl;
}
void Stack::pop()
{
	if(empty())
		exit(STACKEMPTY);
	LNode *del;
	ElemType value;
	value = _stack->top->value;
	del = _stack->top;
	_stack->top = _stack->top->next;
	_stack->sizeStack--;
	delete del;
	cout << "pop()" << value <<  endl;
}
ElemType Stack::top()
{
	return _stack->top->value;
}
bool Stack::empty()
{
	if(_stack->top == NULL)
		return 1;
	return 0;
}
bool Stack::full()
{
	if(_stack->sizeStack == _capacityStack)
		return 1;
	return 0;
}
/*
Stack::Stack(const Stack &original)
	
:_capacityStack(original._capacityStack)
{
	LNode *ori_top = original._top;
	LNode *new_top;
	if(NULL == ori_top)
	{
		_stack->top = NULL;
		_stack->sizeStack = 0;
	}
	else{
		_stack =
		while(ori_top != NULL)
		{
*/



int main()
{
	Stack stack(1);
	cout << stack.empty() << endl;
	stack.push(10);
	stack.push(10);
	stack.pop();
	cout << stack.empty() << endl;

	return 0;
}







