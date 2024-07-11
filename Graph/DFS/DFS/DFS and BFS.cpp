//输入一个图，用邻接矩阵存储（实际上也可以选择邻接表），并实现DFSTraverse操作。
//拷贝前面已经实现的代码，主函数必须如下，完成剩下的部分。



#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
 
#define MVNum 100     //最大顶点数
typedef string VerTexType; //假设顶点的数据类型为字符串
typedef int ArcType;             //假设边的权值类型为整型
 
bool visited[MVNum];//访问标志数组
//Status (* VisitFunc)(int v);//函数变量
 
//------------图的邻接矩阵------------------
typedef struct {
   VerTexType vexs[MVNum];            //顶点表
   ArcType arcs[MVNum][MVNum];      //邻接矩阵
   int vexnum, arcnum;                //图的当前vexnum点数和arcnum边数
} Graph;
 
//得到顶点i的数据
VerTexType Vertexdata(const Graph &g, int i)
{
   return g.vexs[i];
}
 
int LocateVex(const Graph &g, VerTexType v) //返回定点所示的下标
{
   //确定点v在G中的位置
   for(int i = 0; i < g.vexnum; ++i)
      if(g.vexs[i] == v)
         return i;
   return -1;
}//LocateVex
 
int FirstAdjVex(const Graph &g, int v)
{
   //返回v的第一个邻接点编号，没有返回-1
   /****在此下面完成代码***************/
   int i,j;
   for(i=v;i<g.vexnum;i++)
   {
   		for(j=0;j<g.vexnum;j++)
		{
   			if(g.arcs[i] [j]== 1)
   				return j;
   		}
   }
	return -1;
 
   /***********************************/
}//FirstAdjVex
 
int NextAdjVex(const Graph &g, int v, int w)
{
   //返回v相对于w的下一个邻接点，没有返回-1
   /****在此下面完成代码***************/
	int i,j;
  	for(i=w+1;i<g.vexnum;i++){
   		if(g.arcs[v][i] == 1)
   			return i;
    }
	return -1;
 
   /***********************************/
}//NextAdjVex
 
 
void CreateUDG(Graph &g)
{
   //采用邻接矩阵表示法，创建无向图G
   /****在此下面完成代码***************/
	int i,j,k;
	string v1,v2;
	cin >> g.vexnum >>g.arcnum;//是图的总顶点数n和总边数e
	//第二行是n个空格分开的字符串，是顶点的名字，依次对应编号0~n-1。
	for(i=0;i<g.vexnum;i++)	//输入点的信息
	{
		cin >> g.vexs[i];
	}
	//每行两个空格分开的顶点名字，表示一条边的两个顶点
	//构造邻接矩阵
        for(k=0;k<g.arcnum;k++)
		{
			cin >> v1 >> v2 ;
			if(LocateVex(g,v1)||LocateVex(g,v2))
			{
				i=LocateVex(g,v1);
				j=LocateVex(g,v2);
				 g.arcs[i][j]=1;
				 g.arcs[j][i]=g.arcs[i][j];
			}
			else
			{
				g.arcs[i][j]=0; //二维数组其他元素置零  各点之间没有连接
				g.arcs[j][i]=g.arcs[i][j];
			}
		}
 
   /***********************************/
}//CreateUDN
 
 
void DFS(Graph g, int v)  //从第v个顶点出发，深度优先遍历g
{
    int w;
    cout << g.vexs[v] << " ";
    visited[v]=true;  // 访问第v个顶点，并置访问标志数组相应分量值为true
    //VisitFunc(v);
    //依次检查v的所有邻接点w，FirstAdjVex(g,v)表示v的第一个邻接点
    //NextAdjVex(g,v,w)表示v的下一个邻接点   w>=0;表示存在邻接点
    for(w=FirstAdjVex(g,v); w>=0; w=NextAdjVex(g,v,w))
    {
        if(!visited[w]) DFS(g,w);
        //对v尚未访问的邻接顶点w递归调用DFS
    }
 
}
 
void DFSTraverse(Graph g)
{
    int v;
    //VisitFunc = Visit;
    for ( v=0; v<g.vexnum; v++ )   visited[v]=false;
    for ( v=0; v<g.vexnum; v++ )
    if(!visited[v])  DFS(g,v);
}
 
 
 
void DestroyUDG(Graph &g)
{
   //you should do this
   g.arcnum=g.vexnum=0;//点和边都设置为0，则此矩阵为零
 
}
 
 
int main()
{
   Graph g;
   CreateUDG(g);
 
   DFSTraverse(g);
    cout << endl;
   DestroyUDG(g);
   return 0;
}//main
 