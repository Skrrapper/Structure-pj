#include<iostream>
#include<stdlib.h>
using namespace std;
void Radixsort(int a[], int length)//基数排序
{
	int max = a[0], base = 1;//base与max用来判断进行几趟排序
	for (int i = 1; i < length; i++)
	{
		if (max < a[i]) max = a[i];
	}
	int* t = (int*)malloc(sizeof(int) * length);//用t数组临时储存每一趟排好的结果
	while (max / base > 0)//最大数为n位数就进行n次
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < length; i++)//统计每个桶中的数目
			bucket[a[i] / base % 10]++;
		for (int i = 1; i < length; i++)//将各个桶中的数目相加
			bucket[i] += bucket[i - 1];
		for (int i = length - 1; i >= 0; i--)//将数据依次放入桶中
		{
			t[bucket[a[i] / base % 10] - 1] = a[i];
			bucket[a[i] / base % 10]--;
		}
		for (int i = 0; i < length; i++)//将排好的数据放回a数组中
			a[i] = t[i];
		base = base * 10;
	}
}
