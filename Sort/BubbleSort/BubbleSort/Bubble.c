#define CRT_SECURE_NO_WARNINGS 1
//ц╟ещеепР
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void BubbleSort(int* a, int n);

void BubbleSort(int* a, int n)
{
	bool exchange = false;
	for(int j=0;j<n;j++)
	{
		for (int i = 1; i < n-j; i++)
		{
			if (a[i - 1] > a[i])
			{
				int temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
			}
			if(exchange == false)
			{
				break;
			}
		}
	}

}