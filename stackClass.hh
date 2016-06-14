 ///
 /// @file    stackClass.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-13 23:21:50
 ///
#ifndef __STACKCLASS_HH__
#define __STACKCLASS_HH__

#define OVERFLOW -2
#define STACKEMPTY -3

typedef int ElemType;


typedef struct node{
	ElemType value;
	struct node *next;
}LNode;

typedef struct{
	LNode *top;
	int sizeStack;
}stack_t;

class Stack
{
public:
	Stack(int capacity);
	~Stack();
	void push(ElemType value);
	void pop();
	ElemType top();
	bool empty();
	bool full();
private:
	Stack(const Stack &original);
	void operator = (const Stack &original);
private:
	stack_t *_stack;
	int _capacityStack;
};

#endif
