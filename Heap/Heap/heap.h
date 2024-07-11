#define CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapPush(HP* php, HPDataType x);
void AdjustUp(HPDataType* a, int child);
void Swap(HPDataType* p1, HPDataType* p2);
void HeapPop(HP* php);
void AdjustDown(HPDataType* a, int child);
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);