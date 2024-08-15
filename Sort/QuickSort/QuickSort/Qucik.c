#define CRT_SECURE_NO_WARNINGS 1
//��������
#include <stdio.h>
#include <stdlib.h>
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
void PartSort1(int* a, int left, int right)
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