#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<math.h>
#include"LinkStack.h"
#include"Calculator.h"
using namespace std;
template <typename T>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	const T&findMin()const;  //外部调用
	const T&findMax()const;
	/*friend class Calculator;*/
	void makeEmpty();
	bool isEmpty()const;
	bool Find(const T&e)const;
	void insert(const T&e);
	void insert(T&&e);
	void remove(const T&e);
	void Print();
	void CreateBitTree(stack<node>q);
	void CreateBinaryTree(stack<node>q);
	double Value();
	
private:
	struct  BinaryNode {
		T  data;     // 数据域
		BinaryNode  *left;
		BinaryNode *right;

		BinaryNode(const T&e,BinaryNode*L, BinaryNode* R) :data(e),  left(L), right(R) {}

		BinaryNode(T&&e, BinaryNode*L, BinaryNode* R) :data(std::move(e)),  left(L), right(R) {}
	};

	BinaryNode * root;
	stack<node>father;
private:
	BinaryNode * findMin(BinaryNode *t)const;   //内部调用
	BinaryNode * findMax(BinaryNode *t)const;

	void insert(const T&e, BinaryNode * &t);	//插入
	void insert(T &&e, BinaryNode * &t);
	void remove(const T&e, BinaryNode * &t);  //删除
	bool Find(const T&e, BinaryNode*t)const;
	void makeEmpty(BinaryNode*&t);
	BinaryNode* clone(BinaryNode*t)const;  //克隆

	static void print(T e);
	void Push(T e);
	//递归版
	bool PreOrderTraverse(BinaryNode* t, void(*visit)(T e));//先序遍历
	bool InOrderTraverse(BinaryNode* t, void(*visit)(T e));	//中序遍历
	bool PostOrderTraverse(BinaryNode* t, void(*visit)(T e));	//后序遍历
	bool LevelOrderTraverse(BinaryNode* t, void(*visit)(T e));	//层序遍历
	//非递归版
	bool PreOrderTraverseWithout(BinaryNode* t, void(*visit)(T e));//先序遍历
	bool InOrderTraverseWithout(BinaryNode* t, void(*visit)(T e));	//中序遍历
	bool PostOrderTraverseWithout(BinaryNode* t, void(*visit)(T e));	//后序遍历


	bool CreateBiTree(BinaryNode* t, stack<node>q);   //前缀
	bool CreateBinaryTree(BinaryNode* t, stack<node>q);  //后缀
	
	double Value(BinaryNode*t);
	//构造出的二叉树求值
	/*
	提示：可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
	可根据需要自行增加操作.
	*/


};
template <typename T>
ostream & operator<<(ostream & output, const node & d)
{
	if (d.judge)
	{
		output << d.num;
	}
	else if (!d.judge)
	{
		output << d.oper;
	}

	return output;
}

template<typename T>
inline BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	makeEmpty();
}

template<typename T>
inline const T & BinaryTree<T>::findMin() const
{
	return findMin(root)->data;
}

template<typename T>
inline const T & BinaryTree<T>::findMax() const
{
	return findMax(root)->data;
}

template<typename T>
inline void BinaryTree<T>::makeEmpty()
{
	makeEmpty(root);
}

template<typename T>
inline bool BinaryTree<T>::isEmpty() const
{
	if (root == nullptr)
		return true;
	else return false;
}

template<typename T>
inline bool BinaryTree<T>::Find(const T & e) const
{
	return Find(e, root);
}

template<typename T>
inline void BinaryTree<T>::insert(const T & e)
{
	insert(e, root);
}

template<typename T>
inline void BinaryTree<T>::insert(T && e)
{
	insert(e, root);
}

template<typename T>
inline void BinaryTree<T>::remove(const T & e)
{
	remove(e, root);
}

template<typename T>
inline void BinaryTree<T>::Print()
{
	PreOrderTraverse(root, print);
	cout << endl;
	//InOrderTraverse(root, print);	//中序遍历
	//cout << endl;
	//PostOrderTraverse(root, print);	//后序遍历
	//cout << endl;
	LevelOrderTraverse(root, print);	//层序遍历
}

template<typename T>
inline void BinaryTree<T>::CreateBitTree(stack<node>q)
{
	CreateBiTree(root, q);
}

template<typename T>
inline void BinaryTree<T>::CreateBinaryTree(stack<node> q)
{
	CreateBinaryTree(root, q);
}

template<typename T>
inline double BinaryTree<T>::Value()
{
	return Value(root);
}



template<typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::findMin(BinaryNode * t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;

	return	findMin(t->left);
}

template<typename T>
typename BinaryTree<T>::BinaryNode* BinaryTree<T>::findMax(BinaryNode * t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->right == nullptr)
		return t;

	return	findMax(t->right);
}

