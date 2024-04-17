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

//��ʼ��
Status InitList(LinkList& L)
{
    L = new LNode; //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ��㣬L���ǽ�����������Ҫ�õ���ָ��
    L->next = NULL; //ͷ����ָ�����ÿ�
    return OK;
}

//�ڴ�ռ俪��
int ListLength(LinkList L)
{
    int len = 0;
    LNode* p = L->next;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;//len�����ڴ�ռ�ĳ���
}

//ָ���ÿ�
bool ListEmpty(LinkList L)
{
    return L->next == NULL;
}

//ȡֵ������һ��
Status GetElem1(LinkList L, int i, ElemType& e)
{
    LNode* p = L->next; int j = 1;//��ʼ����j��Ϊ��������pָ����Ԫ�ڵ�
    while (p && j < i)//���ҵ�i���ڵ�
    {
        p = p->next;//û���ҵ���ָ����һ���ڵ�
        ++j;
    }
    //��������ڴ淶Χ��
    if (!p || j > i) return ERROR;
    e = p->data;//ȡ��i��Ԫ��������Ҳ����˵ȡ������Ҫ��ֵ
    return OK;
}
//ȡֵ����������
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

//����
LNode* LocateElem(LinkList L, ElemType e)//e��������Ҫ���ҵ�������
{
    LNode* p = L->next;//ָ����Ԫ�ڵ�
    while (p && p->data != e)//ֱ��pΪ�ջ���������Ϊe
        p = p->next;//ָ����һ�ڵ�
    return p;
}

//���루����һ��
Status ListInsert1(LinkList& L, int i, ElemType e)
{
    if (i < 1) return ERROR;
    LNode* p = L; int j = 0;
    while (p && (j < i - 1))
    {
        p = p->next; ++j;//pָ��i+1�Ľڵ�
    }
    if (!p || j > i - 1) return ERROR;
    LNode* s = new LNode;//�½ڵ����ڴ����Ԫ��
    s->data = e;//*s���������e��
    s->next = p->next;//*sָ����ָ���ڵ�
    p->next = s;//*pָ����ָ��*s
    return OK;
} 
//���루��������
Status ListInsert2(LinkList& L, int i, ElemType e)
{
    LNode* p=L;
    int a = 0;
    LinkList m = new LNode;
    if (i == 1)//��i����1��ʱ��
    {
        m->next = L->next;//ָ����ֱ��ָ��ͷ�ڵ�
        m->data = e;//����Ԫ��e��m����������
        p->next = m;
    }
    for (p = L->next; p; p = p->next)
    {
        a++;
        if (a == i - 1)
        {
            m->next = L->next;//ָ����ָ����һ���ڵ�
            m->data = e;//����Ԫ��e��m����������
            p->next = m;      
        }
        return OK;
    }
}

//ɾ��������һ��
Status ListDelete1(LinkList& L, int i)
{
    LNode* p = L; int j = 0;
    if (!(p->next || j > i - 1)) return ERROR;
    while ((p->next && j < i - 1))
    {
        p = p->next; ++j;
    }
    if (p->next == NULL) return ERROR;
    LNode* q = p->next;//q������ʱ���Ҫɾ����Ԫ�ؽڵ�
    p->next = q->next;//�ı�ǰ���ڵ�Ӷ�����ɾ��Ŀ��ڵ����Ĺ�ϵ
    delete q;
    q = NULL;
    return OK;
}

//ɾ������������
Status ListDelete2(LinkList& L, int i)
{
    LNode* p;
    if (i == 1 && L->next != NULL)
    {
        LinkList a = L->next;//��Ҫɾ���ľ��ǵ�һ��Ԫ�أ�������������ֻ��һ��Ԫ��
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

//����
Status DestroyList(LinkList& L)
{
    /* ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L */
    LinkList q;//�õ������Ա�
    while (L)//��ͷ��ʼ�������Ԫ��ֱ����������
    {
        q = L->next;//��ָ��ָ��ͷ���
        delete L;//Ҳ������free�ͷ�
        L = q;
    }
    return OK;
}

//��ת
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

//����
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
//������Ĵ���
// A.ǰ�巨
void CreateList_H(LinkList& L, int n)
{
    L = new LNode; int i;//����������ͼ�����
    L->next = NULL;
    for (i = 0; i < n; i++)
    {
        LNode* p = new LNode;
        cin >> p->data;//�����Ӧ��Ԫ��ֵ����Ӧ��������
        p->next = L->next; L->next = p;//���½�����ͷ���֮��
    }
}
//B.��巨
void Create_R(LinkList& L, int n)
{
    L = new LNode; int i;//����������ͼ�����
    L->next = NULL;
    LNode* r = L;//βָ��ָ��ͷ���
    for (i = 0; i < n; i++)
    {
        LNode* p = new LNode;
        cin >> p->data;
        p->next = NULL; r->next = p;//*p����β���r֮��
        r = p;//rָ���µ�β���
    }
}

//��ӡ
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

