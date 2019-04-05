#ifndef _AQUEUE_H_
#define _AQUEUE_H_
#define MAXQUEUE 10
#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"
//ѭ�����нṹ
typedef struct Aqueue
{
	void *data[MAXQUEUE];      //������
	int front;
	int tail;
	unsigned int length;        //���г���
	int typesize;
} AQueue;

//typedef enum
//{
//	FALSE = 0, TRUE = 1
//} Status;


void InitAQueue(AQueue *Q,int typesize);

void DestoryAQueue(AQueue *Q);

Status IsFullAQueue(const AQueue *Q);

Status IsEmptyAQueue(const AQueue *Q);
Status GetHeadAQueue(AQueue *Q, void *e);
int LengthAQueue(AQueue *Q);
Status EnAQueue(AQueue *Q, void *data);
Status DeAQueue(AQueue *Q);
void ClearAQueue(AQueue *Q);
Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q,int typesize));
void APrint(void *q,int typesize);

#endif // _AQUEUE_H_
