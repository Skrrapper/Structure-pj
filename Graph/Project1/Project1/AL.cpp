
//图的邻接表存储表示

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MVNum 100         // 最大顶点数
#define OK 1              // 操作成功返回的标志

typedef string VerTexType; // 顶点信息类型
typedef int OtherInfo;    // 和边相关的信息类型

//- - - - -图的邻接表存储表示- - - - -
typedef struct ArcNode {                // 边结点
    int adjvex;                          // 该边所指向的顶点的位置
    struct ArcNode* nextarc;             // 指向下一条边的指针
    OtherInfo info;                      // 和边相关的信息
} ArcNode;

typedef struct VNode {
    VerTexType data;                     // 顶点信息
    ArcNode* firstarc;                   // 指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum];                // AdjList表示邻接表类型

typedef struct {
    AdjList vertices;                    // 邻接表
    int vexnum, arcnum;                  // 图的当前顶点数和边数
} Graph;

// 得到顶点i的数据
VerTexType Vertexdata(const Graph& g, int i)
{
    return g.vertices[i].data;           // 返回顶点i的数据
}

// 确定点v在G中的位置
int LocateVex(const Graph& g, VerTexType v)
{
    for (int i = 0; i < g.vexnum; ++i)     // 遍历所有顶点
        if (g.vertices[i].data == v)        // 如果找到顶点v
            return i;                       // 返回顶点的位置
    return -1;                            // 如果未找到，返回-1
}

// 返回v的第一个邻接顶点。若顶点在G中没有邻接表顶点，则返回-1。
int FirstAdjVex(const Graph& g, int v)
{
    if (g.vertices[v].firstarc != nullptr) // 如果顶点v有邻接表
        return g.vertices[v].firstarc->adjvex; // 返回第一个邻接顶点的位置
    return -1;                              // 否则返回-1
}

// 返回v的（相对于w的）下一个邻接顶点。
int NextAdjVex(const Graph& g, int v, int w)
{
    ArcNode* p = g.vertices[v].firstarc;  // 获取顶点v的第一个邻接表
    while (p != nullptr) {                // 遍历邻接表
        if (p->adjvex == w) {              // 找到顶点w
            if (p->nextarc != nullptr)      // 如果存在下一个邻接顶点
                return p->nextarc->adjvex;   // 返回下一个邻接顶点的位置
            else
                return -1;                   // 否则返回-1
        }
        p = p->nextarc;                    // 移动到下一个邻接顶点
    }
    return -1;                            // 如果未找到，返回-1
}

// 对每个顶点的链表排序，按顶点编号从小到大排列
void sort(ArcNode* arclist)
{
    vector<int> adjVertices;              // 创建一个向量存储邻接顶点
    ArcNode* p = arclist;                 // 获取链表的头指针
    while (p != nullptr) {                // 遍历链表
        adjVertices.push_back(p->adjvex);  // 将邻接顶点加入向量
        p = p->nextarc;                    // 移动到下一个节点
    }
    std::sort(adjVertices.begin(), adjVertices.end()); // 对向量进行排序

    p = arclist;                          // 重置链表指针
    for (int i = 0; i < adjVertices.size(); i++) { // 遍历已排序的向量
        p->adjvex = adjVertices[i];        // 更新链表中的顶点编号
        p = p->nextarc;                    // 移动到下一个节点
    }
}

// 采用邻接表表示法，创建无向图G
int CreateUDG(Graph& g)
{
    cin >> g.vexnum >> g.arcnum;          // 输入顶点数和边数

    for (int i = 0; i < g.vexnum; ++i) {  // 初始化每个顶点
        cin >> g.vertices[i].data;         // 输入顶点信息
        g.vertices[i].firstarc = nullptr;  // 初始化邻接表为空
    }

    string v1, v2;
    for (int i = 0; i < g.arcnum; ++i) {  // 读取每条边
        cin >> v1 >> v2;                   // 输入边的两个顶点
        int m = LocateVex(g, v1);          // 查找顶点v1的位置
        int n = LocateVex(g, v2);          // 查找顶点v2的位置

        ArcNode* p1 = new ArcNode;         // 创建新的边结点
        p1->adjvex = n;                    // 设置邻接顶点的位置
        p1->nextarc = g.vertices[m].firstarc; // 插入邻接表的头部
        g.vertices[m].firstarc = p1;       // 更新头指针

        ArcNode* p2 = new ArcNode;         // 创建另一条无向边的边结点
        p2->adjvex = m;                    // 设置邻接顶点的位置
        p2->nextarc = g.vertices[n].firstarc; // 插入邻接表的头部
        g.vertices[n].firstarc = p2;       // 更新头指针
    }

    for (int i = 0; i < g.vexnum; ++i) {  // 对每个顶点的邻接表排序
        sort(g.vertices[i].firstarc);      // 确保有序，不依赖输入次序
    }
    return OK;                            // 返回操作成功
}

// 销毁图，释放动态分配的内存
void DestroyUDG(Graph& g)
{
    for (int i = 0; i < g.vexnum; ++i) {  // 遍历每个顶点
        ArcNode* p = g.vertices[i].firstarc; // 获取顶点的邻接表
        while (p != nullptr) {             // 遍历邻接表
            ArcNode* q = p->nextarc;        // 保存下一个节点指针
            delete p;                       // 删除当前节点
            p = q;                          // 移动到下一个节点
        }
    }
}

int main()
{
    Graph g;                              // 创建一个图的实例
    CreateUDG(g);                         // 创建无向图
    // 输出各个顶点的邻接点
    for (int i = 0; i < g.vexnum; i++) {   // 遍历每个顶点
        cout << Vertexdata(g, i) << ":";   // 输出顶点信息
        for (int w = FirstAdjVex(g, i); w >= 0; w = NextAdjVex(g, i, w)) { // 遍历邻接顶点
            cout << ' ' << Vertexdata(g, w); // 输出邻接顶点信息
        }
        cout << endl;                      // 换行
    }
    DestroyUDG(g);                        // 销毁图，释放内存
    return 0;                             // 返回0，程序结束
}
