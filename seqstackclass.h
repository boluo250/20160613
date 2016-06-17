 ///
 /// @file    seqstackclass.h
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-17 13:12:38
 ///
#ifndef __SEQSTACKCLASS_H__
#define __SEQSTACKCLASS_H__
 

class Seqstack
{
public:
	Seqstack(int size);
	~Seqstack();

	bool full();
	bool empty();
	void push(int num);
	void pop();
	int top();
	int size();

private:
	int _top;
	int _size;
	int  *_parr;
};

#endif
