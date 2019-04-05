
#ifndef _LQUEUE_H_
#define _LQUEUE_H_
#include<stdio.h>
#include<stdlib.h>
//��ʽ���нṹ
typedef struct node
{
	void *data;                   //������ָ��
	struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
	Node *front;                   //��ͷ
	Node *tail;                    //��β
	unsigned int length;            //���г���
	int typesize;
} LQueue;

typedef enum
{
	FALSE = 0, TRUE = 1
} Status;
//extern Status;

Status InitLQueue(LQueue *Q,int typesize);
void DestoryLQueue(LQueue *Q);

Status IsEmptyLQueue(const LQueue *Q);
Status GetHeadLQueue(LQueue *Q, void *e);
int LengthLQueue(LQueue *Q);

Status EnLQueue(LQueue *Q, void *data);
Status DeLQueue(LQueue *Q);

void ClearLQueue(LQueue *Q);
Status TraverseLQueue(const LQueue *Q, void(*foo)(void *q,int typesize));
void LPrint(void *q,int typesize);

#endif // _LQUEUE_H_
