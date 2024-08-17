#define CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�鲢����
void MergeSort(int* a, int n);
void _MergeSort(int* a, int begin, int end, int* tmp);

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	int mid = (begin + end) / 2;//�м�ֵ
	//�����ʣ��������2�ı����᲻���д������ᣬ�鲢�����Ԫ�ظ����޹�,����"/"�����ԣ�
	if (begin >= end)
	{
		return;
	}
	_MergeSort(a, begin, mid, tmp);//�ȴ���߿�ʼ
	_MergeSort(a, mid + 1, end, tmp);//�ٴ��ұ߿�ʼ

	int begin1 = begin, end1 = end;//��ߵ���ʼλ�úͽ���λ��
	int begin2 = mid + 1, end2 = end;//�ұߵ���ʼλ�úͽ���λ��
	int i = begin;//���ﲻ�ܸ�0����Ϊ�ݹ�ʱ���ε���
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)//�����߻���ʣ��
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)//����ұ߻���ʣ��
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(tmp + begin, a + begin, sizeof(int) * (end - begin + 1));//���ź���Ŀ�����ȥ
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		return;
	}
	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

//�ǵݹ�鲢
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	//�鲢����Ϊʲô������ջ��������Ϊ�ݹ��ʱ����Ҫ�����ֳ���ջ������
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		return;
	}
	//���ڷǵݹ飬���ǿ���������������Ȼ�󿽱���ȥ�ٽ�����������ֱ��ȫ������
	int gap = 1;//ÿ������ݸ���
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;//��ߵ���ʼλ�úͽ���λ��
			int begin2 = i + gap, end2 = i + 2 * gap - 1;//�ұߵ���ʼλ�úͽ���λ��
			
			//����Խ�����
			//if (end1 >= n)
			//{
			//	end1 = n - 1;
			//	begin2 = n;//���ﲻ�ܸ�n-1����Ϊ�����++����Խ��
			//	end2 = n - 1;
			//}
			//else if (begin2 >= n)
			//{
			//	begin2 = n;
			//	end2 = n - 1;
			//}
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			int j = i;//���ﲻ�ܸ�0����Ϊ�ݹ�ʱ���ε���
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)//�����߻���ʣ��
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)//����ұ߻���ʣ��
			{
				tmp[j++] = a[begin2++];
			}
			//����
			memcpy(tmp + i, a + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
}

