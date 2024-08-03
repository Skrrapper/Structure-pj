#define CRT_SECURE_NO_WARNINGS 1
//������
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)  
	{
		perror("malloc fail");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//���������
//int size = 0;
//void TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	size++;
//	TreeSize(root->left);
//	TreeSize(root->right);
//}

//�����������
int TreeHeight1(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = TreeHeight(root->left);//�������ĸ߶�
	int right = TreeSize(root->right);//�������ĸ߶�
	return left > right ? left + 1 : right + 1;//��ǰ���ĸ߶�=�����������ֵ+1
}



int TreeSize(BTNode* root)
{
	//ʹ�õݹ�˼��
	return root == NULL ? 0 :
		1 + TreeSize(root->left)
		+ TreeSize(root->right)
		+ 1;//1��ָ���ڵ�
}


BTNode* CreateTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->right = node6;
	
	return node1;
}

//ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//�������
void MidOrder(BTNode* root)
{
	if (root == NULL) 
	{
		return;
	}
	MidOrder(root->left); 
	printf("%d ", root->data);
	MidOrder(root->right);  
}

//�������
void PostOrder(BTNode* root)
{
	if (root == NULL)  
	{
		return;
	}
	PostOrder(root->left);  
	PostOrder(root->right); 
	printf("%d ", root->data);
}

//���k��ڵ����=(��������k-1��ڵ����)+(��������k-1��ڵ����)
int TreeKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)//�����жϣ�����k��Զ����0��k��С����1��
	{
		return 1;
	}
	return TreeKSize(root->left, k - 1) + TreeKSize(root->right, k - 1); 
}

//��ֵ������
bool IsUnivalTree(BTNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->left != NULL && root->left->data != root->data)
	{
		return false;
	}
	if (root->right != NULL && root->right->data != root->data)
	{
		return false;
	} 
	return IsUnivalTree(root->left) && IsUnivalTree(root->right);
}

//����������ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* left = BinaryTreeFind(root->left, x);//���ж�������
	if (left != NULL)
		return left;

	BTNode* right = BinaryTreeFind(root->right, x);//���ж�������
	if (right != NULL)
		return right;

	return NULL;//����������û���ҵ�
}

//�������
//˼·�����Ƚ�һ�����У����ڵ���ӣ�Ȼ����ӣ���ӡ����Ԫ�أ�����������ӣ�ֱ������Ϊ��
void LevelOrder(BTNode* root)
{
	Queue q;//���Ƚ�һ������
	QInit(&q);//��ʼ������
	if (root == NULL)
	{
		return NULL;
	}
	if (root)
	{
		QPush(&q, root);//���ڵ����
	}
	while (!QEmpty(&q))//���в�Ϊ��
	{
		BTNode* front = QFront(&q);//����Ԫ��
		printf("%d ", front->data);//��ӡ����Ԫ��
		if (front->left) //���������
		{
			QPush(&q, front->left);
		}
		if (front->right) //���������
		{
			QPush(&q, front->right);
		}
	}
	QDestroy(&q);//���ٶ���
}

//�ж�һ�����Ƿ�Ϊ��ȫ������
int IfCompleteTree(BTNode* root)
{//˼·����Ϊ������ȫ��������˵���������ߵĻ����ǿս��һ����������
 //���ԣ��������ս��ʱ����ֹͣ�������������Ƿ��зǿս�㣬����У��Ͳ�����ȫ������
	
	Queue q;
	QInit(&q);
	if (root)
	{
		QPush(&q, root);
	}
	while (!QEmpty(&q))
	{
		BTNode* front = QFront(&q);
		QPop(&q);//����
		if (front == NULL)//�����ս��
		{
			break;
		}
		//���������������
		else
		{
			QPush(&q, front->left);
			QPush(&q, front->right);
		}
	}
	//�ж�
	while (!QEmpty(&q))
	{
		BTNode* front =QFront(&q);
		QPop(&q);
		//������滹�зǿս�㣬��˵��������ȫ������
		if (front != NULL)
		{
			QDestroy(&q);//��ֹ�ڴ�й©
			return 0;
		}
	}
	QDestroy(&q);
	return 1;
}

//��������ľ���
//ԭ���������˼�����������໥�Գƣ�����ֻ��Ҫ��ԭ������������Ϊ��������������ԭ������������Ϊ������������
//Ҳ����˵����������������
void Mirror(BTNode* root)
{
	if (root == NULL)
		return;
	BTNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	//�ݹ�
	Mirror(root->left);
	Mirror(root->right);
}

//���ٶ�����
void DestroyTree(BTNode* root)
{
	if (root == NULL)
		return;
	DestroyTree(root->left);
	DestroyTree(root->right);
	free(root);
}

//DFS�㷨
//������ȱ�����˼·���������
void DFS(BTNode* root)
{
		if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	DFS(root->left);
	DFS(root->right);
}


//BFS�㷨
//������ȱ�����˼·���������
void BFS(BTNode* root)
{
    Queue q;
	QInit(&q);
	if (root)
	{
		QPush(&q, root);
	}
	while (!QEmpty(&q))
	{
		BTNode* front = QFront(&q);
		QPop(&q);
		printf("%d ", front->data);
		if (front->left)
		{
			QPush(&q, front->left);
		}
		if (front->right)
		{
			QPush(&q, front->right);
		}
	}
	QDestroy(&q);
}

int main()
{
	/*BTNode* root = CreateTree();
	PreOrder(root);	*/
	printf("hello\n");
	return 0;
}