#define CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountSort(int* a, int n);

//�ռ临�Ӷȣ�O(n)
//ʱ�临�Ӷȣ�O(N+range)
void CountSort(int* a, int n)
{
	int max = a[0],min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i]<max)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int)*range);
	if (count == NULL)
	{
		perror("malloc failed\n");
		return;
	}
	memset(count, 0, sizeof(int)*range);
	for(int i = 0; i < n; i++)//ͳ�ƴ���
	{
		count[a[i] - min]++;//a[i] - min��Ϊ�˼���count����Ĵ�С
	}
	//����		
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)//�����ԭ����count�����е�Ԫ�����η���a������
		{
			a[index++] = i + min;//i + min��Ϊ�˽�count������±�ת��Ϊa�����Ԫ��
		}
	}

	free(count);
}