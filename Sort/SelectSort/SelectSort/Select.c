#define CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>



//选择排序
void SelectSort1(int* a, int n);
void SelectSort2(int* a, int n);

//只进行最小值或者最大值的交换
void SelectSort1(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int min = left;//指定目前最小值为第一个元素
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[min])//如果有比目前最小值更小的元素，就更新最小值，进行交换
			{
				min = i;
			}
		}
		if (min != left)//如果最小值不是第一个元素，就进行Swap交换
		{
			int temp = a[min];
			a[min] = a[left];
			a[left] = temp;
		}
		left++;//每完成一次交换，左指针向右移动一位，进行下一次交换
	}
}


//最小值和最大值同时进行交换，优点是减少了交换次数，在一定程度上提高了效率
void SelectSort2(int* a, int n)//选择排序
{
	int left; int right = n - 1;//左右指针
	while (left < right)
	{
		int min = left, max = right;//最小值和最大值的下标
		for(int i=left+1;i<=right;i++)
		{
			if (a[i] < a[min])//找最小值
				min = i;
			if (a[i] > a[max])//找最大值
				max = i;
		}
		if (min != left)
		{
			//进行一次Swap交换
			int temp = a[min];
			a[min] = a[left];
			a[left] = temp;
		}
		//如果最大值和最小值相等，说明最大值和最小值是同一个元素，只需要进行一次交换
		//如果继续交换max，就会将最小值交换到末尾位置。
		if (left = right)
		{
			right = min;
		}
		left++;
		right--;

}