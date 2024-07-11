//#define _CRT_SECURE_NO_WARNINGS 1
///***顺序栈的实现***/
//#include<iostream>
//#include<cstdlib>
//#include<cstdio>
//using namespace std;
//
////顺序栈定义
//#define OK 1
//#define ERROR 0
//#define OVERFLOW - 2
//#define MAXSIZE  5 //顺序栈存储空间的初始分配量
//typedef int Status;
//typedef int SElemType;
//
//typedef struct {
//    SElemType* base;//栈底指针
//    SElemType* top;//栈顶指针
//    int stacksize;//栈可用的最大容量
//} SqStack;
//
////算法3.1　顺序栈的初始化
//Status InitStack(SqStack& s)
//{
//    //构造一个空栈S
//    s.base = new SElemType[MAXSIZE];//为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
//    if (!s.base)
//        exit(OVERFLOW); //存储分配失败
//    s.top = s.base; //top初始为base，空栈
//    s.stacksize = MAXSIZE; //stacksize置为栈的最大容量MAXSIZE
//    return OK;
//}
//
//void DestroyStack(SqStack& s)
//{
//    /* 销毁栈S，S不再存在 */
//    delete[]s.base;
//    s.base = s.top = NULL;
//    s.stacksize = 0;
//}
//
////算法3.2　顺序栈的入栈
//Status Push(SqStack& s, SElemType e)
//{
//    /****在此下面完成代码***************/
//    if (s.top - s.base == s.stacksize) return ERROR;
//    *s.top++ = e;
//    return OK;
//    /***********************************/
//}
//
////算法3.3　顺序栈的出栈
//Status Pop(SqStack& s, SElemType& e)
//{
//    /****在此下面完成代码***************/
//    if (s.top - s.base == s.stacksize) return ERROR;
//    e = *--s.top;
//    return OK;
//   /***********************************/
//}
//
////算法3.4　取顺序栈的栈顶元素
//SElemType GetTop(SqStack s)  //返回S的栈顶元素，不修改栈顶指针
//{
//    /****在此下面完成代码***************/
//    if (s.top != s.base)
//        return *(s.top - 1);
//   /***********************************/
//}
//
//bool StackEmpty(SqStack s)
//{
//    /****在此下面完成代码***************/
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
////算法3.2　顺序栈的入栈
//Status Push(SqStack& s, SElemType e)
//{
//    if (s.top - s.base == s.stacksize) {
//        return ERROR; // 栈满
//    }
//    *(s.top++) = e;
//    return OK;
//}
//
////算法3.3　顺序栈的出栈
//Status Pop(SqStack& s, SElemType& e)
//{
//    if (s.top == s.base) {
//        return ERROR; // 栈空
//    }
//    e = *(--s.top);
//    return OK;
//}
//
////算法3.4　取顺序栈的栈顶元素
//SElemType GetTop(SqStack s)  //返回S的栈顶元素，不修改栈顶指针
//{
//    if (s.top == s.base) {
//        // 可以根据需求返回一个特定值或者抛出异常
//        // 这里简单返回0
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
