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
        if (child+1 < n && a[child+1] > a[child])
        {
            ++child;
        }
        if (a[child] > a[parent])
        {
            Swap(&a[child] , &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
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