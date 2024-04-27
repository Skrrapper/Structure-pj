#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
#define NAME_MAX 100
#define GENDER_MAX 10
#define TEL_MAX 12
#define ADDR_MAX 100

//ͨѶ¼��������
typedef struct PersonInfo
{
	char name[NAME_MAX];
	int age;
	char gender[GENDER_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}Info;

//ʹ��˳���ǰ������
struct SeqList;

typedef struct SeqList Contact;

//ͨѶ¼�еĲ���

//ͨѶ¼�ĳ�ʼ��������
void ContactInit(Contact* pcon);//��ʼ��
void ContactDestory(Contact* pcon);//����

//����
void ContactAdd(Contact* pcon);
//ɾ��
void ContactDel(Contact* pcon);
//�޸�
void ContactModify(Contact* pcon);
//����
void ContactFind(Contact* pcon);
//�鿴
void ContactShow(Contact* pcon);

