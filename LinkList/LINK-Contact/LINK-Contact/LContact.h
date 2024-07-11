#pragma once
#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100

typedef struct SListNode contact;

typedef struct PersonInfo {
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//初始化
void InitContact(contact** con);
//增添通讯录数据
void AddContact(contact** con);
//删除通讯录数据
void DelContact(contact** con);
//查找通讯录数据
void FindContact(contact** con);
//修改通讯录数据
void ModifyContact(contact** con);
//展示通讯录数据
void ShowContact(contact** con);
//销毁通讯录数据
void DestoryContact(contact** con);
