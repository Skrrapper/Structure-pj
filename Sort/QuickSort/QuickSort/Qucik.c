#define CRT_SECURE_NO_WARNINGS 1
//快速排序
#include <stdio.h>
#include <stdlib.h>
void QuickSort1(int* a, int left, int right);
//交换函数
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//快排分为两种
//第一种是霍尔快排

//三数取中，取三个数中间的数作为基准值，减少最坏情况的概率
int GetMid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])//左边和中间比较
	{
		if(a[mid]<a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else//左边和中间比较
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;

	}
}

void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
		return;

	//随机选基准值，从而可以有效减小最坏情况的概率 
	int randindex = rand() % (right - left + 1) + left;
	Swap(&a[randindex], &a[left]);

	int key = left;//选择最左边为基准值
	while (left < right)
	{
		//右边找小的
		while (a[right] >= a[key])
			right--;
		//左边找大的
		while (a[left] <= a[key])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	//二叉树的递归方式
	QuickSort1(a, key, left - 1);//递归左边
	QuickSort1(a, left + 1, right);//递归右边

}

//快排单趟
void PartSort1(int* a, int left, int right)
{
	if (left >= right)
		return;

	//随机选基准值，从而可以有效减小最坏情况的概率 
	int randindex = rand() % (right - left + 1) + left;
	Swap(&a[randindex], &a[left]);

	int key = left;//选择最左边为基准值
	while (left < right)
	{
		//右边找小的
		while (a[right] >= a[key])
			right--;
		//左边找大的
		while (a[left] <= a[key])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	return left;

}



//第二种是挖坑法
//挖坑法的实质就是不断变基准值的位置，直到找到基准值的位置
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;

	//三数取中
	int mid = GetMid(a, left, right);
	if (left != mid)
		Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;//挖坑位置

	while (left < right)
	{
		//右边找小的
		while (a[right] >= a[key])
			right--;
		a[hole] = a[right];//填坑
		hole = right;

		//左边找大的
		while (a[left] <= a[key])
			left++;
		a[hole] = a[left];//填坑
		hole = left;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	//二叉树的递归方式
	QuickSort1(a, key, left - 1);//递归左边
	QuickSort1(a, left + 1, right);//递归右边
}

//挖坑单趟
void PartSort2(int* a, int left, int right)
{
	
	//三数取中
	int mid = GetMid(a, left, right);
	if (left != mid)
		Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;//挖坑位置

	while (left < right)
	{
		//右边找小的
		while (a[right] >= a[key])
			right--;
		a[hole] = a[right];//填坑
		hole = right;

		//左边找大的
		while (a[left] <= a[key])
			left++;
		a[hole] = a[left];//填坑
		hole = left;
		
	}
	a[hole] = key;
	return hole;
}


//第三种是前后指针法
//前后指针法的实质是通过比较后指针和基准值的大小，
//然后满足大小条件时进行前后指针交换
//交换的原则就是把小的放在前边，大的放在后边
void QuickSort3(int* a, int left, int right)
{
	int mid = GetMid(a, left, right);
	if (mid != left)
		Swap(&a[left], &a[mid]);
	int key = left;
	
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] <a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
		
	}
	Swap(&a[prev], &a[key]);
	key = prev;

	return key;
    
}