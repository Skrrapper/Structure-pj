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
//�����������ָ����
typedef struct LNode
{
    ElemType data; //����������
    struct LNode* next; //����ָ����
} LNode, * LinkList; //LinkListΪָ��ṹ��LNode��ָ������
Status InitList(LinkList& L)   //�㷨2.6 ������ĳ�ʼ��
{
    //����һ���յĵ�����L
    L = NULL;
    return OK;
}

Status DestroyList(LinkList& L)
{
    /* ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L */
    LinkList q;
    while (L) {
        q = L->next;
        delete L;
        L = q;
    }
    return OK;
}
bool ListEmpty(LinkList L)
{
    /****�ڴ�������ɴ���***************/
    return L == NULL;
    /***********************************/
}
int ListLength(LinkList L) {
    /****�ڴ�������ɴ���***************/
    if (ListEmpty(L)) return 0;
    int ans = 0;
    LinkList q;
    while (L) {
        q = L->next;
        L = q;
        ans++;
    }
    return ans;
    /***********************************/
}



Status GetElem(LinkList L, int i, ElemType& e)   //�㷨2.7 �������ȡֵ
{
    /****�ڴ�������ɴ���***************/
    LNode* p;
    int ans = 0;
    if (ListEmpty(L)) return 0;
    for (p = L; p; p = p->next) {
        ans++;
        if (ans == i) { e = p->data; return 1; }
    }
    return 0;
    /***********************************/
} //GetElem

int LocateElem(LinkList L, int e)   //���иĶ� �㷨2.8 ��ֵ����
{
    /****�ڴ�������ɴ���***************/
    if (ListEmpty(L)) return 0;
    LNode* p;
    int ans = 0;
    for (p = L; p; p = p->next) {
        ans++;
        if (p->data == e) return ans;
    }
    return 0;
    /*************************************/
} //LocateElem
Status ListInsert(LinkList& L, int i, ElemType e)   //�㷨2.9 ������Ĳ���
{
    /****�ڴ�������ɴ���***************/
    LNode* p;
    int ans = 0;
    if (ListEmpty(L) && i != 1) return 0;
    LinkList l = new LNode;
    if (i == 1) {
        if (L == NULL) {
            L = l;
            L->next = NULL;
            L->data = e;
            return 1;
        }
        l->next = L;
        l->data = e;
        L = l;
        return 1;
    }
    for (p = L; p; p = p->next) {
        ans++;
        if (ans == i - 1) {
            l->next = p->next;
            l->data = e;
            p->next = l;
            return 1;
        }
    }
    return 0;
    /***********************************/
} //ListInsert

Status ListDelete(LinkList& L, int i)   //�㷨2.10 �������ɾ��
{
    /****�ڴ�������ɴ���***************/
    LNode* p;
    int ans = 0;
    if (ListEmpty(L)) return 0;
    if (i == 1) {
        LinkList l = L;
        L = l->next;
        free(l);
        return 1;
    }
    for (p = L; p; p = p->next) {
        ans++;
        if (p->next == NULL) return 0;
        if (ans == i - 1) {
            LinkList l = p->next;
            p->next = l->next;
            free(l);
            return 1;
        }
    }
    return 0;
}