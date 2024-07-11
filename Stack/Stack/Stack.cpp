//#define _CRT_SECURE_NO_WARNINGS 1
///***��ջ��ʵ��***/
//#include<iostream>
//#include<fstream>
//using namespace std;
//#define OK 1
//#define ERROR 0
//#define OVERFLOW - 2
//typedef int Status;
//typedef int SElemType;
//
//typedef struct StackNode {
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
//
//void DestroyStack(LinkStack& s)
//{
//    LinkStack next;
//    while (s) {
//        next = s->next;
//        delete s;
//        s = next;
//    }
//}
//
////�㷨3.6����ջ����ջ
//Status Push(LinkStack& s, SElemType e)  //��ջ������Ԫ��e
//{
//    /****�ڴ�������ɴ���***************/
//    StackNode* p = new StackNode;
//    p->data= e;
//    p->next = s;
//    s = p;
//    return OK;
//    /***********************************/
//}
//
////�㷨3.7����ջ�ĳ�ջ
//Status Pop(LinkStack& s, SElemType& e)  //ɾ��S��ջ��Ԫ�أ���e������ֵ
//{
//    /****�ڴ�������ɴ���***************/
//    if (s == NULL) return ERROR;
//    e = s->data;
//    StackNode* p = s;
//    s = s->next;
//    delete p;
//    return OK;
//    /***********************************/
//}
////�㷨3.8��ȡ��ջ��ջ��Ԫ��
//SElemType GetTop(LinkStack s)  //����S��ջ��Ԫ�أ����޸�ջ��ָ��
//{
//    /****�ڴ�������ɴ���***************/
//    if (s != NULL)
//        return s->data;
//     /***********************************/
//}
//
//bool StackEmpty(LinkStack s)
//{
//    /****�ڴ�������ɴ���***************/
//    return s->next == NULL;
//
//    /***********************************/
//}
//
//void PrintStack(LinkStack s)
//{
//    for (LinkStack p = s; p; p = p->next) 
//    {
//        cout << p->data;
//        if (p->next)
//            cout << ' ';
//    }
//    cout << endl;
//}
//
//int main()
//{
//    LinkStack s;
//    SElemType e;
//    string op;
//    InitStack(s);
//    while (cin >> op) {
//        if (op == "Push") {
//            cin >> e;
//            if (Push(s, e) == ERROR)
//                cout << "Push failure\n";
//            else
//                PrintStack(s);
//        }
//        else  if (op == "Pop") {
//            if (Pop(s, e) == ERROR)
//                cout << "Pop failure\n";
//            else
//                cout << e << " is poped\n";
//        }
//        else if (op == "Empty") {
//            cout << "Stack is " << (StackEmpty(s) ? "empty" : "not empty") << endl;
//        }
//        else if (op == "GetTop") {
//            if (StackEmpty(s)) {
//                cout << "GetTop failure\n";
//            }
//            else
//                cout << "The top element is " << GetTop(s) << endl;
//        }
//    }
//    DestroyStack(s);
//    return 0;
//}
//
////�㷨3.6����ջ����ջ
//Status Push(LinkStack& s, SElemType e)  //��ջ������Ԫ��e
//{
//    StackNode* newNode = new StackNode;
//    if (!newNode) {
//        return ERROR; // �ڴ����ʧ��
//    }
//    newNode->data = e;
//    newNode->next = s;
//    s = newNode;
//    return OK;
//}
//
////�㷨3.7����ջ�ĳ�ջ
//Status Pop(LinkStack& s, SElemType& e)  //ɾ��S��ջ��Ԫ�أ���e������ֵ
//{
//    if (s == NULL) {
//        return ERROR; // ջ�գ��޷���ջ
//    }
//    StackNode* topNode = s;
//    e = topNode->data;
//    s = s->next;
//    delete topNode;
//    return OK;
//}
//
////�㷨3.8��ȡ��ջ��ջ��Ԫ��
//SElemType GetTop(LinkStack s)  //����S��ջ��Ԫ�أ����޸�ջ��ָ��
//{
//    if (s == NULL) {
//        // ���Ը������󷵻�һ���ض�ֵ�����׳��쳣
//        // ����򵥷���0
//        return 0;
//    }
//    return s->data;
//}
//
//
//
