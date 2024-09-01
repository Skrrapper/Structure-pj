#define CRT_SECURE_NO_WARNINGS 1
//��������
#include <stdio.h>
#include <stdlib.h>
#include "StackB.c"


void QuickSort1(int* a, int left, int right);
//��������
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//���ŷ�Ϊ����
//��һ���ǻ�������

//����ȡ�У�ȡ�������м������Ϊ��׼ֵ�����������ĸ���
int GetMid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])//��ߺ��м�Ƚ�
	{
		if(a[mid]<a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else//��ߺ��м�Ƚ�
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

	//���ѡ��׼ֵ���Ӷ�������Ч��С�����ĸ��� 
	int randindex = rand() % (right - left + 1) + left;
	Swap(&a[randindex], &a[left]);

	int key = left;//ѡ�������Ϊ��׼ֵ
	while (left < right)
	{
		//�ұ���С��
		while (a[right] >= a[key])
			right--;
		//����Ҵ��
		while (a[left] <= a[key])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	//�������ĵݹ鷽ʽ
	QuickSort1(a, key, left - 1);//�ݹ����
	QuickSort1(a, left + 1, right);//�ݹ��ұ�

}

//���ŵ���
int PartSort1(int* a, int left, int right)
{
	if (left >= right)
		return;

	//���ѡ��׼ֵ���Ӷ�������Ч��С�����ĸ��� 
	int randindex = rand() % (right - left + 1) + left;
	Swap(&a[randindex], &a[left]);

	int key = left;//ѡ�������Ϊ��׼ֵ
	while (left < right)
	{
		//�ұ���С��
		while (a[right] >= a[key])
			right--;
		//����Ҵ��
		while (a[left] <= a[key])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	return left;

}



//�ڶ������ڿӷ�
//�ڿӷ���ʵ�ʾ��ǲ��ϱ��׼ֵ��λ�ã�ֱ���ҵ���׼ֵ��λ��
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;

	//����ȡ��
	int mid = GetMid(a, left, right);
	if (left != mid)
		Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;//�ڿ�λ��

	while (left < right)
	{
		//�ұ���С��
		while (a[right] >= a[key])
			right--;
		a[hole] = a[right];//���
		hole = right;

		//����Ҵ��
		while (a[left] <= a[key])
			left++;
		a[hole] = a[left];//���
		hole = left;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	//�������ĵݹ鷽ʽ
	QuickSort1(a, key, left - 1);//�ݹ����
	QuickSort1(a, left + 1, right);//�ݹ��ұ�
}

//�ڿӵ���
void PartSort2(int* a, int left, int right)
{
	
	//����ȡ��
	int mid = GetMid(a, left, right);
	if (left != mid)
		Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;//�ڿ�λ��

	while (left < right)
	{
		//�ұ���С��
		while (a[right] >= a[key])
			right--;
		a[hole] = a[right];//���
		hole = right;

		//����Ҵ��
		while (a[left] <= a[key])
			left++;
		a[hole] = a[left];//���
		hole = left;
		
	}
	a[hole] = key;
	return hole;
}


//��������ǰ��ָ�뷨
//ǰ��ָ�뷨��ʵ����ͨ���ȽϺ�ָ��ͻ�׼ֵ�Ĵ�С��
//Ȼ�������С����ʱ����ǰ��ָ�뽻��
//������ԭ����ǰ�С�ķ���ǰ�ߣ���ķ��ں��
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

//ǰ��ָ�뵥��
int PartSort3(int* a, int left, int right)
{
	int mid = GetMid(a, left, right);
	if (mid != left)
		Swap(&a[left], &a[mid]);
	int key = left;

	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;

	}
	Swap(&a[prev], &a[key]);
	key = prev;

	return key;

}

//����
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 1; i < n; i++)
	{
		int key = a[i];
		int end = i - 1;
		while (end >= 0 && a[end] > key)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = key;
	}
}

//С�����Ż�
void QuickSort4(int* a, int left, int right)
{
	if (left >= right)
		return;

	//С����ֱ��ʹ�ò�������
	if ((right - left + 1) > 10)
	{
		int key = PartSort3(a, left, right);
		QuickSort3(a, left, key - 1);
		QuickSort3(a, key + 1, right);
	}
	else
	{
		//����ʹ�ò�������
		InsertSort(a + left, right - left + 1);
	}
}

//�ǵݹ�ʵ�ֿ���
void QuickSortNoR(int* a, int left, int right)
{
	ST s;
	STInit(&s);
	STPush(&s, left);//�Ƚ����ұ߽���ջ
	STPush(&s, right);

	while (STEmpty(&s))
	{
		//ȡ�����ұ߽�
		int begin = STTop(&s);
		STPop(&s);
		int end = STTop(&s);
		STPop(&s);
		//ʹ��һ�ε��˵Ŀ��ŵõ���һ�εĻ�׼ֵ
		int key = PartSort3(a, begin, end);
		//����׼ֵ�����ұ߽���ջ
		if (key + 1 < end)
		{
			STPush(&s, end);
			STPush(&s, key + 1);
		}
		if (begin < key-1)
		{
			STPush(&s, key-1);
			STPush(&s, begin);
		}
	}

	STDestroy(&s);
}