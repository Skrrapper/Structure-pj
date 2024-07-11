#define _CRT_SECURE_NO_WARNINGS 1
//��������ǰ�����򡢺�������Ķ��壺
//ǰ�����������һ�������ȷ��ʸ���Ȼ�������������������������������
//�������������һ�������ȱ�������������Ȼ����ʸ�������������������
//�������������һ�������ȱ�������������Ȼ��������������������ʸ���
//����һ�ö�������ǰ������������������������������ʾ������ǰ���������������ܹ�Ψһȷ�������������
//

//����ǰ��������������������������
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

typedef char TElemType;
//�������Ķ�������洢��ʾ
typedef struct BiTNode {
    TElemType data;                      //���������
    struct BiTNode* lchild, * rchild; //���Һ���ָ��
} BiTNode, * BiTree;

//������������pre[pre_low..pre_low+len-1]����������in[in_low..in_low+len-1]����t
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

// ��������ĵݹ��㷨
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