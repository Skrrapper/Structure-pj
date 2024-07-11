//����һ��ͼ�����ڽӾ���洢��ʵ����Ҳ����ѡ���ڽӱ�����ʵ��DFSTraverse������
//����ǰ���Ѿ�ʵ�ֵĴ��룬�������������£����ʣ�µĲ��֡�



#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
 
#define MVNum 100     //��󶥵���
typedef string VerTexType; //���趥�����������Ϊ�ַ���
typedef int ArcType;             //����ߵ�Ȩֵ����Ϊ����
 
bool visited[MVNum];//���ʱ�־����
//Status (* VisitFunc)(int v);//��������
 
//------------ͼ���ڽӾ���------------------
typedef struct {
   VerTexType vexs[MVNum];            //�����
   ArcType arcs[MVNum][MVNum];      //�ڽӾ���
   int vexnum, arcnum;                //ͼ�ĵ�ǰvexnum������arcnum����
} Graph;
 
//�õ�����i������
VerTexType Vertexdata(const Graph &g, int i)
{
   return g.vexs[i];
}
 
int LocateVex(const Graph &g, VerTexType v) //���ض�����ʾ���±�
{
   //ȷ����v��G�е�λ��
   for(int i = 0; i < g.vexnum; ++i)
      if(g.vexs[i] == v)
         return i;
   return -1;
}//LocateVex
 
int FirstAdjVex(const Graph &g, int v)
{
   //����v�ĵ�һ���ڽӵ��ţ�û�з���-1
   /****�ڴ�������ɴ���***************/
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
   //����v�����w����һ���ڽӵ㣬û�з���-1
   /****�ڴ�������ɴ���***************/
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
   //�����ڽӾ����ʾ������������ͼG
   /****�ڴ�������ɴ���***************/
	int i,j,k;
	string v1,v2;
	cin >> g.vexnum >>g.arcnum;//��ͼ���ܶ�����n���ܱ���e
	//�ڶ�����n���ո�ֿ����ַ������Ƕ�������֣����ζ�Ӧ���0~n-1��
	for(i=0;i<g.vexnum;i++)	//��������Ϣ
	{
		cin >> g.vexs[i];
	}
	//ÿ�������ո�ֿ��Ķ������֣���ʾһ���ߵ���������
	//�����ڽӾ���
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
				g.arcs[i][j]=0; //��ά��������Ԫ������  ����֮��û������
				g.arcs[j][i]=g.arcs[i][j];
			}
		}
 
   /***********************************/
}//CreateUDN
 
 
void DFS(Graph g, int v)  //�ӵ�v�����������������ȱ���g
{
    int w;
    cout << g.vexs[v] << " ";
    visited[v]=true;  // ���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue
    //VisitFunc(v);
    //���μ��v�������ڽӵ�w��FirstAdjVex(g,v)��ʾv�ĵ�һ���ڽӵ�
    //NextAdjVex(g,v,w)��ʾv����һ���ڽӵ�   w>=0;��ʾ�����ڽӵ�
    for(w=FirstAdjVex(g,v); w>=0; w=NextAdjVex(g,v,w))
    {
        if(!visited[w]) DFS(g,w);
        //��v��δ���ʵ��ڽӶ���w�ݹ����DFS
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
   g.arcnum=g.vexnum=0;//��ͱ߶�����Ϊ0����˾���Ϊ��
 
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
 