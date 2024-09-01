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

//����child���λ�ã�ǰ������ݶ�Ҫ���ɶ�
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

//�����������Ƕ�
void AdjustDown(HPDataType* a, int n,int parent)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        //ѡ�����Һ����д����һ��
        if (child+1 < n && a[child+1] > a[child])//����Һ��Ӵ��ڲ����Һ��Ӵ�������
        {
            ++child;
        }
        if (a[child] > a[parent])//������Ӵ��ڸ���
        {
            Swap(&a[child] , &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else//�������С�ڸ���
        {
            break;
        }

    }
}

void HeapPop(HP* php)
{
    assert(php);
    assert(!HeapEmpty(php));
    
    //ɾ������
    Swap(&php->a[0], &php->size - 1);
    php->size--;
}

////ð������
//    void HeapPop(HP* php)
//{
//	assert(php);
//	assert(!HeapEmpty(php));
//
//	//ɾ������
//	Swap(&php->a[0], &php->size - 1);
//	php->size--;
//
//	//���µ���
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
    for (int i = (n - 1 - 1) / 2; i >= 0; i++)//�����һ����Ҷ�ӽڵ㿪ʼ����
    {
        AdjustDown(a, n, i);
    }

    int end = n-1;
    while (end > 0)//ÿ�ν��Ѷ�Ԫ�������һ��Ԫ�ؽ�����Ȼ�������
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

//topk����
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


//������topk����Ķ��ֽⷨ
void TopK_Heap(int* a, int n, int k)
{
    HP hp;
    HeapInit(&hp);
    for (int i = 0; i < k; i++)//�Ƚ�k��Ԫ�ط���һ��С�����У�����������ڱȽ�Ԫ�صĴ�С
    {
        HeapPush(&hp, a[i]);
    }
    for (int i = k; i < n; i++)//�ӵ�k+1��Ԫ�ؿ�ʼ����Ѷ�Ԫ�ؽ��бȽϣ����TopK�������Ҫ����
    {
        if (a[i] > HeapTop(&hp))//��ǰԪ�رȶѶ�Ԫ�ش��ʱ�򣬽��Ѷ�Ԫ���滻Ϊ���Ԫ��
        {
            HeapTop(&hp);//���ȵ����Ѷ�Ԫ��
            HeapPush(&hp, a[i]);//�ٽ���ǰԪ�ط������
        }
    }
    while (!HeapEmpty(&hp))//��ѭ��������ʱ����ʱ���е�Ԫ�ؾ��������k��Ԫ�أ��������ȴ�ӡ�ٵ������ɡ�
    {
        printf("%d ", HeapTop(&hp));//���δ�ӡԪ��
        HeapPop(&hp);//����Ԫ��
    }
    //���һ�й���֮�󣬲�Ҫ�������������
    HeapDestory(&hp);
    
}
//�ѵķ����Ľⷨ
void TopK_Sort(int* a, int n, int k)//
{
	HeapSort(a, n);
	for (int i = n - 1; i >= n - k; i--)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//ð������Ľⷨ
void TopK_BubSort(int* a, int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)//ð������ĺ��Ĵ���
        {
            int tmp = 0;
            if (a[j] > a[j + 1])//����ð������
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for (int i = n - 1; i >= n - k; i--)//����������֮���k��Ԫ��
    {
        printf("%d ", a[i]);
    }
}



//��������Ľⷨ
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
	if (left >= right)//����ߴ����ұߵ�ʱ��ֱ�ӷ��ؼ���
	{
		return;
	}
	int div = PartSort(a, left, right);//���п���
	if (div == k)//��div����k��ʱ��ֱ�ӷ���
	{
		return;
	}
	else if (div < k)//��divС��k��ʱ�򣬼����ݹ�
	{
		QuickSort(a, div + 1, right, k);
	}
	else//��div����k��ʱ�򣬼����ݹ�
	{
		QuickSort(a, left, div - 1, k);
	}
}

int PartSort(int *a,int left,int right)
{
    //������������ָ�룬�ֱ�ָ������ĵ�һ��Ԫ�غ����һ��Ԫ��
	int begin = left;
	int end = right;
	int tmp = a[right];//����ѡ���������һ��Ԫ����Ϊ��׼ֵ
	while (begin < end)//���ŵĺ��Ĵ��루������㷨˼������������
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
