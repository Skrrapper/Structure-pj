#include<iostream>
#include<stdlib.h>
using namespace std;
void Radixsort(int a[], int length)//��������
{
	int max = a[0], base = 1;//base��max�����жϽ��м�������
	for (int i = 1; i < length; i++)
	{
		if (max < a[i]) max = a[i];
	}
	int* t = (int*)malloc(sizeof(int) * length);//��t������ʱ����ÿһ���źõĽ��
	while (max / base > 0)//�����Ϊnλ���ͽ���n��
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < length; i++)//ͳ��ÿ��Ͱ�е���Ŀ
			bucket[a[i] / base % 10]++;
		for (int i = 1; i < length; i++)//������Ͱ�е���Ŀ���
			bucket[i] += bucket[i - 1];
		for (int i = length - 1; i >= 0; i--)//���������η���Ͱ��
		{
			t[bucket[a[i] / base % 10] - 1] = a[i];
			bucket[a[i] / base % 10]--;
		}
		for (int i = 0; i < length; i++)//���źõ����ݷŻ�a������
			a[i] = t[i];
		base = base * 10;
	}
}
