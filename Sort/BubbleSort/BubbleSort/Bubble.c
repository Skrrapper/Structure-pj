#define CRT_SECURE_NO_WARNINGS 1
//ð������
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void BubbleSort(int* a, int n);

void BubbleSort(int* a, int n)
{
	bool exchange = false;//����Ƿ�������
	for(int j=0;j<n;j++)
	{
		for (int i = 1; i < n-j; i++)
		{
			//���ǰһ��Ԫ�ش��ں�һ��Ԫ�أ�����
			if (a[i - 1] > a[i])
			{
				int temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
			}
			if(exchange == false)//���û�з���������˵����ʱ�Ѿ�������ô��ֱ������
			{
				break;
			}
		}
	}

}