#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣

typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����
#define MAXSIZE 100
typedef struct
{
	ElemType* elem;
	int length;
}SqList;

//��ʼ��
Status Init(SqList& L)
{
	L.elem = new ElemType[MAXSIZE];//����MAXSIZE��С�Ŀռ�
	if (!L.elem) exit(OVERFLOW);//����ʧ��
	L.length = 0;//�ձ�
	return OK;
}

//ȡֵ
Status Get(SqList L, int i, ElemType& e)
{
	if (i<1 || i>L.length) return ERROR;//�ж�i�Ƿ����

	e = L.elem[i - 1];//�±�-1�洢��i��Ԫ��

	return OK;

}

//����
Status Find(SqList L, int i,ElemType e)
{

	for (i = 0; i < L.length; i++)//����
		if (L.elem < 0) printf("���ݲ���ʧ��\n");
	if (L.elem[i] == e) return i + 1;//���ҳɹ�
	return 0;
}

//����
Status InSr(SqList& L, int i, ElemType e)
{
	if ((i < 1) || (i > L.length + 1)) return ERROR;//�ж�i�Ƿ����
	if (L.length == MAXSIZE) return ERROR;//�洢��
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];//����Ԫ�غ��Ԫ�غ���
	L.elem[i - 1] = e;//��Ԫ�ط���iλ��
	++L.length;//����1
	return OK;
}

//ɾ��
Status Dele(SqList& L, int i)
{
	if ((i < 1) || (i > L.length)) return ERROR;//�ж�i�Ƿ����
	for (int j = i; j <= L.length - 1; j++)//����
		L.elem[j - 1] = L.elem[j];//��ɾԪ�غ��Ԫ��ǰ��
	--L.length;//����1
	return OK;
}
//����
Status Destory(SqList& L)
{
	assert(L.elem);
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
}

//һ�����Ա�ϲ�
SqList MergeLists(SqList L1, SqList L2) 
{
	SqList mergedList;
	Init(mergedList); // ��ʼ���µ����Ա�

	for (int i = 1; i <= L1.length; i++) 
	{
		ElemType e;
		Get(L1, i, e); // ��ȡ��i��Ԫ��
		InSr(mergedList, mergedList.length + 1, e); // ��Ԫ�ز��뵽�µ����Ա��ĩβ
	}

	for (int i = 1; i <= L2.length; i++) 
	{
		ElemType e;
		Get(L2, i, e); // ��ȡ��i��Ԫ��
		InSr(mergedList, mergedList.length + 1, e); // ��Ԫ�ز��뵽�µ����Ա��ĩβ
	}

	return mergedList;
}

//�����ϲ�
void OrderSq(SqList LC, SqList LD, SqList& LE)
{
	LE.length = LC.length + LD.length;//�±���Ϊ������֮��
	LE.elem = new ElemType[LE.length];//�����µ�����ռ�
	int* pe = LE.elem;//ָ���±���Ԫ��
	int* pc = LC.elem; 
	int* pd = LD.elem;//ָ��ֱ�ָ��������Ԫ��
	int* pc_last = LC.elem + LC.length - 1; 
	int* pd_last = LD.elem + LD.length - 1;//ָ��ֱ�ָ������ĩԪ��
	while ((pc < pc_last) && (pd < pd_last))
	{
		if (*pc <= *pd)	*pe++ = *pc++;//����С��Ԫ�ط����±����
		else *pe++ = *pd++;		//�ٽ���һ���ϴ�ķ������
	}
	while (pc <= pc_last) *pe++ = *pc++;
	while (pd <= pd_last) *pe++ = *pd++;//�����β��ʣ��Ԫ�ز����±����

}  

