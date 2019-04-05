
#ifndef _LQUEUE_H_
#define _LQUEUE_H_
#include<stdio.h>
#include<stdlib.h>
//链式队列结构
typedef struct node
{
	void *data;                   //数据域指针
	struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
	Node *front;                   //队头
	Node *tail;                    //队尾
	unsigned int length;            //队列长度
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
