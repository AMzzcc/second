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
	cout << "���ɵ�ǰ׺���ʽ����������";
	Tree.Print();
	*answer = Tree.Value();
	return true;
}