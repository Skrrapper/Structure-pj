#include "Queue.h"
void QInit(Queue* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;

}

void QPush(Queue* pq, QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)//Îª¿Õ
	{
		assert(pq->tail == NULL);

		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

void QPop(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);
	
	/*QNode next = pq->head->next;
	free(pq->head);
	pq->head = next;*/

	//if (pq->head == NULL)
	//	pq->tail = NULL;

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->size--;

}

void QSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

bool QEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;

}

QDataType QFront(Queue* pq)
{
	assert(pq);
	assert(!QEmpty(pq));

	return pq->head->data;

}

QDataType QBack(Queue* pq)
{
	assert(pq);
	assert(!QEmpty(pq));

	return pq->tail->data;

}