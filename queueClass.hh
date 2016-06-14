

#ifndef __QUEUECLASS_HH__
#define __QUEUECLASS_HH__

typedef int ElemType;

typedef struct node{
	ElemType data;
	struct node *next;
}LNode;

typedef struct{
	LNode *front;
	LNode *rear;
}Queue_t;

class Queue
{
public:
	Queue();
	~Queue();
	void push(ElemType data);
	void pop();
	ElemType front();
	ElemType rear();
	bool empty();
private:
	Queue(const Queue & rhs);
	void operator = (const Queue &rhs);
private:
	Queue_t *_queue;
};
#endif
