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

//��ʼ��
void InitContact(contact** con);
//����ͨѶ¼����
void AddContact(contact** con);
//ɾ��ͨѶ¼����
void DelContact(contact** con);
//����ͨѶ¼����
void FindContact(contact** con);
//�޸�ͨѶ¼����
void ModifyContact(contact** con);
//չʾͨѶ¼����
void ShowContact(contact** con);
//����ͨѶ¼����
void DestoryContact(contact** con);
