#define CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

//�������
void InsertSort(int* arr, int n)
{
	int end = n - 1;//�����һ�����ݿ�ʼ���бȽ�
	int tmp = arr[end];//�������һ������
	while (end >= 0)
	{
		if (tmp <= arr[end])//��tmpС�ڵ���arr[end]ʱ��˵��tmp��û���ҵ����ʵ�λ��
		{
			arr[end + 1] = arr[end];//��ô�ͽ�arr[end]����ƶ�
			end--;//������ǰ�Ƚ�
		}
		else//��tmp����arr[end]ʱ��˵��tmp�Ѿ��ҵ��˺��ʵ�λ��
		{
			break;//��ô��ֱ���˳�ѭ��
		}
	}
	arr[end + 1] = tmp;
}

//�������
void InsertSort2(int* arr, int n)
{
	int begin = 0;//�ӵ�һ�����ݿ�ʼ���бȽ�
	int tmp = arr[begin];//�����һ������
	while (begin <= n - 1)
	{
		if(tmp>=arr[begin])//��tmp���ڵ���arr[begin]ʱ��˵��tmp��û���ҵ����ʵ�λ��
		{
			arr[begin - 1] = arr[begin];//��ô�ͽ�arr[begin]����ƶ�
			begin++;//�������Ƚ�
		}
		else//��tmpС��arr[begin]ʱ��˵��tmp�Ѿ��ҵ��˺��ʵ�λ��
		{
			break;//��ô��ֱ���˳�ѭ��
		}
		arr[begin + 1] = tmp;
}