template<typename T>
inline void BinaryTree<T>::insert(const T & e, BinaryNode *& t)
{
	if (t == nullptr)
		t = new BinaryNode{ e,nullptr,nullptr };
	else if (e > t->data)
		return insert(e,t->right);
	else if (e < t->data)
		return insert(e,t->left);
	else
		;//重复则啥也不干
}

template<typename T>
inline void BinaryTree<T>::insert(T && e, BinaryNode *& t)
{
	if (t == nullptr)
		t = new BinaryNode{ std::move(e),nullptr,nullptr };
	else if (e > t->data)
		return insert(e,t->right);
	else if (e < t->data)
		return insert(e,t->left);
	else
		;//重复则啥也不干
}

template<typename T>
inline void BinaryTree<T>::remove(const T & e, BinaryNode *& t)
{
	if (t == nullptr)
		return;
	if (e < t->data)
		remove(e, t->left);
	else if (e > t->right)
		remove(e, t->right);
	else if (t->left != nullptr&&t->right != nullptr)
	{
		t->data = findMin(t->right)->data;
		remove(t->data, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		if (oldNode->parent != nullptr)
			t->parent = oldNode->parent;
		delete(oldNode);
	}

}

template<typename T>
inline bool BinaryTree<T>::Find(const T & e, BinaryNode * t) const
{
	if (t == nullptr)return false;
	else if (e < t->data)
		return Find(e, t->left);
	else if (e > t->data)
		return Find(e, t->right);
	else
		return true;
}

template<typename T>
inline void BinaryTree<T>::makeEmpty(BinaryNode *& t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}

template<typename T>
inline void BinaryTree<T>::print(T e)
{
	cout << e << " ";
}

template<typename T>
inline void BinaryTree<T>::Push(T e)
{
	father.push(e);
}

template<typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::clone(BinaryNode * t) const
{
	if (t == nullptr)return t;
	else
		return new BinaryNode{ t->data,clone(t->left),clone(t->right) };
}

template<typename T>
bool BinaryTree<T>::CreateBiTree(BinaryNode* t, stack<node>q)
{
	stack<BinaryNode*>s;
	BinaryNode* now;
	if (q.empty())
	{
		cout << "null" << endl;
		return false;
	}
	now= new BinaryNode{ q.top(),nullptr,nullptr };
	s.push(now);
	q.pop();
	while (!q.empty())
	{
		if (q.top().judge)//		数字
		{
			if (now->data.judge)  //前一个也是，则加入s
			{
				now = new BinaryNode{ q.top(),nullptr,nullptr };
				s.push(now);
				q.pop();
			}
			else  //前一个操作符
			{
				if (now->right == nullptr)
				{
					now->right= new BinaryNode{ q.top(),nullptr,nullptr };
					q.pop();
				}
				else if(now->left == nullptr)
				{
					now->left = new BinaryNode{ q.top(),nullptr,nullptr };
					q.pop();
				}
				else
				{
					now = new BinaryNode{ q.top(),nullptr,nullptr };
					s.push(now);
					q.pop();
				}
			}
		}
		else  //caozuofu
		{
			now = new BinaryNode{ q.top(),nullptr,nullptr };
			s.push(now);
			q.pop();
		}
	}
	
	stack<BinaryNode*>s2;
	BinaryNode*then;
	while (!s.empty())
	{
		s2.push(s.top());
		s.pop();
	}
	now=t = s2.top();
	s2.pop();
	then = now->left;
	while (!s2.empty())
	{
		if (s2.top()->data.judge)
		{
			if(now->right == nullptr)
			{
				now->right= s2.top();
				s2.pop();
			}
			else if (now->left == nullptr)
			{
				now->left = s2.top();
				s2.pop();
			}
			else if (then->right == nullptr)
			{
				then->right= s2.top();
				s2.pop();
				now = then;
				then = now->left;
			}
		}
		else if(!s2.top()->data.judge)
		{
			if (now->left == nullptr)
			{
				now->left = s2.top();
				s2.pop();
			}
			else if (now->right == nullptr)
			{
				now->right = s2.top();
				s2.pop();
			}
			else if (then->left == nullptr)
			{
				then->left = s2.top();
				s2.pop();
				now = then;
				then = now->left;
			}
		}
	}
	then=now = nullptr;
	return true;
}

template<typename T>
inline bool BinaryTree<T>::CreateBinaryTree(BinaryNode * t, stack<node> q)
{
	stack<BinaryNode*>s;
	BinaryNode* now;
	BinaryNode* then;
	if (q.empty())
	{
		cout << "null" << endl;
		return false;
	}
	while (!q.empty())
	{
		if (q.top().judge)
		{
			now = new BinaryNode{ q.top(),nullptr,nullptr };
			s.push(now);
			q.pop();
		}
		else if (!q.top().judge)
		{
			now = &*s.top();
			s.pop();
			then= s.top();
			s.pop();
			now= new BinaryNode{ q.top(),then,now };
			s.push(now);
			q.pop();
		}
	}
	t = clone(s.top());
	while (!s.empty())
		s.pop();
	return true;
}

template<typename T>
double BinaryTree<T>::Value(BinaryNode*t)
{
	if (t == nullptr)return 0;
	stack<BinaryNode*>s;
	BinaryTree *p;
	BinaryTree *LastView;
	p = t;
	LastView = nullptr;
	while (p->left!=nullptr)
	{
		s.push(p);
		p = p->left;
	}
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		if (p->right == LastView)
		{
			p->data.judge = true;
			if (p->data.oper == '+')
			{
				p->data.num = p->left.num + p->right.num;
			}
			else if (p->data.oper == '-')
			{
				p->data.num = p->left.num - p->right.num;
			}
			else if (p->data.oper == '*')
			{
				p->data.num = p->left.num * p->right.num;
			}
			else if (p->data.oper == '/')
			{
				p->data.num = p->left.num / p->right.num;
			}
			else if (p->data.oper == '%')
			{
				
				p->data.num =(int) p->left.num %(int) p->right.num;
			}
			else if (p->data.oper == '^')
			{
				p->data.num =pow( p->left.num , p->right.num);
			}
			LastView = p;
		}
		else
		{
			s.push(p);
			p = p->right;
			while (p)
			{
				s.push(p);
				p = p->left;
			}
		}
	}
	double answer = p->data.num;
	if (p != nullptr)
	{
		delete(p);
		p = nullptr;
	}
	if (LastView != nullptr)
	{
		delete(LastView);
		LastView = nullptr;
	}
	return answer;
}

