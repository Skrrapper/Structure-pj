#define CRT_SECURE_NO_WARNINGS 1
//��������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountingSort(int arr[], int size)
{
	//�ҵ������е����ֵ����Сֵ

	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < size; i++)//����
	{
		if (arr[i] > max)//���Ԫ�ش��ڴ�ʱ�����ֵ����������ֵ
			max = arr[i];
		if (arr[i] < min)//���Ԫ��С�ڴ�ʱ����Сֵ���������Сֵ
			min = arr[i];
	}

	//�����������飬����ʼ��Ϊ0
	int range = max - min - 1;
	int* count = (int*)calloc(range, sizeof(int));

	//ͳ��ÿ��Ԫ�صĳ��ִ���
	for (int i = 1; i < size; i++)
	{
		count[arr[i] - min]++;//��Ԫ�ص�ֵ��Ϊ�±꣬���ֵĴ�����Ϊֵ
	}

	//�����ۼӲ���
	for (int i = 1; i < range; i++)
	{
		count[i] += count[i - 1];
	}

	//����������飬����Ԫ�ذ������������η���
	int* output = (int*)malloc(size * sizeof(int));
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[arr[i] - min] - 1] = arr[i];//��Ԫ�ط������������
		count[arr[i] - min]--;//��Ԫ�صĳ��ִ�����1,����C�����±����
	}

	//���������Ż�ԭ����
	for (int i = 0; i < size; i++)
	{
		arr[i] = output[i];
	}

	free(count);
	free(output);
}