#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。

typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型
#define MAXSIZE 100
typedef struct
{
	ElemType* elem;
	int length;
}SqList;

//初始化
Status Init(SqList& L)
{
	L.elem = new ElemType[MAXSIZE];//分配MAXSIZE大小的空间
	if (!L.elem) exit(OVERFLOW);//分配失败
	L.length = 0;//空表
	return OK;
}

//取值
Status Get(SqList L, int i, ElemType& e)
{
	if (i<1 || i>L.length) return ERROR;//判断i是否合理

	e = L.elem[i - 1];//下标-1存储第i个元素

	return OK;

}

//查找
Status Find(SqList L, int i,ElemType e)
{

	for (i = 0; i < L.length; i++)//遍历
		if (L.elem < 0) printf("数据查找失败\n");
	if (L.elem[i] == e) return i + 1;//查找成功
	return 0;
}

//插入
Status InSr(SqList& L, int i, ElemType e)
{
	if ((i < 1) || (i > L.length + 1)) return ERROR;//判断i是否合理
	if (L.length == MAXSIZE) return ERROR;//存储满
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];//插入元素后的元素后移
	L.elem[i - 1] = e;//新元素放在i位置
	++L.length;//表长加1
	return OK;
}

//删除
Status Dele(SqList& L, int i)
{
	if ((i < 1) || (i > L.length)) return ERROR;//判断i是否合理
	for (int j = i; j <= L.length - 1; j++)//遍历
		L.elem[j - 1] = L.elem[j];//被删元素后的元素前移
	--L.length;//表长减1
	return OK;
}
//销毁
Status Destory(SqList& L)
{
	assert(L.elem);
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
}

//一般线性表合并
SqList MergeLists(SqList L1, SqList L2) 
{
	SqList mergedList;
	Init(mergedList); // 初始化新的线性表

	for (int i = 1; i <= L1.length; i++) 
	{
		ElemType e;
		Get(L1, i, e); // 获取第i个元素
		InSr(mergedList, mergedList.length + 1, e); // 将元素插入到新的线性表的末尾
	}

	for (int i = 1; i <= L2.length; i++) 
	{
		ElemType e;
		Get(L2, i, e); // 获取第i个元素
		InSr(mergedList, mergedList.length + 1, e); // 将元素插入到新的线性表的末尾
	}

	return mergedList;
}

//有序表合并
void OrderSq(SqList LC, SqList LD, SqList& LE)
{
	LE.length = LC.length + LD.length;//新表长度为两表长度之和
	LE.elem = new ElemType[LE.length];//分配新的数组空间
	int* pe = LE.elem;//指向新表首元素
	int* pc = LC.elem; 
	int* pd = LD.elem;//指针分别指向两表首元素
	int* pc_last = LC.elem + LC.length - 1; 
	int* pd_last = LD.elem + LD.length - 1;//指针分别指向两表末元素
	while ((pc < pc_last) && (pd < pd_last))
	{
		if (*pc <= *pd)	*pe++ = *pc++;//将较小的元素放在新表最后
		else *pe++ = *pd++;		//再将另一个较大的放在其次
	}
	while (pc <= pc_last) *pe++ = *pc++;
	while (pd <= pd_last) *pe++ = *pd++;//到达表尾，剩余元素插入新表最后

}  

