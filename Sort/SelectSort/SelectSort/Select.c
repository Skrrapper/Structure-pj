#define CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>



//ѡ������
void SelectSort1(int* a, int n);
void SelectSort2(int* a, int n);

//ֻ������Сֵ�������ֵ�Ľ���
void SelectSort1(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int min = left;//ָ��Ŀǰ��СֵΪ��һ��Ԫ��
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[min])//����б�Ŀǰ��Сֵ��С��Ԫ�أ��͸�����Сֵ�����н���
			{
				min = i;
			}
		}
		if (min != left)//�����Сֵ���ǵ�һ��Ԫ�أ��ͽ���Swap����
		{
			int temp = a[min];
			a[min] = a[left];
			a[left] = temp;
		}
		left++;//ÿ���һ�ν�������ָ�������ƶ�һλ��������һ�ν���
	}
}


//��Сֵ�����ֵͬʱ���н������ŵ��Ǽ����˽�����������һ���̶��������Ч��
void SelectSort2(int* a, int n)//ѡ������
{
	int left; int right = n - 1;//����ָ��
	while (left < right)
	{
		int min = left, max = right;//��Сֵ�����ֵ���±�
		for(int i=left+1;i<=right;i++)
		{
			if (a[i] < a[min])//����Сֵ
				min = i;
			if (a[i] > a[max])//�����ֵ
				max = i;
		}
		if (min != left)
		{
			//����һ��Swap����
			int temp = a[min];
			a[min] = a[left];
			a[left] = temp;
		}
		//������ֵ����Сֵ��ȣ�˵�����ֵ����Сֵ��ͬһ��Ԫ�أ�ֻ��Ҫ����һ�ν���
		//�����������max���ͻὫ��Сֵ������ĩβλ�á�
		if (left = right)
		{
			right = min;
		}
		left++;
		right--;

}