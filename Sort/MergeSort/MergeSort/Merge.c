#define CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//归并排序
void MergeSort(int* a, int n);
void _MergeSort(int* a, int begin, int end, int* tmp);

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	int mid = (begin + end) / 2;//中间值
	//（提问：如果不是2的倍数会不会有错——不会，归并本身和元素个数无关,基于"/"的特性）
	if (begin >= end)
	{
		return;
	}
	_MergeSort(a, begin, mid, tmp);//先从左边开始
	_MergeSort(a, mid + 1, end, tmp);//再从右边开始

	int begin1 = begin, end1 = end;//左边的起始位置和结束位置
	int begin2 = mid + 1, end2 = end;//右边的起始位置和结束位置
	int i = begin;//这里不能给0，因为递归时会多次调用
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
	while (begin1 <= end1)//如果左边还有剩余
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)//如果右边还有剩余
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(tmp + begin, a + begin, sizeof(int) * (end - begin + 1));//将排好序的拷贝回去
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

//非递归归并
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	//归并排序为什么不能用栈？——因为递归的时候需要保存现场，栈不方便
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		return;
	}
	//对于非递归，我们可以两两进行排序，然后拷贝回去再进行四四排序，直到全部排序
	int gap = 1;//每组的数据个数
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;//左边的起始位置和结束位置
			int begin2 = i + gap, end2 = i + 2 * gap - 1;//右边的起始位置和结束位置
			
			//考虑越界情况
			//if (end1 >= n)
			//{
			//	end1 = n - 1;
			//	begin2 = n;//这里不能给n-1，因为下面会++，会越界
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

			int j = i;//这里不能给0，因为递归时会多次调用
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
			while (begin1 <= end1)//如果左边还有剩余
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)//如果右边还有剩余
			{
				tmp[j++] = a[begin2++];
			}
			//拷贝
			memcpy(tmp + i, a + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
}

