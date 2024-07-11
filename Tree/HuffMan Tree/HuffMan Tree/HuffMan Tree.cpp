#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;
typedef struct
{
    int weight;
    int parent, lchild, rchild;
}HTNode, * HuffmanTree;
typedef char** HuffmanCode;

void Select(HuffmanTree HT, int len, int& s1, int& s2)
{
    int i, min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f;
    for (i = 1; i < len; i++) {
        if (HT[i].weight < min1 && HT[i].parent == 0) {
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    int temp = HT[s1].weight;
    HT[s1].weight = 0x3f3f3f3f;
    for (i = 1; i <= len; i++) {
        if (HT[i].weight < min2 && HT[i].parent == 0) {
            min2 = HT[i].weight;
            s2 = i;
        }
    }
    HT[s1].weight = temp;
}

//用算法5.10构造赫夫曼树
void CreatHuffmanTree(HuffmanTree& HT, int n)
{
    //构造赫夫曼树HT
    int m, s1, s2, i;
    if (n <= 1)return;
    m = 2 * n - 1;
    HT = new HTNode[m + 1];        //0号单元未用，所以需要动态分配m+1个单元，HT[m]表示根结点
    for (i = 1; i <= m; ++i)           //将1~m号单元中的双亲、左孩子，右孩子的下标都初始化为0
    {
        HT[i].parent = 0;  HT[i].lchild = 0;  HT[i].rchild = 0;
    }
    //cout<<"请输入叶子结点的权值：\n";
    for (i = 1; i <= n; ++i)           //输入前n个单元中叶子结点的权值
        cin >> HT[i].weight;
    /*――――――――――初始化工作结束，下面开始创建赫夫曼树――――――――――*/
    for (i = n + 1; i <= m; ++i)
    {  //通过n-1次的选择、删除、合并来创建赫夫曼树
        Select(HT, i - 1, s1, s2);
        //在HT[k](1≤k≤i-1)中选择两个其双亲域为0且权值最小的结点,
        // 并返回它们在HT中的序号s1和s2
        HT[s1].parent = i;
        HT[s2].parent = i;
        //得到新结点i，从森林中删除s1，s2，将s1和s2的双亲域由0改为i
        HT[i].lchild = s1;
        HT[i].rchild = s2;                          //s1,s2分别作为i的左右孩子
        HT[i].weight = HT[s1].weight + HT[s2].weight;  //i 的权值为左右孩子权值之和
    }                                              //for
}                                                 // CreatHuffmanTree


int countWPL(HuffmanTree HT, int n)  //计算树的带树路径长度
{
    int cnt, WPL = 0;
    for (int i = 1; i <= n; i++)
    {
        int father = HT[i].parent;    //当前节点的父节点
        cnt = 0;
        while (father != 0)
        {
            cnt++;
            father = HT[father].parent;
        }
        WPL += cnt * HT[i].weight;
    }
    return WPL;

}
int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int n;
    cin >> n;                                          //输入赫夫曼树的叶子结点个数
    CreatHuffmanTree(HT, n);
    cout << countWPL(HT, n);
    return 0;
}
