#define CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>



//—°‘Ò≈≈–Ú
void SelectSort(int* a, int n);
void SelectSort(int* a, int n)//—°‘Ò≈≈–Ú
{
	int left; int right = n - 1;
	while (left < right)
	{
		int min = left, max = right;
		for(int i=left+1;i<=right;i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;
		}
		if (min != left)
		{
			int temp = a[min];
			a[min] = a[left];
			a[left] = temp;
		}
		if (left = right)
		{
			right = min;
		}
		left++;
		right--;

}