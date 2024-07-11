//#define _CRT_SECURE_NO_WARNINGS 1
///***˳��ջ��ʵ��***/
//#include<iostream>
//#include<cstdlib>
//#include<cstdio>
//using namespace std;
//
////˳��ջ����
//#define OK 1
//#define ERROR 0
//#define OVERFLOW - 2
//#define MAXSIZE  5 //˳��ջ�洢�ռ�ĳ�ʼ������
//typedef int Status;
//typedef int SElemType;
//
//typedef struct {
//    SElemType* base;//ջ��ָ��
//    SElemType* top;//ջ��ָ��
//    int stacksize;//ջ���õ��������
//} SqStack;
//
////�㷨3.1��˳��ջ�ĳ�ʼ��
//Status InitStack(SqStack& s)
//{
//    //����һ����ջS
//    s.base = new SElemType[MAXSIZE];//Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
//    if (!s.base)
//        exit(OVERFLOW); //�洢����ʧ��
//    s.top = s.base; //top��ʼΪbase����ջ
//    s.stacksize = MAXSIZE; //stacksize��Ϊջ���������MAXSIZE
//    return OK;
//}
//
//void DestroyStack(SqStack& s)
//{
//    /* ����ջS��S���ٴ��� */
//    delete[]s.base;
//    s.base = s.top = NULL;
//    s.stacksize = 0;
//}
//
////�㷨3.2��˳��ջ����ջ
//Status Push(SqStack& s, SElemType e)
//{
//    /****�ڴ�������ɴ���***************/
//    if (s.top - s.base == s.stacksize) return ERROR;
//    *s.top++ = e;
//    return OK;
//    /***********************************/
//}
//
////�㷨3.3��˳��ջ�ĳ�ջ
//Status Pop(SqStack& s, SElemType& e)
//{
//    /****�ڴ�������ɴ���***************/
//    if (s.top - s.base == s.stacksize) return ERROR;
//    e = *--s.top;
//    return OK;
//   /***********************************/
//}
//
////�㷨3.4��ȡ˳��ջ��ջ��Ԫ��
//SElemType GetTop(SqStack s)  //����S��ջ��Ԫ�أ����޸�ջ��ָ��
//{
//    /****�ڴ�������ɴ���***************/
//    if (s.top != s.base)
//        return *(s.top - 1);
//   /***********************************/
//}
//
//bool StackEmpty(SqStack s)
//{
//    /****�ڴ�������ɴ���***************/
//    return s.top = s.base;
//   /***********************************/
//}
//
//void PrintStack(SqStack s)
//{
//    for (SElemType* top = s.top - 1; top >= s.base; top--) {
//        cout << (*top);
//        if (top != s.base)
//            cout << ' ';
//    }
//    cout << endl;
//}
//
////int main()
////{
////    SqStack s;
////    SElemType e;
////    string op;
////    InitStack(s);
////    while (cin >> op) {
////        if (op == "Push") {
////            cin >> e;
////            if (Push(s, e) == ERROR)
////                cout << "Push failure\n";
////            else
////                PrintStack(s);
////        }
////        else  if (op == "Pop") {
////            if (Pop(s, e) == ERROR)
////                cout << "Pop failure\n";
////            else
////                cout << e << " is poped\n";
////        }
////        else if (op == "Empty") {
////            cout << "Stack is " << (StackEmpty(s) ? "empty" : "not empty") << endl;
////        }
////        else if (op == "GetTop") {
////            if (StackEmpty(s)) {
////                cout << "GetTop failure\n";
////            }
////            else
////                cout << "The top element is " << GetTop(s) << endl;
////        }
////    }
////    DestroyStack(s);
////    return 0;
////}
//
//
//
//
////�㷨3.2��˳��ջ����ջ
//Status Push(SqStack& s, SElemType e)
//{
//    if (s.top - s.base == s.stacksize) {
//        return ERROR; // ջ��
//    }
//    *(s.top++) = e;
//    return OK;
//}
//
////�㷨3.3��˳��ջ�ĳ�ջ
//Status Pop(SqStack& s, SElemType& e)
//{
//    if (s.top == s.base) {
//        return ERROR; // ջ��
//    }
//    e = *(--s.top);
//    return OK;
//}
//
////�㷨3.4��ȡ˳��ջ��ջ��Ԫ��
//SElemType GetTop(SqStack s)  //����S��ջ��Ԫ�أ����޸�ջ��ָ��
//{
//    if (s.top == s.base) {
//        // ���Ը������󷵻�һ���ض�ֵ�����׳��쳣
//        // ����򵥷���0
//        return 0;
//    }
//    return *(s.top - 1);
//}
//
//bool StackEmpty(SqStack s)
//{
//    return s.top == s.base;
//}
//
//void PrintStack(SqStack s)
//{
//    for (SElemType* top = s.top - 1; top >= s.base; top--) {
//        cout << (*top);
//        if (top != s.base)
//            cout << ' ';
//    }
//    cout << endl;
//}
//
////int main()
////{
////    SqStack s;
////    SElemType e;
////    string op;
////    InitStack(s);
////    while (cin >> op) {
////        if (op == "Push") {
////            cin >> e;
////            if (Push(s, e) == ERROR)
////                cout << "Push failure\n";
////            else
////                PrintStack(s);
////        }
////        else  if (op == "Pop") {
////            if (Pop(s, e) == ERROR)
////                cout << "Pop failure\n";
////            else
////                cout << e << " is popped\n";
////        }
////        else if (op == "Empty") {
////            cout << "Stack is " << (StackEmpty(s) ? "empty" : "not empty") << endl;
////        }
////        else if (op == "GetTop") {
////            if (StackEmpty(s)) {
////                cout << "GetTop failure\n";
////            }
////            else
////                cout << "The top element is " << GetTop(s) << endl;
////        }
////    }
////    DestroyStack(s);
////    return 0;
////}
