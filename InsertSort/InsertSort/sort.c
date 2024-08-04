#define CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

//升序情况
void InsertSort(int* arr, int n)
{
	int end = n - 1;//从最后一个数据开始进行比较
	int tmp = arr[end];//保存最后一个数据
	while (end >= 0)
	{
		if (tmp <= arr[end])//当tmp小于等于arr[end]时，说明tmp还没有找到合适的位置
		{
			arr[end + 1] = arr[end];//那么就将arr[end]向后移动
			end--;//继续向前比较
		}
		else//当tmp大于arr[end]时，说明tmp已经找到了合适的位置
		{
			break;//那么就直接退出循环
		}
	}
	arr[end + 1] = tmp;
}
