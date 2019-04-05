#include"LQueue.h"

Status InitLQueue(LQueue * Q,int typesize)
{
	Q->front = Q->tail = (Node*)malloc(sizeof(Node));
	if (!Q->front)return FALSE;
	Q->front->data = NULL;
	Q->front->next = NULL;
	Q->tail = Q->front;
	Q->typesize = typesize;
	Q->length = 0;
	return TRUE;
}

void DestoryLQueue(LQueue * Q)
{
	ClearLQueue(Q);
	free(Q);
}

Status IsEmptyLQueue(const LQueue * Q)
{
	return Q->length == 0;
}

Status GetHeadLQueue(LQueue * Q, void * e)
{
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	else
	{
		e = Q->front->next->data;
		return TRUE;
	}
}

int LengthLQueue(LQueue * Q)
{
	return Q->length;
}

Status EnLQueue(LQueue * Q, void * data)
{
	Q->tail->next = (Node*)malloc(sizeof(Node));
	Q->tail->next->data = data;
	Q->tail->next->next = NULL;
	Q->tail = Q->tail->next;
	++Q->length;
	return TRUE;
}

Status DeLQueue(LQueue * Q)
{
	if (IsEmptyLQueue(Q))return FALSE;
	Node *p = Q->front->next;
	Q->front->next = p->next;
	free(p);
	p = NULL;
	if (Q->front->next == NULL)
	{
		Q->tail = Q->front;
	}
	--Q->length;
	return TRUE;
}

void ClearLQueue(LQueue * Q)
{
	while (DeLQueue(Q));
	Q->typesize = 0;
}

Status TraverseLQueue(const LQueue * Q, void(*foo)(void *q,int typesize))
{
	if (IsEmptyLQueue(Q))return FALSE;
	Node* p = Q->front->next;
	while (p != NULL)
	{
		foo(p->data,Q->typesize);
		p =p->next;
	}
	p = NULL;
	return TRUE;
}

void LPrint(void * q,int typesize)
{
	if (typesize == 1)printf("%c ", *(char*)q);
	else if (typesize == 4)printf("%d ", *(int*)q);
	else if (typesize == 8)printf("%f ", *(double*)q);
}
