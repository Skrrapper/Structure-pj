//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<fstream>
//using namespace std;
//
//#define OK 1
//#define ERROR 0
//#define OVERFLOW - 2
//typedef int Status;
//typedef int SElemType;
//
//typedef struct StackNode
//{
//    SElemType data;
//    struct StackNode* next;
//} StackNode, * LinkStack;
//
////�㷨3.5����ջ�ĳ�ʼ��
//Status InitStack(LinkStack& s)   // ����һ����ջ S��ջ��ָ���ÿ�
//{
//    s = NULL;
//    return OK;
//}
////����ջ
//void DestroyStack(LinkStack& s)
//{
//    LinkStack next;
//    while (s)
//    {
//        next = s->next;
//        delete s;
//        s = next;
//    }
//}
//
////�㷨3.6����ջ����ջ
//Status Push(LinkStack& s, SElemType e)  //��ջ������Ԫ��e
//{
//    StackNode* p;
//    p = new StackNode;
//    p->data = e;
//    p->next = s;
//    s = p;
//    return OK;
//}
//
////�㷨3.7����ջ�ĳ�ջ
//Status Pop(LinkStack& s)  //ɾ��S��ջ��Ԫ�أ���e������ֵ
//{
//    LinkStack p;
//    if (s == NULL)
//        return ERROR;
//    p = s;
//    s = s->next;
//    cout << p->data;
//    delete p;
//    return OK;
//}
//
//
//void conversion(LinkStack s, int n)
//{
//    SElemType e;
//    while (n)
//    {
//        Push(s, n % 8);
//        n /= 8;
//    }
//    while (s)
//    {
//        Pop(s);
//    }
//    cout << endl;
//}
//
////int main()
////{
////    int n;
////    LinkStack s;
////    SElemType e;
////    InitStack(s);
////
////    while (cin >> n)
////    {
////        conversion(s, n);
////    }
////
////    DestroyStack(s);
////    return 0;
////}
//
