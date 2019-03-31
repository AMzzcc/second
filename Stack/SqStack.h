#ifndef _SQSTACK_H_
#define _SQSTACK_H_
#include<iostream>
#define STACK_INIT_SIZE 100
#define STACK_SIZE_ADD 50
using namespace std;
template <typename T>
class SqStack
{
public:
	SqStack();
	~SqStack();
	
	bool isEmptyStack();
	T &getTopStack()const;
	bool destroyStack();
	bool clearStack();
	bool push(T&e);
	bool pop();
	bool stackTraverse();
	int stackLength()const;
public:
	
	T * base;
	T * top;
	int size;

};
template<typename T>
inline SqStack<T>::SqStack()
{
	base = new T[STACK_INIT_SIZE];
	if (!base)
	{
		cout << "error create" << endl;
		return;
	}
	top = base;
	size = STACK_INIT_SIZE;
}

template<typename T>
inline SqStack<T>::~SqStack()
{
	destroyStack();
}

template<typename T>
inline bool SqStack<T>::isEmptyStack()
{
	if (top == base)return true;
	return false;
}

template<typename T>
inline T &SqStack<T>::getTopStack()const
{
	if (top == base)
	{
		cout << "Stack is empty" << endl;
		exit(-1);
	}
	else if (base == nullptr)
	{
		cout << "error stack" << endl;
		exit(-1);
	}
	return *(top - 1);
}

template<typename T>
inline bool SqStack<T>::destroyStack()
{
	if (base == nullptr)
		return false;
	clearStack();
	size = 0;
	top = base = nullptr;
	return true;
}

template<typename T>
inline bool SqStack<T>::clearStack()
{
	while (!isEmptyStack())pop();
	return true;
}

template<typename T>
inline bool SqStack<T>::push(T&e)
{
	int a=0, n=0;
	if (top - base >= size)
	{
		T*p = base;
		n = size + STACK_SIZE_ADD;
		base = new T[n];
		a = 0;
		while (a < size)
		{
			base[a] = p[a];
			++a;
		}

		if (!base)
		{
			cout << "error create" << endl;
			return false;
		}
		top = base + size;
		size += STACK_SIZE_ADD;
	}
	*top = e;
	++top;
	return true;

}

template<typename T>
inline bool SqStack<T>::pop()
{
	if (isEmptyStack())
	{
		cout << "stack is empty" << endl;
		return false;
	}
	--top;
	return true;
}

template<typename T>
inline bool SqStack<T>::stackTraverse()
{
	if(base==top)return false;
	T*p = top;
	while (!isEmptyStack())
	{

		cout << *(--top) << endl;
	}
	top = p;
	return true;
}

template<typename T>
inline int SqStack<T>::stackLength() const
{
	if (base == nullptr)
	{
		cout << "stack is error" << endl;
		return -1;
	}
	return top-base;
}

#endif // !_SQSTACK_H_




