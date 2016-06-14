 ///
 /// @file    mutexclass.cc
 /// @author  boluo(169180920@qq.com)
 /// @date    2016-06-12 21:07:36
 ///
 
#include <iostream>
#include <pthread.h>
using namespace std;

class Mutexlock
{
public:
	Mutexlock()
	{
		pthread_mutex_init(&_mutex,NULL);
	}
	~Mutexlock()
	{
		pthread_mutex_destroy(&_mutex);
	}
	void lock()
	{
		pthread_mutex_lock(&_mutex);
	}
	void unlock()
	{
		pthread_mutex_unlock(&_mutex);
	}
	pthread_mutex_t * getMutexPtr()
	{
		return &_mutex;
	}
private:
	Mutexlock(const Mutexlock &rhs);
	Mutexlock &operator = (const Mutexlock &rhs);
private:
	pthread_mutex_t _mutex;
};

class Condtion
{
public:
	Condtion(Mutexlock & mutex)
	:_mutex(mutex)
	{
		pthread_cond_init(&_cond,NULL);
	}
	void wait()
	{
		pthread_cond_wait(&_cond,_mutex.getMutexPtr());
	}
	void notify()
	{
		pthread_cond_signal(&_cond);
	}
	void notifyAll()
	{
		pthread_cond_broadcast(&_cond);
	}

private:
	pthread_cond_t _cond;
	Mutexlock & _mutex;
};



int main()
{
	Mutexlock mutex;
	Condtion condition(mutex);
	condition.wait();
	mutex.lock();
	cout << "doing something" << endl;
	mutex.unlock();

	return 0;
}