template<typename T>
inline bool BinaryTree<T>::PreOrderTraverse(BinaryNode* t, void(*visit)(T e))
{
	if (t == nullptr)
		return true;
	else
		visit(t->data);

	if (t->left != nullptr)
		PreOrderTraverse(t->left, visit);
	if (t->right != nullptr)
		PreOrderTraverse(t->right, visit);
	return true;
}

template<typename T>
inline bool BinaryTree<T>::InOrderTraverse(BinaryNode* t, void(*visit)(T e))
{
	if (t == nullptr)
		return true;

	if (t->left != nullptr)
		InOrderTraverse(t->left, visit);
	visit(t->data);
	if (t->right != nullptr)
		InOrderTraverse(t->right, visit);
	return true;
}

template<typename T>
inline bool BinaryTree<T>::PostOrderTraverse(BinaryNode* t, void(*visit)(T e))
{
	if (t == nullptr)
		return true;

	if (t->left != nullptr)
		PostOrderTraverse(t->left, visit);
	if (t->right != nullptr)
		PostOrderTraverse(t->right, visit);
	visit(t->data);
	return true;
}

template<typename T>
inline bool BinaryTree<T>::LevelOrderTraverse(BinaryNode* t, void(*visit)(T e))
{
	if (t == nullptr)return true;
	queue<BinaryNode*>q;
	BinaryNode* p;
	q.push(t);
	while (!q.empty())
	{
		p = q.front();
		visit(p->data);
		if (p->left != nullptr)
			q.push(p->left);
		if (p->right != nullptr)
			q.push(p->right);
		q.pop();
	}
	return true;
}

template<typename T>
inline bool BinaryTree<T>::PreOrderTraverseWithout(BinaryNode * t, void(*visit)(T e))
{
	if (t == nullptr)return true;
	BinaryNode* p = t;
	stack<BinaryNode *>s;
	while (!s.empty() || p)
	{
		while (p)
		{
			visit(p->data);
			s.push(p);
			p = p->left;
		}

		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
	return true;
}

template<typename T>
inline bool BinaryTree<T>::InOrderTraverseWithout(BinaryNode * t, void(*visit)(T e))
{
	if (t == nullptr)return true;
	BinaryNode* p = t;
	stack<BinaryNode *>s;
	while (!s.empty() || p)
	{
		while (p)
		{
			s.push(p);
			p = p->left;
		}

		if (!s.empty())
		{
			p = s.top();
			s.pop();
			visit(p->data);
			p = p->right;
		}
	}
	return true;
}

template<typename T>
inline bool BinaryTree<T>::PostOrderTraverseWithout(BinaryNode * t, void(*visit)(T e))
{
	if (t == nullptr)return true;
	stack<BinaryNode*>s;
	BinaryTree *p;
	BinaryTree *LastView;
	p = t;
	LastView = nullptr;
	while (p)
	{
		s.push(p);
		p = p->left;
	}
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		if (p->right == nullptr || p->right == LastView)
		{
			visit(p->data);
			LastView = p;
		}
		else
		{
			s.push(p);
			p = p->right;
			while (p)
			{
				s.push(p);
				p = p->left;
			}
		}
	}
	return true;
}

#endif // !_BINARYTREE_H_