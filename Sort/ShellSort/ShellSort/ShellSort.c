#define CRT_SECURE_NO_WARNINGS 1
void ShellSort1(int arr[], int n);
void ShellSort2(int arr[], int n);
//������������ƣ�ֻ�ǲ�������ļ����1����ϣ������ļ����gap

//����һ���������һ��
void ShellSort1(int arr[], int n)
{
	int gap = 3;//����һ����Ҫ�ļ��
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

//��֮ͬ�������鲢��
void ShellSort2(int arr[], int n)
{
	int gap = 3;//����һ����Ҫ�ļ��
	
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

//gapԽ������Խ�죬��һ��������������
//gapԽС������Խ������һ��������������