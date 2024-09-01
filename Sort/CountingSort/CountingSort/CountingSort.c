#define CRT_SECURE_NO_WARNINGS 1
//计数排序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountingSort(int arr[], int size)
{
	//找到数组中的最大值和最小值

	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < size; i++)//进行
	{
		if (arr[i] > max)//如果元素大于此时的最大值，则更新最大值
			max = arr[i];
		if (arr[i] < min)//如果元素小于此时的最小值，则更新最小值
			min = arr[i];
	}

	//创建计数数组，并初始化为0
	int range = max - min - 1;
	int* count = (int*)calloc(range, sizeof(int));

	//统计每个元素的出现次数
	for (int i = 1; i < size; i++)
	{
		count[arr[i] - min]++;//将元素的值作为下标，出现的次数作为值
	}

	//进行累加操作
	for (int i = 1; i < range; i++)
	{
		count[i] += count[i - 1];
	}

	//创建输出数组，并将元素按照排序结果依次放入
	int* output = (int*)malloc(size * sizeof(int));
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[arr[i] - min] - 1] = arr[i];//将元素放入输出数组中
		count[arr[i] - min]--;//将元素的出现次数减1,符合C语言下标规则
	}

	//将排序结果放回原数组
	for (int i = 0; i < size; i++)
	{
		arr[i] = output[i];
	}

	free(count);
	free(output);
}