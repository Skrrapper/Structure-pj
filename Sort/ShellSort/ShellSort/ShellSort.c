#define CRT_SECURE_NO_WARNINGS 1
void ShellSort1(int arr[], int n);
void ShellSort2(int arr[], int n);
//与插入排序类似，只是插入排序的间隔是1，而希尔排序的间隔是gap

//排完一组后，再排下一组
void ShellSort1(int arr[], int n)
{
	int gap = 3;//任意一个想要的间隔
	for (int j; j < gap; j++)
	{
		for (int i = gap; i < n; i += gap)
		{

			int end = i - gap;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp >= arr[end])
				{
					arr[end + gap] = tmp;
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}


}

//不同之处：多组并排
void ShellSort2(int arr[], int n)
{
	int gap = 3;//任意一个想要的间隔
	
		for (int i = gap; i < n-gap; i ++)
		{

			int end = i;
			int tmp = arr[i + gap];
			while (end >= 0)
			{
				if (tmp >= arr[end])
				{
					arr[end + gap] = tmp;
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
}

//gap越大，跳得越快，但一次排下来最无序
//gap越小，跳得越慢，但一次排下来更有序