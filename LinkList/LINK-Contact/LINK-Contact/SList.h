#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct SLTDataType;
//�������ɽڵ����
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//typedef struct SListNode SLTNode;

void SLTPrint(SLTNode* phead);

//�����ͷ�塢β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//�����ͷɾ��βɾ
void SLTPopBack(SLTNode** pphead);
void SLTPopFront(SLTNode** pphead);

//����
SLTNode* SLTFind(SLTNode** pphead, SLTDataType x);

//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos);
//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos);

//��������
void SListDesTroy(SLTNode** pphead);