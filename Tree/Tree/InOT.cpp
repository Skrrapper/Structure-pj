#define _CRT_SECURE_NO_WARNINGS 1
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
//例如如下的先序遍历字符串：
//ABC##DE#G##F###
//其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
//

//下面提供代码框架，请同学完成指定的部分。
//算法5.3 先序遍历的的顺序建立二叉链表
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef char TElemType;
//二叉树的二叉链表存储表示
typedef struct BiTNode {
    TElemType data;                      //结点数据域
    struct BiTNode* lchild, * rchild; //左右孩子指针
} BiTNode, * BiTree;

void CreateBiTree(BiTree& T)
{
    //按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
    TElemType ch;

    //此处和教材的不同是，要处理多组数据，输入ch如果遇到EOF，应该结束程序
    //所以main函数用while(1)
    if (!(cin >> ch)) exit(0);
    /****在此下面完成代码***************/
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    /***********************************/
}   //CreateBiTree

//用算法5.1 中序遍历的递归算法
void InOrderTraverse(BiTree T)
{
    //中序遍历二叉树T的递归算法
    /****在此下面完成代码***************/
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);       
    }
    /***********************************/
}

void DestroyBitree(BiTree& T)
{
    /****在此下面完成代码***************/
    if (T)
    {
        DestroyBitree(T->lchild);
        DestroyBitree(T->rchild);
        delete T;
        T = NULL;
    }
    /***********************************/
}

int main()
{
    BiTree tree;
    while (1) {
        CreateBiTree(tree);
        InOrderTraverse(tree);
        cout << endl;
        DestroyBitree(tree);
    }
}

