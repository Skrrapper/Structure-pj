#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

#define MVNum 100     //��󶥵���
typedef string VerTexType; //���趥�����������Ϊ�ַ���
typedef int ArcType;             //����ߵ�Ȩֵ����Ϊ����

//------------ͼ���ڽӾ���------------------
typedef struct {
    VerTexType vexs[MVNum];            //�����
    ArcType arcs[MVNum][MVNum];      //�ڽӾ���
    int vexnum, arcnum;                //ͼ�ĵ�ǰ�����ͱ���
} Graph;

//�õ�����i������
VerTexType Vertexdata(const Graph& g, int i)
{
    return g.vexs[i];
}

int LocateVex(const Graph& g, VerTexType v)
{
    //ȷ����v��G�е�λ��
    for (int i = 0; i < g.vexnum; ++i)
        if (g.vexs[i] == v)
            return i;
    return -1;
}//LocateVex

int FirstAdjVex(const Graph& g, int v)
{
    //����v�ĵ�һ���ڽӵ��ţ�û�з���-1
    /****�ڴ�������ɴ���***************/
    int j;
    for (j = 0; j < g.vexnum; j++)
        if (g.arcs[v][j] == 1)
            return j;
    return -1;

    /***********************************/
}//FirstAdjVex

int NextAdjVex(const Graph& g, int v, int w)
{
    //����v�����w����һ���ڽӵ㣬û�з���-1
    /****�ڴ�������ɴ���***************/
    int i;
    for (i = w + 1; i < g.vexnum; i++)
    {
        if (g.arcs[v][i] == 1)
            return i;
    }
    return -1;

    /***********************************/
}//NextAdjVex

void CreateUDG(Graph& g)
{
    //�����ڽӾ����ʾ������������ͼG
    /****�ڴ�������ɴ���***************/
    int i, k, j; string v1, v2;
    cin >> g.vexnum >> g.arcnum;//�����ܶ��������ܱ���
    for (i = 0; i < g.vexnum; i++)//��������Ϣ
        cin >> g.vexs[i];
    for (i = 0; i < g.vexnum; i++)
    {
        for (j = 0; j < g.vexnum; j++)
        {
            g.arcs[i][j] = 0;
        }
    }
    for (i = 0; i < g.arcnum; i++)
    {
        cin >> v1 >> v2;
        k = LocateVex(g, v1); j = LocateVex(g, v2);
        g.arcs[k][j] = 1;
        g.arcs[j][k] = g.arcs[k][j];
    }

    /***********************************/
}//CreateUDN

void DestroyUDG(Graph& g)
{
    //you should do this
    g.arcnum = g.vexnum = 0;
}


//����ڽӾ���
void PrintUDG(const Graph& g)
{
    int i, j;
    cout << "    ";
    for (i = 0; i < g.vexnum; i++) {
        cout << setw(4) << g.vexs[i];
    }
    cout << endl;
    for (i = 0; i < g.vexnum; i++) {
        cout << setw(4) << g.vexs[i];
        for (j = 0; j < g.vexnum; j++) {
            cout << setw(4) << g.arcs[i][j];
        }
        cout << endl;
    }
}

int main()
{
    Graph g;
    CreateUDG(g);
    //�������������ڽӵ�
    for (int i = 0; i < g.vexnum; i++) {
        cout << Vertexdata(g, i) << ":";
        for (int w = FirstAdjVex(g, i); w >= 0; w = NextAdjVex(g, i, w)) {
            cout << ' ' << Vertexdata(g, w);
        }
        cout << endl;
    }
    PrintUDG(g);
    DestroyUDG(g);
    return 0;
}//main