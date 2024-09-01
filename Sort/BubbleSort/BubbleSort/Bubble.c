#define CRT_SECURE_NO_WARNINGS 1
//冒泡排序
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void BubbleSort(int* a, int n);

void BubbleSort(int* a, int n)
{
	bool exchange = false;//标记是否发生交换
	for(int j=0;j<n;j++)
	{
		for (int i = 1; i < n-j; i++)
		{
			//如果前一个元素大于后一个元素，交换
			if (a[i - 1] > a[i])
			{
				int temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
			}
			if(exchange == false)//如果没有发生交换，说明此时已经有序，那么就直接跳出
			{
				break;
			}
		}
	}

}