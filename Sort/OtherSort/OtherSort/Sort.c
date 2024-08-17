#define CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountSort(int* a, int n);

//空间复杂度：O(n)
//时间复杂度：O(N+range)
void CountSort(int* a, int n)
{
	int max = a[0],min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i]<max)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int)*range);
	if (count == NULL)
	{
		perror("malloc failed\n");
		return;
	}
	memset(count, 0, sizeof(int)*range);
	for(int i = 0; i < n; i++)//统计次数
	{
		count[a[i] - min]++;//a[i] - min是为了减少count数组的大小
	}
	//排序		
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)//排序的原理：将count数组中的元素依次放入a数组中
		{
			a[index++] = i + min;//i + min是为了将count数组的下标转换为a数组的元素
		}
	}

	free(count);
}