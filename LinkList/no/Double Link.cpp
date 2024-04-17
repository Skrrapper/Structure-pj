#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。

typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

#define MAXSIZE 100 //链表可能达到的最大长度
typedef struct DulNode
{
	ElemType data;
	struct DulNode* prior;//指向直接前驱,这是不同于单链表的点，可以往前寻找其他结点
	struct DulNode* next;//指向直接后继
}DulNode, * DuLinkList;
//双链表和单链表仅在插入和删除方面具有较大差异
//取值（方案一）（弃）
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
// 优化方案：
// 在双向链表中根据位置i直接定位到对应的节点，返回该节点指针。
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

//插入
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

//删除
Status ListDelete_DuL(DuLinkList& L, int i)
{
	DuLinkList p;
	if (!(p = GetElem_DuL(L, i))) return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return OK;
}

