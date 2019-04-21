#include"Calcu.h"
bool MakeTree(LinkStack<node>*p, double* answer)
{
	stack<node>q;
	BinaryTree<node> Tree;
	while (p->isEmptyStack())
	{
		q.push(p->top->next->data);
		p->pop();
	}
	Tree.CreateBinaryTree(q);
	cout << "生成的前缀表达式及二叉树：";
	Tree.Print();
	*answer = Tree.Value();
	return true;
}