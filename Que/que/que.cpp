//#define _CRT_SECURE_NO_WARNINGS 1
///***循环队列基本操作***/
//
//#include<iostream>
//#include<cstdlib>
//#include<cstdio>
//using namespace std;
//
//#define MAXQSIZE 6
//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//typedef int QElemType;
//typedef int Status;
//
//typedef struct {
//    QElemType* base;//初始化时动态分配存储空间
//    int front;//头指针
//    int rear;//尾指针
//} SqQueue;
//
////算法3.11　循环队列的初始化
//Status InitQueue(SqQueue& q)   //构造一个空队列Q
//{
//    q.base = new QElemType[MAXQSIZE]; //为队列分配一个最大容量为MAXSIZE的数组空间
//    if (!q.base)
//        exit(OVERFLOW); //存储分配失败
//    q.front = q.rear = 0; //头指针和尾指针置为零，队列为空
//    return OK;
//}
//
//void DestroyQueue(SqQueue& q)
//{
//    /* 销毁队列Q，Q不再存在 */
//    if (q.base)
//        delete[]q.base;
//    q.base = NULL;
//    q.front = q.rear = 0;
//}
//
////算法3.12　求循环队列的长度
//int QueueLength(SqQueue q)   //返回Q的元素个数，即队列的长度
//{
//    /****在此下面完成代码***************/
//    return(q.rear - q.front + MAXQSIZE) % MAXQSIZE;
//
//   /***********************************/
//}
//
//bool QueueEmpty(SqQueue q)
//{
//    /****在此下面完成代码***************/
//    return q.front == q.rear;
//
//   /***********************************/
//}
////算法3.13　循环队列的入队
//Status EnQueue(SqQueue& q, QElemType e)   //插入元素e为Q的新的队尾元素
//{
//    /****在此下面完成代码***************/
//    if ((q.rear + 1) % MAXQSIZE == q.front) return ERROR;
//    q.base[q.rear] = e;
//    q.rear = (q.rear + 1) % MAXQSIZE;
//    return OK;
//   /***********************************/
//}
//
////算法3.14　循环队列的出队
//Status DeQueue(SqQueue& q, QElemType& e)   //删除Q的队头元素，用e返回其值
//{
//    /****在此下面完成代码***************/
//    if (q.front == q.rear) return ERROR;
//    e = q.base[q.front];
//    q.front = (q.front + 1) % MAXQSIZE;
//    return OK;
//   /***********************************/
//}
//
////算法3.15　取循环队列的队头元素
//QElemType GetHead(SqQueue q)   //返回Q的队头元素，不修改队头指针
//{
//    /****在此下面完成代码***************/
//    if (q.front != q.rear)
//        return q.base[q.front];
//    /***********************************/
//}
//
//void PrintQueue(SqQueue q)
//{
//    for (int i = q.front; i != q.rear; i = (i + 1) % MAXQSIZE) {
//        if (i != q.front)
//            cout << ' ';
//        cout << q.base[i];
//    }
//    cout << endl;
//}
//int main()
//{
//    SqQueue q;
//    QElemType e;
//    string op;
//    InitQueue(q);
//    while (cin >> op) {
//        if (op == "Empty") {
//            cout << "Queue is " << (QueueEmpty(q) ? "empty" : "not empty") << endl;
//        }
//        else if (op == "Length") {
//            cout << "The queue length is " << QueueLength(q) << endl;
//        }
//        else if (op == "EnQueue") {
//            cin >> e;
//            if (EnQueue(q, e) == ERROR)
//                cout << "EnQueue failure\n";
//            else
//                PrintQueue(q);
//        }
//        else if (op == "DeQueue") {
//            if (DeQueue(q, e) == ERROR)
//                cout << "DeQueue failure\n";
//            else
//                PrintQueue(q);
//        }
//        else if (op == "Head") {
//            if (QueueEmpty(q)) {
//                cout << "GetHead failure\n";
//            }
//            else
//                cout << "The front element is " << GetHead(q) << endl;
//        }
//    }
//    DestroyQueue(q);
//    return 0;
//}

/***链队的基本操作***/
//#include<iostream>
//#include<cstdlib>
//#include<cstdio>
//using namespace std;
//
//#define MAXQSIZE 6
//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//typedef int QElemType;
//typedef int Status;
//
////- - - - - 队列的链式存储结构- - - - -
//typedef struct QNode {
//    QElemType data;
//    struct QNode* next;
//} QNode, * QueuePtr;
//typedef struct {
//    QueuePtr front; //队头指针
//    QueuePtr rear; //队尾指针
//} LinkQueue;
//
////算法3.16　链队的初始化
//Status InitQueue(LinkQueue& q)  //构造一个空队列Q
//{
//    q.front = q.rear = new QNode; //生成新结点作为头结点，队头和队尾指针指向此结点
//    q.front->next = NULL; //头结点的指针域置空
//    return OK;
//}
//
//void DestroyQueue(LinkQueue& q)
//{
//    /* 销毁队列Q(无论空否均可) */
//    for (QueuePtr p = q.front, q; p; ) {
//        q = p->next;
//        delete p;
//        p = q;
//    }
//}
//
//Status QueueEmpty(LinkQueue q)
//{
//    /****在此下面完成代码************/
//    return q.front == q.rear;
//
//    /***********************************/
//}
//
//int QueueLength(LinkQueue q)
//{
//    /****在此下面完成代码************/
//
//
//    /***********************************/
//}
//
////算法3.17　链队的入队
//Status EnQueue(LinkQueue& q, QElemType e)  //插入元素e为Q的新的队尾元素
//{
//    /****在此下面完成代码************/
//
//
//    /***********************************/
//}
//
////算法3.18　链队的出队
//Status DeQueue(LinkQueue& q, QElemType& e)  //删除Q的队头元素，用e返回其值
//{
//    /****在此下面完成代码************/
//
//
//    /***********************************/
//}
//
////算法3.19　取链队的队头元素
//QElemType GetHead(LinkQueue q)  //返回Q的队头元素，不修改队头指针
//{
//    /****在此下面完成代码************/
//
//
//    /***********************************/
//}
//
//void PrintQueue(LinkQueue q)
//{
//    QueuePtr p;
//    for (p = q.front->next; p; p = p->next) {
//
//        cout << p->data;
//        if (p->next != NULL)
//            cout << ' ';
//    }
//    cout << endl;
//}
//int main()
//{
//    //freopen("linkqueue.out", "w", stdout);
//    LinkQueue q;
//    QElemType e;
//    string op;
//
//    InitQueue(q);
//    while (cin >> op) {
//        if (op == "Empty") {
//            cout << "Queue is " << (QueueEmpty(q) ? "empty" : "not empty") << endl;
//        }
//        else if (op == "Length") {
//            cout << "The queue length is " << QueueLength(q) << endl;
//        }
//        else if (op == "EnQueue") {
//            cin >> e;
//            if (EnQueue(q, e) == ERROR)
//                cout << "EnQueue failure\n";
//            else
//                PrintQueue(q);
//        }
//        else if (op == "DeQueue") {
//            if (DeQueue(q, e) == ERROR)
//                cout << "DeQueue failure\n";
//            else
//                PrintQueue(q);
//        }
//        else if (op == "Head") {
//            if (QueueEmpty(q)) {
//                cout << "GetHead failure\n";
//            }
//            else
//                cout << "The front element is " << GetHead(q) << endl;
//        }
//    }
//    DestroyQueue(q);
//    return 0;
//}