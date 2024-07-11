#define _CRT_SECURE_NO_WARNINGS 1
//分别利用计数指针i和j指示主串S和模式串T中当前正待比较的字符位置。
// 算法的基本思想是：从主串S的第pos个字符起和模式的第一个字符比较，
// 若相等，则继续逐个比较后续字符，
// 则从主串的下一个字符起再重新和模式的字符比较之。
// 依次类推
// 直至模式T中的每个字符依次和主串S中的一个连续的字符序列相等，则称匹配成功，
// 函数值为和模式T中第一个字符相等的字符在主串中的序号，
// 否则称匹配不成功，函数值为零。
// 
//你的任务是将S中每次比较的字符输出来，并将匹配的序号输出
#define MAXLEN 255
#include<stdio.h>
#include<string.h>
#include<math.h>
#define mod 1000000008
#define pi acos(-1.0)typedef struct
typedef struct
{
	char ch[MAXLEN + 1];
	int length;
}SString;

int Index_BF(SString S, SString T)
{
	int pos = 0;
	int i = 0;int j = 0;
	while (i < S.length && j < T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			printf("%c", S.ch[i]); // 输出每次比较的字符
			++i; ++j;	
		}
		else
		{
			printf("%c", S.ch[i]); // 输出每次比较的字符
			j = 0;
			i = ++pos;

		}
	}
	putchar('\n');
	if (j > T.length)
		return i - T.length;
	else return 0;
}

int main()
{
	SString S, T;
	int pos;
	int n, m, j, k, i;

	while (~scanf("%s", S.ch))
	{
		scanf("%s", T.ch);
		S.length = strlen(S.ch);
		T.length = strlen(T.ch);
		int ans = Index_BF(S, T) + 1;
		printf("%d\n", ans);
	}
	return 0;
}

//typedef struct
//{
//	char s[1000];
//	int len;
//}SString;
//
//int Index(SString S, SString T)
//{
//	int pos = 0;
//	int i = 0, j = 0;
//
//	while (i < S.len && j < T.len)
//	{
//		if (S.s[i] == T.s[j])
//		{
//			printf("%c", S.s[i]);
//			++i; ++j;
//		}
//		else
//		{
//			printf("%c", S.s[i]);
//
//			j = 0;
//			i = ++pos;
//
//		}
//	}
//	putchar('\n');
//	if (j == T.len)
//		return pos;
//	else
//		return -1;
//}
//
//int main()
//{
//	SString S, T;
//	int pos;
//	int n, m, j, k, i;
//
//	while (~scanf("%s", S.s))
//	{
//		scanf("%s", T.s);
//		S.len = strlen(S.s);
//		T.len = strlen(T.s);
//		int ans = Index(S, T) + 1;
//		printf("%d\n", ans);
//	}
//	return 0;
//}