#include"Calcu.h"
bool MakeTree(LinkStack<node>*p, double* answer)
{
	stack<node>q;
	BinaryTree<node> Tree;
	while (!p->isEmptyStack())
	{
		q.push(p->top->next->data);
		p->pop();
	}
	Tree.CreateBinaryTree(q,answer);
	
	/*Tree.Print();
	*answer = Tree.Value();*/
	return true;
}

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