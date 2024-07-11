#define CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

int main()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 5);
	HeapPush(&hp, 6);
	HeapPush(&hp, 7);
	HeapPush(&hp, 8);
	HeapPush(&hp, 9);

	while (!HeapEmpty(&hp))
	{
		printf("%d", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
	return 0;
}