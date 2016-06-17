 ///
 /// @file    circlequeueclass.h
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-17 14:05:51
 ///
#ifndef __CIRCLEQUEUECLASS_H__
#define __CIRCLEQUEUECLASS_H__

class Circlequeue
{
public:
	Circlequeue(int size);
	~Circlequeue();

	bool full() const;
	bool empty() const;
	void push(int num);
	void pop();
	int front() const;
	int back() const;

private:
	int _front;
	int _rear;
	int _size;
	int * _parr;
};

#endif 
