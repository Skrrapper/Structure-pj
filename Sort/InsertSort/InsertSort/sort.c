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
