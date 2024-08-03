#define CRT_SECURE_NO_WARNINGS 1
//二叉树
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

//计算结点个数
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

//计算树的深度
int TreeHeight1(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = TreeHeight(root->left);//左子树的高度
	int right = TreeSize(root->right);//右子树的高度
	return left > right ? left + 1 : right + 1;//当前树的高度=左右子树最大值+1
}



int TreeSize(BTNode* root)
{
	//使用递归思想
	return root == NULL ? 0 :
		1 + TreeSize(root->left)
		+ TreeSize(root->right)
		+ 1;//1是指根节点
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

//前序遍历
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

//中序遍历
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

//后序遍历
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

//求第k层节点个数=(左子树的k-1层节点个数)+(右子树的k-1层节点个数)
int TreeKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)//必须判断，否则k永远都是0（k最小都是1）
	{
		return 1;
	}
	return TreeKSize(root->left, k - 1) + TreeKSize(root->right, k - 1); 
}

//单值二叉树
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

//二叉树查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* left = BinaryTreeFind(root->left, x);//先判断左子树
	if (left != NULL)
		return left;

	BTNode* right = BinaryTreeFind(root->right, x);//再判断右子树
	if (right != NULL)
		return right;

	return NULL;//左右子树都没有找到
}

//层序遍历
//思路：首先建一个队列，根节点入队，然后出队，打印队首元素，左右子树入队，直到队列为空
void LevelOrder(BTNode* root)
{
	Queue q;//首先建一个队列
	QInit(&q);//初始化队列
	if (root == NULL)
	{
		return NULL;
	}
	if (root)
	{
		QPush(&q, root);//根节点入队
	}
	while (!QEmpty(&q))//队列不为空
	{
		BTNode* front = QFront(&q);//队首元素
		printf("%d ", front->data);//打印队首元素
		if (front->left) //左子树入队
		{
			QPush(&q, front->left);
		}
		if (front->right) //右子树入队
		{
			QPush(&q, front->right);
		}
	}
	QDestroy(&q);//销毁队列
}

//判断一棵树是否为完全二叉树
int IfCompleteTree(BTNode* root)
{//思路：因为对于完全二叉树来说，按层序走的话，非空结点一定是连续的
 //所以，当遇到空结点时，就停止遍历，看后面是否还有非空结点，如果有，就不是完全二叉树
	
	Queue q;
	QInit(&q);
	if (root)
	{
		QPush(&q, root);
	}
	while (!QEmpty(&q))
	{
		BTNode* front = QFront(&q);
		QPop(&q);//出队
		if (front == NULL)//遇到空结点
		{
			break;
		}
		//否则左右子树入队
		else
		{
			QPush(&q, front->left);
			QPush(&q, front->right);
		}
	}
	//判断
	while (!QEmpty(&q))
	{
		BTNode* front =QFront(&q);
		QPop(&q);
		//如果后面还有非空结点，则说明不是完全二叉树
		if (front != NULL)
		{
			QDestroy(&q);//防止内存泄漏
			return 0;
		}
	}
	QDestroy(&q);
	return 1;
}

//求二叉树的镜像
//原理：镜像的意思就是左右子相互对称，所以只需要将原树的左子树作为镜树的右子树，原树的右子树作为镜树的左子树
//也就是说交换左右子树即可
void Mirror(BTNode* root)
{
	if (root == NULL)
		return;
	BTNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	//递归
	Mirror(root->left);
	Mirror(root->right);
}

//销毁二叉树
void DestroyTree(BTNode* root)
{
	if (root == NULL)
		return;
	DestroyTree(root->left);
	DestroyTree(root->right);
	free(root);
}

//DFS算法
//深度优先遍历的思路：先序遍历
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


//BFS算法
//广度优先遍历的思路：层序遍历
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