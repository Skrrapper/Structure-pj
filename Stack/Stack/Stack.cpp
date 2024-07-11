//#define _CRT_SECURE_NO_WARNINGS 1
///***链栈的实现***/
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
////算法3.5　链栈的初始化
//Status InitStack(LinkStack& s)   // 构造一个空栈 S，栈顶指针置空
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
////算法3.6　链栈的入栈
//Status Push(LinkStack& s, SElemType e)  //在栈顶插入元素e
//{
//    /****在此下面完成代码***************/
//    StackNode* p = new StackNode;
//    p->data= e;
//    p->next = s;
//    s = p;
//    return OK;
//    /***********************************/
//}
//
////算法3.7　链栈的出栈
//Status Pop(LinkStack& s, SElemType& e)  //删除S的栈顶元素，用e返回其值
//{
//    /****在此下面完成代码***************/
//    if (s == NULL) return ERROR;
//    e = s->data;
//    StackNode* p = s;
//    s = s->next;
//    delete p;
//    return OK;
//    /***********************************/
//}
////算法3.8　取链栈的栈顶元素
//SElemType GetTop(LinkStack s)  //返回S的栈顶元素，不修改栈顶指针
//{
//    /****在此下面完成代码***************/
//    if (s != NULL)
//        return s->data;
//     /***********************************/
//}
//
//bool StackEmpty(LinkStack s)
//{
//    /****在此下面完成代码***************/
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
////算法3.6　链栈的入栈
//Status Push(LinkStack& s, SElemType e)  //在栈顶插入元素e
//{
//    StackNode* newNode = new StackNode;
//    if (!newNode) {
//        return ERROR; // 内存分配失败
//    }
//    newNode->data = e;
//    newNode->next = s;
//    s = newNode;
//    return OK;
//}
//
////算法3.7　链栈的出栈
//Status Pop(LinkStack& s, SElemType& e)  //删除S的栈顶元素，用e返回其值
//{
//    if (s == NULL) {
//        return ERROR; // 栈空，无法出栈
//    }
//    StackNode* topNode = s;
//    e = topNode->data;
//    s = s->next;
//    delete topNode;
//    return OK;
//}
//
////算法3.8　取链栈的栈顶元素
//SElemType GetTop(LinkStack s)  //返回S的栈顶元素，不修改栈顶指针
//{
//    if (s == NULL) {
//        // 可以根据需求返回一个特定值或者抛出异常
//        // 这里简单返回0
//        return 0;
//    }
//    return s->data;
//}
//
//
//
