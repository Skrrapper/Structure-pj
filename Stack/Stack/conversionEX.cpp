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
////算法3.5　链栈的初始化
//Status InitStack(LinkStack& s)   // 构造一个空栈 S，栈顶指针置空
//{
//    s = NULL;
//    return OK;
//}
////销毁栈
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
////算法3.6　链栈的入栈
//Status Push(LinkStack& s, SElemType e)  //在栈顶插入元素e
//{
//    StackNode* p;
//    p = new StackNode;
//    p->data = e;
//    p->next = s;
//    s = p;
//    return OK;
//}
//
////算法3.7　链栈的出栈
//Status Pop(LinkStack& s)  //删除S的栈顶元素，用e返回其值
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
