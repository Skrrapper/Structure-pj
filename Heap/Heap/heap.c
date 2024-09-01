#define CRT_SECURE_NO_WARNINGS 1
#include "heap.h"
void HeapInit(HP* php)
{
    assert(php);
    php->a = (HPDataType*)malloc(sizeof(HPDataType) * 4);
        if (php->a == NULL)
        {
            perror("malloc fail");
            return;
        }
        php->size = 0;
        php->capacity = 4;
}

void HeapPush(HP* php, HPDataType x)
{
    assert(php);

    if (php->size == php->capacity)
    {
       HPDataType* tmp = (HPDataType*)realloc(php->a,sizeof(HPDataType) * php->capacity*2);
        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        php->a = tmp;
        php->capacity *= 2;
    }
    php->a[php->size] = x;
    php->size++;

    AdjustUp(php->a, php->size - 1);
}

void Swap(HPDataType* p1, HPDataType* p2)
{
    HPDataType x = *p1;
    *p1 = *p2;
    *p2 = x;
}

//除了child这个位置，前面的数据都要构成堆
void AdjustUp(HPDataType* a, int child)
{
    int parent = (child - 1) / 2;
    while (child>0)
    {
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
        
    }
}

//左右子树都是堆
void AdjustDown(HPDataType* a, int n,int parent)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        //选择左右孩子中大的那一个
        if (child+1 < n && a[child+1] > a[child])//如果右孩子存在并且右孩子大于左孩子
        {
            ++child;
        }
        if (a[child] > a[parent])//如果孩子大于父亲
        {
            Swap(&a[child] , &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else//如果孩子小于父亲
        {
            break;
        }

    }
}

void HeapPop(HP* php)
{
    assert(php);
    assert(!HeapEmpty(php));
    
    //删除数据
    Swap(&php->a[0], &php->size - 1);
    php->size--;
}

////冒泡排序
//    void HeapPop(HP* php)
//{
//	assert(php);
//	assert(!HeapEmpty(php));
//
//	//删除数据
//	Swap(&php->a[0], &php->size - 1);
//	php->size--;
//
//	//向下调整
//	AdjustDown(php->a, php->size, 0);
//}

HPDataType HeapTop(HP* php)
{
    assert(php);
    return php->a[0];
}
bool HeapEmpty(HP* php)
{
    assert(php);
    return php->size == 0;
}

int HeapSize(HP* php)
{
    assert(php);
    return php->size;
}

void HeapSort(int* a, int n)
{
    /*for (int i = 1; i < n; i++)
    {
        AdjustUp(a, i);
    }*/
    for (int i = (n - 1 - 1) / 2; i >= 0; i++)//从最后一个非叶子节点开始调整
    {
        AdjustDown(a, n, i);
    }

    int end = n-1;
    while (end > 0)//每次将堆顶元素与最后一个元素交换，然后调整堆
    {
        Swap(&a[end], &a[0]);
        AdjustDown(a, end, 0);
        end--;
    }

}

void HeapDestory(HP* php)
{
    assert(php);

    free(php->a);
    php->a = NULL;
    php->capacity = php->capacity = 0;

}

//topk问题
void GetTopK(int* a, int n, int k)
{
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < k; i++)
	{
		HeapPush(&hp, a[i]);
	}

	for (int i = k; i < n; i++)
	{
		if (a[i] < HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}

	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
	HeapDestory(&hp);
}


//以下是topk问题的多种解法
void TopK_Heap(int* a, int n, int k)
{
    HP hp;
    HeapInit(&hp);
    for (int i = 0; i < k; i++)//先将k个元素放入一个小顶堆中，方便后续用于比较元素的大小
    {
        HeapPush(&hp, a[i]);
    }
    for (int i = k; i < n; i++)//从第k+1个元素开始，与堆顶元素进行比较，完成TopK问题的主要流程
    {
        if (a[i] > HeapTop(&hp))//当前元素比堆顶元素大的时候，将堆顶元素替换为这个元素
        {
            HeapTop(&hp);//首先弹出堆顶元素
            HeapPush(&hp, a[i]);//再将当前元素放入堆中
        }
    }
    while (!HeapEmpty(&hp))//当循环到结束时，这时堆中的元素就是所求的k个元素，将它们先打印再弹出即可、
    {
        printf("%d ", HeapTop(&hp));//依次打印元素
        HeapPop(&hp);//弹出元素
    }
    //完成一切工作之后，不要忘了销毁这个堆
    HeapDestory(&hp);
    
}
//堆的分类后的解法
void TopK_Sort(int* a, int n, int k)//
{
	HeapSort(a, n);
	for (int i = n - 1; i >= n - k; i--)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//冒泡排序的解法
void TopK_BubSort(int* a, int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)//冒泡排序的核心代码
        {
            int tmp = 0;
            if (a[j] > a[j + 1])//进行冒泡排序
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for (int i = n - 1; i >= n - k; i--)//返回排序完之后的k个元素
    {
        printf("%d ", a[i]);
    }
}



//快速排序的解法
void TopK_QuickSort(int* a, int n, int k)
{
	QuickSort(a, 0, n - 1, k);
	for (int i = n - 1; i >= n - k; i--)
	{
		printf("%d ", a[i]);
	}
}

void QuickSort(int* a, int left, int right, int k)
{
	if (left >= right)//当左边大于右边的时候，直接返回即可
	{
		return;
	}
	int div = PartSort(a, left, right);//进行快排
	if (div == k)//当div等于k的时候，直接返回
	{
		return;
	}
	else if (div < k)//当div小于k的时候，继续递归
	{
		QuickSort(a, div + 1, right, k);
	}
	else//当div大于k的时候，继续递归
	{
		QuickSort(a, left, div - 1, k);
	}
}

int PartSort(int *a,int left,int right)
{
    //设置左右两个指针，分别指向数组的第一个元素和最后一个元素
	int begin = left;
	int end = right;
	int tmp = a[right];//我们选择数组最后一个元素作为基准值
	while (begin < end)//快排的核心代码（具体的算法思想自行搜索）
	{
		while (begin < end && a[begin] >= tmp)
		{
			begin++;
		}
		while (begin < end && a[end] <= tmp)
		{
			end--;
		}
		if (begin < end)
		{
			Swap(&a[begin], &a[end]);
		}
	}
	Swap(&a[begin], &a[right]);
	return begin;
}
