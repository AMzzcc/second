#include"AQueue.h"
void InitAQueue(AQueue * Q,int typesize)
{

	for (int i = 0; i < MAXQUEUE; i++)
	{
		Q->data[i] = NULL;
	}
	Q->typesize = typesize;
	Q->front = Q->tail = 0;
	Q->length = 0;
}

void DestoryAQueue(AQueue * Q)
{
	DeAQueue(Q);
	free(Q);

}

Status IsFullAQueue(const AQueue * Q)
{
	return Q->length == MAXQUEUE;
}

Status IsEmptyAQueue(const AQueue * Q)
{
	return Q->length == 0;
}

Status GetHeadAQueue(AQueue * Q, void * e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("The queue is empty\n");
		return FALSE;
	}
	else
	{
		e = Q->data[Q->front];
		return TRUE;
	}
}

int LengthAQueue(AQueue * Q)
{
	return Q->length;
}

Status EnAQueue(AQueue * Q, void * data)
{
	if (IsFullAQueue(Q))
	{
		printf("The queue is full\n");
		return FALSE;
	}
	
	if (Q->tail == MAXQUEUE)Q->tail = 0;
	else if (IsEmptyAQueue(Q));
	else ++Q->tail;
	Q->data[Q->tail] = data;
	++Q->length;
	printf("success add to queue\n");
	return TRUE;

}

Status DeAQueue(AQueue * Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("The queue is empty\n");
		return FALSE;
	}
	else
	{
		if (Q->front == MAXQUEUE)Q->front = 0;
		else if (Q->length == 1);
		else ++Q->front;
		--Q->length;
		return TRUE;
	}
}

void ClearAQueue(AQueue * Q)
{
	while (DeAQueue(Q));
	Q->typesize = 0;
}

Status TraverseAQueue(const AQueue * Q, void(*foo)(void *q,int typesize))
{
	if (IsEmptyAQueue(Q))
	{
		printf("The queue is empty\n");
		return FALSE;
	}
	for (int i = Q->front; i <= Q->tail; i++)
	{
		foo(Q->data[i],Q->typesize);
	}
	return TRUE;
}

void APrint(void * q,int typesize)
{
	if (typesize == 2)printf("%c ", *(char*)q);
	else if (typesize == 4)printf("%d ", *(int*)q);
	else if (typesize == 8)printf("%f ", *(float*)q);
	
}
