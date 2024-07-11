#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

#define MVNum 100     //最大顶点数
typedef string VerTexType; //假设顶点的数据类型为字符串
typedef int ArcType;             //假设边的权值类型为整型

//------------图的邻接矩阵------------------
typedef struct {
    VerTexType vexs[MVNum];            //顶点表
    ArcType arcs[MVNum][MVNum];      //邻接矩阵
    int vexnum, arcnum;                //图的当前点数和边数
} Graph;

//得到顶点i的数据
VerTexType Vertexdata(const Graph& g, int i)
{
    return g.vexs[i];
}

int LocateVex(const Graph& g, VerTexType v)
{
    //确定点v在G中的位置
    for (int i = 0; i < g.vexnum; ++i)
        if (g.vexs[i] == v)
            return i;
    return -1;
}//LocateVex

int FirstAdjVex(const Graph& g, int v)
{
    //返回v的第一个邻接点编号，没有返回-1
    /****在此下面完成代码***************/
    int j;
    for (j = 0; j < g.vexnum; j++)
        if (g.arcs[v][j] == 1)
            return j;
    return -1;

    /***********************************/
}//FirstAdjVex

int NextAdjVex(const Graph& g, int v, int w)
{
    //返回v相对于w的下一个邻接点，没有返回-1
    /****在此下面完成代码***************/
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
    //采用邻接矩阵表示法，创建无向图G
    /****在此下面完成代码***************/
    int i, k, j; string v1, v2;
    cin >> g.vexnum >> g.arcnum;//输入总顶点数和总边数
    for (i = 0; i < g.vexnum; i++)//输入点的信息
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


//输出邻接矩阵
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
    //输出各个顶点的邻接点
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