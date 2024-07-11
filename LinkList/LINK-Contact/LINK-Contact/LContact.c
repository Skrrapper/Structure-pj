#define  _CRT_SECURE_NO_WARNINGS 1
#include "LContact.h"
#include "SList.h"

void LoadContact(contact** con) {
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL) {
		perror("����ʧ�ܣ�\n");
		return;
	}
	//��ȡ����
	PeoInfo info;
	while (fread(&info,sizeof(info),1,pf))
	{
		LTPushBack(con, info);
	}
	printf("�������ݳɹ���\n");
}

//��ʼ��
void InitContact(contact** con) {
	LoadContact(con);
}

//����
void AddContact(contact** con) {
	PeoInfo info;
	printf("�������������Ա����䡢��ϵ��ʽ����ַ\n");
	scanf("%s %s %d %s %s", &info.name, &info.sex, &info.age, &info.tel, &info.addr);

		LTPushBack(con, info);
		printf("����ɹ���\n");
}

contact* FindByName(contact** con, char name[]) {
	contact* cur = con;
	while (cur) {
		if (strcmp(cur->data,name) == 0) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//ɾ��
void DelContact(contact** con) {
	char name[NAME_MAX];
	printf("����ɾ������:\n");
	scanf("%s", name);

	contact* pos = FindByName(*con, name);
	if (pos == NULL) {
		printf("�û������ڣ�\n");
		return;
	}
	SLTErase(con, pos);
		printf("ɾ���ɹ���\n");
}

//չʾ
void ShowContact(contact* con) {
	printf("%-10s %-4s  %-4s  %-15s  %20s\n", "����", "�Ա�", "����", "��ϵ��ʽ", "��ַ");
		contact* cur = con;
		while (cur) {
			printf("%-10s %-4s  %-4s  %-15s  %20s\n",
				cur->data.name,
				cur->data.sex,
				cur->data.age,
				cur->data.tel,
				cur->data.addr);
			cur = cur->next;
		}
}

//����
void FindContact(contact* con) {
	char name[NAME_MAX];
	printf("������Ҫ���ҵ��û�����\n");
	scanf("%s", name);

	contact* cur = FindByName(con, name);
	if (cur == NULL) {
		printf("�û������ڣ�\n");
		return;
	}
	printf("���ҳɹ������û���Ϣ���£�\n");
	printf("%-10s %-4s  %-4s  %-15s  %20s\n",
		cur->data.name,
		cur->data.sex,
		cur->data.age,
		cur->data.tel,
		cur->data.addr);
}

//�޸�
void ModifyContact(contact* con) {
	char name[NAME_MAX];
	printf("������Ҫ���ҵ��û�����\n");
	scanf("%s", name);
	contact* pos = FindByName(con,name);
	if (pos == NULL) {
		printf("�û������ڣ�\n");
		return;
	}
	int choice;
	printf("��ѡ��Ҫ�޸ĵ���Ϣ��\n");
	printf("1. ����\n2. �Ա�\n3. ����\n4. ��ϵ�绰\n5. ��ַ\n");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		printf("������Ҫ�޸ĵ�������\n");
		scanf("%s", pos->data.name);
		break;
	case 2:
		printf("������Ҫ�޸ĵ��Ա�\n");
		scanf("%s", pos->data.sex);
		break;
	case 3:
		printf("������Ҫ�޸ĵ����䣺\n");
		scanf("%d", &pos->data.age);
		break;
	case 4:
		printf("������Ҫ�޸ĵ���ϵ�绰��\n");
		scanf("%s", pos->data.tel);
		break;
	case 5:
		printf("������Ҫ�޸ĵĵ�ַ��\n");
		scanf("%s", pos->data.addr);
		break;
	default:
		printf("��Ч��ѡ�\n");
		break;
	}
	printf("�޸ĳɹ���\n");
}

//����
void SaveContact(contact* con) {
	FILE* pf = fopen("Contact.txt", "wb");
	if (pf == NULL) {
		perror("δ�ҵ���Ӧ�ļ���\n");
		return;
	}
	contact* cur = con;
	while (cur)
	{
		fwrite(&(cur->data), sizeof(cur->data), 1, pf);
		cur = cur->next;
	}
	printf("����ɹ���\n");
}

//����
void DestoryContact(contact** con) {
	SaveContact(*con);
	SListDesTroy(con);
}