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

//初始化
Status InitList(LinkList& L)
{
    L = new LNode; //生成新结点作为头结点，用头指针L指向头结点，L即是接下来操作需要用到的指针
    L->next = NULL; //头结点的指针域置空
    return OK;
}

//内存空间开辟
int ListLength(LinkList L)
{
    int len = 0;
    LNode* p = L->next;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;//len即是内存空间的长度
}

//指针置空
bool ListEmpty(LinkList L)
{
    return L->next == NULL;
}

//取值（方案一）
Status GetElem1(LinkList L, int i, ElemType& e)
{
    LNode* p = L->next; int j = 1;//初始化，j作为计数器，p指向首元节点
    while (p && j < i)//查找第i个节点
    {
        p = p->next;//没有找到就指向下一个节点
        ++j;
    }
    //如果不在内存范围内
    if (!p || j > i) return ERROR;
    e = p->data;//取第i个元素数据域，也就是说取到了想要的值
    return OK;
}
//取值（方案二）
Status GetElem2(LinkList L, int i, ElemType& e)
{
    LNode* p; int k = 0;
    for (p = L->next; p; p = p->next)
    {
        k++;
        if (k == i) { e = p->data; return 1; }
    }
    return 0;
}

//查找
LNode* LocateElem(LinkList L, ElemType e)//e是我们需要查找的数据域
{
    LNode* p = L->next;//指向首元节点
    while (p && p->data != e)//直到p为空或者数据域为e
        p = p->next;//指向下一节点
    return p;
}

//插入（方案一）
Status ListInsert1(LinkList& L, int i, ElemType e)
{
    if (i < 1) return ERROR;
    LNode* p = L; int j = 0;
    while (p && (j < i - 1))
    {
        p = p->next; ++j;//p指向i+1的节点
    }
    if (!p || j > i - 1) return ERROR;
    LNode* s = new LNode;//新节点用于存放新元素
    s->data = e;//*s数据域放入e中
    s->next = p->next;//*s指针域指向后节点
    p->next = s;//*p指针域指向*s
    return OK;
} 
//插入（方案二）
Status ListInsert2(LinkList& L, int i, ElemType e)
{
    LNode* p=L;
    int a = 0;
    LinkList m = new LNode;
    if (i == 1)//当i就是1的时候
    {
        m->next = L->next;//指针域直接指向头节点
        m->data = e;//插入元素e于m的数据域中
        p->next = m;
    }
    for (p = L->next; p; p = p->next)
    {
        a++;
        if (a == i - 1)
        {
            m->next = L->next;//指针域指向下一个节点
            m->data = e;//插入元素e于m的数据域中
            p->next = m;      
        }
        return OK;
    }
}

//删除（方案一）
Status ListDelete1(LinkList& L, int i)
{
    LNode* p = L; int j = 0;
    if (!(p->next || j > i - 1)) return ERROR;
    while ((p->next && j < i - 1))
    {
        p = p->next; ++j;
    }
    if (p->next == NULL) return ERROR;
    LNode* q = p->next;//q用来临时存放要删除的元素节点
    p->next = q->next;//改变前驱节点从而彻底删除目标节点与表的关系
    delete q;
    q = NULL;
    return OK;
}

//删除（方案二）
Status ListDelete2(LinkList& L, int i)
{
    LNode* p;
    if (i == 1 && L->next != NULL)
    {
        LinkList a = L->next;//需要删除的就是第一个元素，或者整个表中只有一个元素
        L->next = a->next;
        delete a;
        return OK;
    }
    int m = 0;
    for (p = L->next; p; p = p->next)
    {
        m++;
        if (p->next == NULL) return ERROR;
        if (m == i - 1)
        {
            LinkList a = p->next;
            p->next = a->next;
            delete a;
            return OK;
        }
    }
    return 0;
}

//销毁
Status DestroyList(LinkList& L)
{
    /* 初始条件：线性表L已存在。操作结果：销毁线性表L */
    LinkList q;//拿到该线性表
    while (L)//从头开始逐个销毁元素直到整表销毁
    {
        q = L->next;//用指针指向头结点
        delete L;//也可以用free释放
        L = q;
    }
    return OK;
}

//逆转
void  inverse(LinkList& L)
{
    LNode* p, * q;

    p = L->next;
    L->next = NULL;
    while (p)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

//排序
void ListSort(LinkList& L)
{
    LinkList t1, t2;
    int temp;
    for (t1 = L->next; t1; t1 = t1->next)
    {
        for (t2 = L->next; t2; t2 = t2->next)
        {
            if (t1->data < t2->data)
            {
                temp = t1->data;
                t1->data = t2->data;
                t2->data = temp;
            }
        }
        // L=L->next;
    }
}
//----------------------------------------------------------------------------------------------
//单链表的创建
// A.前插法
void CreateList_H(LinkList& L, int n)
{
    L = new LNode; int i;//创键空链表和计数器
    L->next = NULL;
    for (i = 0; i < n; i++)
    {
        LNode* p = new LNode;
        cin >> p->data;//输入对应的元素值给对应的数据域
        p->next = L->next; L->next = p;//将新结点插入头结点之后
    }
}
//B.后插法
void Create_R(LinkList& L, int n)
{
    L = new LNode; int i;//创键空链表和计数器
    L->next = NULL;
    LNode* r = L;//尾指针指向头结点
    for (i = 0; i < n; i++)
    {
        LNode* p = new LNode;
        cin >> p->data;
        p->next = NULL; r->next = p;//*p插入尾结点r之后
        r = p;//r指向新的尾结点
    }
}

//打印
void ListPrint(LinkList L)
{
    LNode* p;
    for (p = L->next; p; p = p->next)
        cout << p->data << (p->next ? ' ' : '\n');
}

int main1()
{
    int i;
    ElemType e;
    LinkList L;
    string op;
    InitList(L);
    while (cin >> op) {
        if (op == "Empty")
            cout << (ListEmpty(L) ? "Empty" : "Not empty") << endl;
        else if (op == "Insert") {
            cin >> i >> e;
            if (ListInsert1(L, i, e) == ERROR)
                cout << "Insert failed" << endl;
            else
                ListPrint(L);
        }
        else if (op == "Length") {
            cout << "List length is " << ListLength(L) << endl;
        }
    }
    DestroyList(L);
    return 0;
}

