#define _CRT_SECURE_NO_WARNINGS 1
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢����
//�������µ���������ַ�����
//ABC##DE#G##F###
//���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������
//

//�����ṩ�����ܣ���ͬѧ���ָ���Ĳ��֡�
//�㷨5.3 ��������ĵ�˳������������
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef char TElemType;
//�������Ķ�������洢��ʾ
typedef struct BiTNode {
    TElemType data;                      //���������
    struct BiTNode* lchild, * rchild; //���Һ���ָ��
} BiTNode, * BiTree;

void CreateBiTree(BiTree& T)
{
    //�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
    TElemType ch;

    //�˴��ͽ̲ĵĲ�ͬ�ǣ�Ҫ����������ݣ�����ch�������EOF��Ӧ�ý�������
    //����main������while(1)
    if (!(cin >> ch)) exit(0);
    /****�ڴ�������ɴ���***************/
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    /***********************************/
}   //CreateBiTree

//���㷨5.1 ��������ĵݹ��㷨
void InOrderTraverse(BiTree T)
{
    //�������������T�ĵݹ��㷨
    /****�ڴ�������ɴ���***************/
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
    /****�ڴ�������ɴ���***************/
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

