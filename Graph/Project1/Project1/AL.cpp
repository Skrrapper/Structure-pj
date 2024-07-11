
//ͼ���ڽӱ�洢��ʾ

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MVNum 100         // ��󶥵���
#define OK 1              // �����ɹ����صı�־

typedef string VerTexType; // ������Ϣ����
typedef int OtherInfo;    // �ͱ���ص���Ϣ����

//- - - - -ͼ���ڽӱ�洢��ʾ- - - - -
typedef struct ArcNode {                // �߽��
    int adjvex;                          // �ñ���ָ��Ķ����λ��
    struct ArcNode* nextarc;             // ָ����һ���ߵ�ָ��
    OtherInfo info;                      // �ͱ���ص���Ϣ
} ArcNode;

typedef struct VNode {
    VerTexType data;                     // ������Ϣ
    ArcNode* firstarc;                   // ָ���һ�������ö���ıߵ�ָ��
} VNode, AdjList[MVNum];                // AdjList��ʾ�ڽӱ�����

typedef struct {
    AdjList vertices;                    // �ڽӱ�
    int vexnum, arcnum;                  // ͼ�ĵ�ǰ�������ͱ���
} Graph;

// �õ�����i������
VerTexType Vertexdata(const Graph& g, int i)
{
    return g.vertices[i].data;           // ���ض���i������
}

// ȷ����v��G�е�λ��
int LocateVex(const Graph& g, VerTexType v)
{
    for (int i = 0; i < g.vexnum; ++i)     // �������ж���
        if (g.vertices[i].data == v)        // ����ҵ�����v
            return i;                       // ���ض����λ��
    return -1;                            // ���δ�ҵ�������-1
}

// ����v�ĵ�һ���ڽӶ��㡣��������G��û���ڽӱ��㣬�򷵻�-1��
int FirstAdjVex(const Graph& g, int v)
{
    if (g.vertices[v].firstarc != nullptr) // �������v���ڽӱ�
        return g.vertices[v].firstarc->adjvex; // ���ص�һ���ڽӶ����λ��
    return -1;                              // ���򷵻�-1
}

// ����v�ģ������w�ģ���һ���ڽӶ��㡣
int NextAdjVex(const Graph& g, int v, int w)
{
    ArcNode* p = g.vertices[v].firstarc;  // ��ȡ����v�ĵ�һ���ڽӱ�
    while (p != nullptr) {                // �����ڽӱ�
        if (p->adjvex == w) {              // �ҵ�����w
            if (p->nextarc != nullptr)      // ���������һ���ڽӶ���
                return p->nextarc->adjvex;   // ������һ���ڽӶ����λ��
            else
                return -1;                   // ���򷵻�-1
        }
        p = p->nextarc;                    // �ƶ�����һ���ڽӶ���
    }
    return -1;                            // ���δ�ҵ�������-1
}

// ��ÿ��������������򣬰������Ŵ�С��������
void sort(ArcNode* arclist)
{
    vector<int> adjVertices;              // ����һ�������洢�ڽӶ���
    ArcNode* p = arclist;                 // ��ȡ�����ͷָ��
    while (p != nullptr) {                // ��������
        adjVertices.push_back(p->adjvex);  // ���ڽӶ����������
        p = p->nextarc;                    // �ƶ�����һ���ڵ�
    }
    std::sort(adjVertices.begin(), adjVertices.end()); // ��������������

    p = arclist;                          // ��������ָ��
    for (int i = 0; i < adjVertices.size(); i++) { // ���������������
        p->adjvex = adjVertices[i];        // ���������еĶ�����
        p = p->nextarc;                    // �ƶ�����һ���ڵ�
    }
}

// �����ڽӱ��ʾ������������ͼG
int CreateUDG(Graph& g)
{
    cin >> g.vexnum >> g.arcnum;          // ���붥�����ͱ���

    for (int i = 0; i < g.vexnum; ++i) {  // ��ʼ��ÿ������
        cin >> g.vertices[i].data;         // ���붥����Ϣ
        g.vertices[i].firstarc = nullptr;  // ��ʼ���ڽӱ�Ϊ��
    }

    string v1, v2;
    for (int i = 0; i < g.arcnum; ++i) {  // ��ȡÿ����
        cin >> v1 >> v2;                   // ����ߵ���������
        int m = LocateVex(g, v1);          // ���Ҷ���v1��λ��
        int n = LocateVex(g, v2);          // ���Ҷ���v2��λ��

        ArcNode* p1 = new ArcNode;         // �����µı߽��
        p1->adjvex = n;                    // �����ڽӶ����λ��
        p1->nextarc = g.vertices[m].firstarc; // �����ڽӱ��ͷ��
        g.vertices[m].firstarc = p1;       // ����ͷָ��

        ArcNode* p2 = new ArcNode;         // ������һ������ߵı߽��
        p2->adjvex = m;                    // �����ڽӶ����λ��
        p2->nextarc = g.vertices[n].firstarc; // �����ڽӱ��ͷ��
        g.vertices[n].firstarc = p2;       // ����ͷָ��
    }

    for (int i = 0; i < g.vexnum; ++i) {  // ��ÿ��������ڽӱ�����
        sort(g.vertices[i].firstarc);      // ȷ�����򣬲������������
    }
    return OK;                            // ���ز����ɹ�
}

// ����ͼ���ͷŶ�̬������ڴ�
void DestroyUDG(Graph& g)
{
    for (int i = 0; i < g.vexnum; ++i) {  // ����ÿ������
        ArcNode* p = g.vertices[i].firstarc; // ��ȡ������ڽӱ�
        while (p != nullptr) {             // �����ڽӱ�
            ArcNode* q = p->nextarc;        // ������һ���ڵ�ָ��
            delete p;                       // ɾ����ǰ�ڵ�
            p = q;                          // �ƶ�����һ���ڵ�
        }
    }
}

int main()
{
    Graph g;                              // ����һ��ͼ��ʵ��
    CreateUDG(g);                         // ��������ͼ
    // �������������ڽӵ�
    for (int i = 0; i < g.vexnum; i++) {   // ����ÿ������
        cout << Vertexdata(g, i) << ":";   // ���������Ϣ
        for (int w = FirstAdjVex(g, i); w >= 0; w = NextAdjVex(g, i, w)) { // �����ڽӶ���
            cout << ' ' << Vertexdata(g, w); // ����ڽӶ�����Ϣ
        }
        cout << endl;                      // ����
    }
    DestroyUDG(g);                        // ����ͼ���ͷ��ڴ�
    return 0;                             // ����0���������
}
