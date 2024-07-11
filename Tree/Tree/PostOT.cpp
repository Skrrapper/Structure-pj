#define _CRT_SECURE_NO_WARNINGS 1
//二叉树的前序、中序、后序遍历的定义：
//前序遍历：对任一子树，先访问跟，然后遍历其左子树，最后遍历其右子树；
//中序遍历：对任一子树，先遍历其左子树，然后访问根，最后遍历其右子树；
//后序遍历：对任一子树，先遍历其左子树，然后遍历其右子树，最后访问根。
//给定一棵二叉树的前序遍历和中序遍历，求其后序遍历（提示：给定前序遍历与中序遍历能够唯一确定后序遍历）。
//

//给定前序遍历和中序遍历，求其后序遍历
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

typedef char TElemType;
//二叉树的二叉链表存储表示
typedef struct BiTNode {
    TElemType data;                      //结点数据域
    struct BiTNode* lchild, * rchild; //左右孩子指针
} BiTNode, * BiTree;

//根据先序序列pre[pre_low..pre_low+len-1]和中序序列in[in_low..in_low+len-1]建树t
void BuildTree(BiTree& t, char pre[], int pre_low, char in[], int in_low, int len)
{
    if (len <= 0) {
        t = NULL;
        return;
    }

    t = (BiTree)malloc(sizeof(BiTNode));
    t->data = pre[pre_low];

    int i;
    for (i = in_low; i < in_low + len; i++) {
        if (in[i] == pre[pre_low]) {
            break;
        }
    }

    int left_len = i - in_low;
    int right_len = len - left_len - 1;

    BuildTree(t->lchild, pre, pre_low + 1, in, in_low, left_len);
    BuildTree(t->rchild, pre, pre_low + left_len + 1, in, i + 1, right_len);
}

// 后序遍历的递归算法
void PostOrderTraverse(BiTree t)
{
    if (t == NULL) {
        return;
    }

    PostOrderTraverse(t->lchild);
    PostOrderTraverse(t->rchild);
    cout << t->data;
}

void DestroyBitree(BiTree& t)
{
    if (t == NULL) {
        return;
    }

    DestroyBitree(t->lchild);
    DestroyBitree(t->rchild);
    free(t);
    t = NULL;
}

int main1()
{
    char pre[30], in[30];
    BiTree t = NULL;
    while (cin >> pre) {
        cin >> in;
        BuildTree(t, pre, 0, in, 0, strlen(in));
        PostOrderTraverse(t);
        DestroyBitree(t);
        cout << endl;
    }