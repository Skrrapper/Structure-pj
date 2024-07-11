#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
 
typedef int	QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QInit(Queue* pq);
void QDestroy(Queue* pq);
void QPush(Queue* pq,QDataType x);
void QPop(Queue* pq);
void QSize(Queue* pq);
bool QEmpty(Queue* pq);
QDataType QFront(Queue* pq);
QDataType QBack(Queue* pq);