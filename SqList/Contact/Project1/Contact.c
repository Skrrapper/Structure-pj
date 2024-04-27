#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
#include "SeqList.h"
#include <string.h>
//文件历史存储
void LoadContact(Contact* con) {
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL) {
		perror("fopen error!\n");
		return;
	}
	//循环读取⽂件数据
	Info info;
	while (fread(&info, sizeof(Info), 1, pf))
	{
		SLPushBack(con, info);
	}
	printf("历史数据导⼊通讯录成功！\n");
}

//通讯录的初始化和销毁
void ContactInit(Contact* pcon)//初始化
{
	SLInit(pcon);
}

void ContactDestory(Contact* pcon)//销毁
{
	SLDestroy(pcon);
}
//直接调用顺序表中的初始化和删除函数


//增加
void ContactAdd(Contact* pcon)
{
	Info info;//保存在该结构体内

	printf("请输入联系人姓名：\n");
	scanf("%s", info.name);
	printf("请输入联系人年龄：\n");
	scanf("%d", &info.age);
	printf("请输入联系人性别：\n");
	scanf("%s", info.gender);
	printf("请输入联系人电话：\n");
	scanf("%s", info.tel);
	printf("请输入联系人住址：\n");
	scanf("%s", info.addr);

	//保存数据到通讯录（顺序表）
	SLPushBack(pcon, info);
}
//删除
void ContactDel(Contact* pcon) 
{
//先查找Find来判断是否有这个联系人
	printf("输入要删除联系人的姓名:\n");
	char name[NAME_MAX];
	scanf("%s", name);

	int findIndex = FindByName(pcon, name);
	if (findIndex < 0)
	{
		printf("要删除的联系人不存在！\n");
			return;
	}
	//执行删除操作
	SLErase(pcon, findIndex);
	printf("联系人删除成功！\n");
}
//修改
void ContactModify(Contact* pcon)
{
	char name[NAME_MAX];
	printf("请输入要修改联系人的姓名\n");
	scanf("%s", name);

	int findIndex = FindByName(pcon, name);
		if (findIndex < 0)
		{
			printf("要修改的联系人不存在！\n");
			return;
		}
		//找到了，则执行修改Modify
		printf("请输入姓名：\n");
		scanf("%s", pcon->arr[findIndex].name);
		printf("请输入年龄：\n");
		scanf("%d", &pcon->arr[findIndex].age);
		printf("请输入性别：\n");
		scanf("%s", pcon->arr[findIndex].gender);
		printf("请输入电话：\n");
		scanf("%s", pcon->arr[findIndex].tel);
		printf("请输入都着急哦：\n");
		scanf("%s", pcon->arr[findIndex].addr);

		printf("联系人修改成功！\n");
}
//查找
//1.查找的指标
int FindByName(Contact* pcon, char name[])
{
	for (int i = 0; i < pcon->size; i++)
	{
		if (strcmp(pcon->arr[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//2.进行查找
void ContactFind(Contact* pcon)
{
	char name[NAME_MAX];
	printf("请输入要查找的用户姓名：\n");
	scanf("%s", name);

	int findIndex = FindByName(pcon, name);
	if (findIndex < 0) 
	{
		printf("该联系人不存在！\n");
		return;
	}
	//找到了，打印一下查找的联系人信息
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");
	printf("%s %s %d %s %s\n",
		pcon->arr[findIndex].name,
		pcon->arr[findIndex].gender,
		pcon->arr[findIndex].age,
		pcon->arr[findIndex].tel,
		pcon->arr[findIndex].addr
		);
}
//查看
void ContactShow(Contact* pcon)
{
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");

	for (int i = 0; i < pcon->size; i++)
	{

		printf("%s %s %d %s %s\n",
			pcon->arr[i].name,
			pcon->arr[i].gender,
			pcon->arr[i].age,
			pcon->arr[i].tel,
			pcon->arr[i].addr);
	}
}
