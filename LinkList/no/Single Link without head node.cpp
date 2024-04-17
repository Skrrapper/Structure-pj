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
//定义数据域和指针域
typedef struct LNode
{
    ElemType data; //结点的数据域
    struct LNode* next; //结点的指针域
} LNode, * LinkList; //LinkList为指向结构体LNode的指针类型
Status InitList(LinkList& L)   //算法2.6 单链表的初始化
{
    //构造一个空的单链表L
    L = NULL;
    return OK;
}

Status DestroyList(LinkList& L)
{
    /* 初始条件：线性表L已存在。操作结果：销毁线性表L */
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
    /****在此下面完成代码***************/
    return L == NULL;
    /***********************************/
}
int ListLength(LinkList L) {
    /****在此下面完成代码***************/
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



Status GetElem(LinkList L, int i, ElemType& e)   //算法2.7 单链表的取值
{
    /****在此下面完成代码***************/
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

int LocateElem(LinkList L, int e)   //略有改动 算法2.8 按值查找
{
    /****在此下面完成代码***************/
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
Status ListInsert(LinkList& L, int i, ElemType e)   //算法2.9 单链表的插入
{
    /****在此下面完成代码***************/
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

Status ListDelete(LinkList& L, int i)   //算法2.10 单链表的删除
{
    /****在此下面完成代码***************/
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