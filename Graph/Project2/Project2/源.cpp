#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a[20], b[] = "The sky in blue."; int i;
	for (int i = 0; i < 10; i++)scanf("%c", &a[i]);
	a[i] = '\0';
	fgets(b);
	printf("%s%s\n", a, b);
}