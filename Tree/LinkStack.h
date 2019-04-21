#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
template <typename T>
class LinkStack //Á´Õ»
{
public:
	typedef  struct StackNode
	{
		T data;
		struct StackNode *next;
	}StackNode, *LinkStackPtr;

	LinkStack();
	LinkStack(T &e);
	~LinkStack();
	bool isEmptyStack()const;
	bool push(T&e);
	bool pop();
	T & getTopStack()const;
	bool clearStack();
	bool destroyLStack();
	bool stackTraverse();
	int LStackLength()const;
public:
	LinkStackPtr top;
	int	count;
	LinkStackPtr top2;
};



template<typename T>
inline LinkStack<T>::LinkStack()
{
	top = new StackNode;
	top->next = nullptr;
	top2 = top;
	count=0;
}

template<typename T>
inline LinkStack<T>::LinkStack(T & e)
{
	if (count != 0)
	{
		LinkStack();
	}
	push(e);
	return;
}

template<typename T>
inline LinkStack<T>::~LinkStack()
{
	destroyLStack();
}

template<typename T>
inline bool LinkStack<T>::isEmptyStack()const
{
	if (count == 0)return true;
	return false;
}

template<typename T>
inline bool LinkStack<T>::push(T&e)
{
	top->data = e;
	top2 = new StackNode;
	top2->next = top;
	top = top2;
	count++;
	return true;
}

template<typename T>
inline bool LinkStack<T>::pop()
{
	if (count == 0)
	{
		cout << "stack is empty" << endl;
		return false;
	}
	
	top2= top->next;
	delete top;
	top = top2;
	count--;
	return true;
}

template<typename T>
inline T & LinkStack<T>::getTopStack() const
{
	if (isEmptyStack())
	{
		cout << "Stack is empty" << endl;
		return;
	}
	else if (!top)
	{
		count << "stack is error" << endl;
		return;
	}else
	return top->next->data;
}


template<typename T>
inline bool LinkStack<T>::clearStack()
{
	while (count > 0)
	{
		pop();
	}
	return true;
}

template<typename T>
inline bool LinkStack<T>::destroyLStack()
{
	if (!top)
	return false;
	clearStack();
	delete top;
	top2=top = nullptr;
	return true;
}

template<typename T>
inline bool LinkStack<T>::stackTraverse()
{
	for(int a=count;a>0;--a)
	{
		cout << top->next->data << endl;
		top = top->next;
	}
	top = top2;
	return false;
}



template<typename T>
inline int LinkStack<T>::LStackLength() const
{
	if (!top)
	{
		cout << "stack error" << endl;
		return -1;
	}
	return count;
}
#endif // !_LINKSTACK_H_