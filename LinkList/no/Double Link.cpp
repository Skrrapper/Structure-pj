#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣

typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

#define MAXSIZE 100 //������ܴﵽ����󳤶�
typedef struct DulNode
{
	ElemType data;
	struct DulNode* prior;//ָ��ֱ��ǰ��,���ǲ�ͬ�ڵ�����ĵ㣬������ǰѰ���������
	struct DulNode* next;//ָ��ֱ�Ӻ��
}DulNode, * DuLinkList;
//˫����͵�������ڲ����ɾ��������нϴ����
//ȡֵ������һ��������
//Status GetElem_DuL(DuLinkList L, int i)
//{
//	DuLinkList p = L->next;
//	int j = 1;
//	while (p && j < i) {
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i) {
//		return ERROR;
//	}
//	return p->data;
//}
// �Ż�������
// ��˫�������и���λ��iֱ�Ӷ�λ����Ӧ�Ľڵ㣬���ظýڵ�ָ�롣
DulNode* GetElem_DuL(DuLinkList& L, int i)
{
	if (i < 0) return NULL;

	DulNode* p = L;
	int j = 0;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}

	return p;
}

//����
Status ListInsert_Dul(DuLinkList& L, int i, ElemType e)
{
	DulNode* p;
	if (!(p = GetElem_DuL(L, i))) return ERROR;
	DulNode* s = new DulNode;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

//ɾ��
Status ListDelete_DuL(DuLinkList& L, int i)
{
	DuLinkList p;
	if (!(p = GetElem_DuL(L, i))) return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return OK;
}

