#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
#define NAME_MAX 100
#define GENDER_MAX 10
#define TEL_MAX 12
#define ADDR_MAX 100

//通讯录数据类型
typedef struct PersonInfo
{
	char name[NAME_MAX];
	int age;
	char gender[GENDER_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}Info;

//使用顺序表前置声明
struct SeqList;

typedef struct SeqList Contact;

//通讯录中的操作

//通讯录的初始化和销毁
void ContactInit(Contact* pcon);//初始化
void ContactDestory(Contact* pcon);//销毁

//增加
void ContactAdd(Contact* pcon);
//删除
void ContactDel(Contact* pcon);
//修改
void ContactModify(Contact* pcon);
//查找
void ContactFind(Contact* pcon);
//查看
void ContactShow(Contact* pcon);

