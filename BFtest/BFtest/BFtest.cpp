#define _CRT_SECURE_NO_WARNINGS 1
//�ֱ����ü���ָ��i��jָʾ����S��ģʽ��T�е�ǰ�����Ƚϵ��ַ�λ�á�
// �㷨�Ļ���˼���ǣ�������S�ĵ�pos���ַ����ģʽ�ĵ�һ���ַ��Ƚϣ�
// ����ȣ����������ȽϺ����ַ���
// �����������һ���ַ��������º�ģʽ���ַ��Ƚ�֮��
// ��������
// ֱ��ģʽT�е�ÿ���ַ����κ�����S�е�һ���������ַ�������ȣ����ƥ��ɹ���
// ����ֵΪ��ģʽT�е�һ���ַ���ȵ��ַ��������е���ţ�
// �����ƥ�䲻�ɹ�������ֵΪ�㡣
// 
//��������ǽ�S��ÿ�αȽϵ��ַ������������ƥ���������
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
			printf("%c", S.ch[i]); // ���ÿ�αȽϵ��ַ�
			++i; ++j;	
		}
		else
		{
			printf("%c", S.ch[i]); // ���ÿ�αȽϵ��ַ�
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