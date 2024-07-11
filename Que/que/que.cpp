//#define _CRT_SECURE_NO_WARNINGS 1
///***ѭ�����л�������***/
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
//    QElemType* base;//��ʼ��ʱ��̬����洢�ռ�
//    int front;//ͷָ��
//    int rear;//βָ��
//} SqQueue;
//
////�㷨3.11��ѭ�����еĳ�ʼ��
//Status InitQueue(SqQueue& q)   //����һ���ն���Q
//{
//    q.base = new QElemType[MAXQSIZE]; //Ϊ���з���һ���������ΪMAXSIZE������ռ�
//    if (!q.base)
//        exit(OVERFLOW); //�洢����ʧ��
//    q.front = q.rear = 0; //ͷָ���βָ����Ϊ�㣬����Ϊ��
//    return OK;
//}
//
//void DestroyQueue(SqQueue& q)
//{
//    /* ���ٶ���Q��Q���ٴ��� */
//    if (q.base)
//        delete[]q.base;
//    q.base = NULL;
//    q.front = q.rear = 0;
//}
//
////�㷨3.12����ѭ�����еĳ���
//int QueueLength(SqQueue q)   //����Q��Ԫ�ظ����������еĳ���
//{
//    /****�ڴ�������ɴ���***************/
//    return(q.rear - q.front + MAXQSIZE) % MAXQSIZE;
//
//   /***********************************/
//}
//
//bool QueueEmpty(SqQueue q)
//{
//    /****�ڴ�������ɴ���***************/
//    return q.front == q.rear;
//
//   /***********************************/
//}
////�㷨3.13��ѭ�����е����
//Status EnQueue(SqQueue& q, QElemType e)   //����Ԫ��eΪQ���µĶ�βԪ��
//{
//    /****�ڴ�������ɴ���***************/
//    if ((q.rear + 1) % MAXQSIZE == q.front) return ERROR;
//    q.base[q.rear] = e;
//    q.rear = (q.rear + 1) % MAXQSIZE;
//    return OK;
//   /***********************************/
//}
//
////�㷨3.14��ѭ�����еĳ���
//Status DeQueue(SqQueue& q, QElemType& e)   //ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
//{
//    /****�ڴ�������ɴ���***************/
//    if (q.front == q.rear) return ERROR;
//    e = q.base[q.front];
//    q.front = (q.front + 1) % MAXQSIZE;
//    return OK;
//   /***********************************/
//}
//
////�㷨3.15��ȡѭ�����еĶ�ͷԪ��
//QElemType GetHead(SqQueue q)   //����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
//{
//    /****�ڴ�������ɴ���***************/
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

/***���ӵĻ�������***/
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
////- - - - - ���е���ʽ�洢�ṹ- - - - -
//typedef struct QNode {
//    QElemType data;
//    struct QNode* next;
//} QNode, * QueuePtr;
//typedef struct {
//    QueuePtr front; //��ͷָ��
//    QueuePtr rear; //��βָ��
//} LinkQueue;
//
////�㷨3.16�����ӵĳ�ʼ��
//Status InitQueue(LinkQueue& q)  //����һ���ն���Q
//{
//    q.front = q.rear = new QNode; //�����½����Ϊͷ��㣬��ͷ�Ͷ�βָ��ָ��˽��
//    q.front->next = NULL; //ͷ����ָ�����ÿ�
//    return OK;
//}
//
//void DestroyQueue(LinkQueue& q)
//{
//    /* ���ٶ���Q(���ۿշ����) */
//    for (QueuePtr p = q.front, q; p; ) {
//        q = p->next;
//        delete p;
//        p = q;
//    }
//}
//
//Status QueueEmpty(LinkQueue q)
//{
//    /****�ڴ�������ɴ���************/
//    return q.front == q.rear;
//
//    /***********************************/
//}
//
//int QueueLength(LinkQueue q)
//{
//    /****�ڴ�������ɴ���************/
//
//
//    /***********************************/
//}
//
////�㷨3.17�����ӵ����
//Status EnQueue(LinkQueue& q, QElemType e)  //����Ԫ��eΪQ���µĶ�βԪ��
//{
//    /****�ڴ�������ɴ���************/
//
//
//    /***********************************/
//}
//
////�㷨3.18�����ӵĳ���
//Status DeQueue(LinkQueue& q, QElemType& e)  //ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
//{
//    /****�ڴ�������ɴ���************/
//
//
//    /***********************************/
//}
//
////�㷨3.19��ȡ���ӵĶ�ͷԪ��
//QElemType GetHead(LinkQueue q)  //����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
//{
//    /****�ڴ�������ɴ���************/
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