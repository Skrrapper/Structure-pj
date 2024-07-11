#define  _CRT_SECURE_NO_WARNINGS 1
#include "LContact.h"
#include "SList.h"

void LoadContact(contact** con) {
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL) {
		perror("开辟失败！\n");
		return;
	}
	//读取数据
	PeoInfo info;
	while (fread(&info,sizeof(info),1,pf))
	{
		LTPushBack(con, info);
	}
	printf("导入数据成功！\n");
}

//初始化
void InitContact(contact** con) {
	LoadContact(con);
}

//增添
void AddContact(contact** con) {
	PeoInfo info;
	printf("请输入姓名、性别、年龄、联系方式、地址\n");
	scanf("%s %s %d %s %s", &info.name, &info.sex, &info.age, &info.tel, &info.addr);

		LTPushBack(con, info);
		printf("插入成功！\n");
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

//删除
void DelContact(contact** con) {
	char name[NAME_MAX];
	printf("输入删除对象:\n");
	scanf("%s", name);

	contact* pos = FindByName(*con, name);
	if (pos == NULL) {
		printf("用户不存在！\n");
		return;
	}
	SLTErase(con, pos);
		printf("删除成功！\n");
}

//展示
void ShowContact(contact* con) {
	printf("%-10s %-4s  %-4s  %-15s  %20s\n", "姓名", "性别", "年龄", "联系方式", "地址");
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

//查找
void FindContact(contact* con) {
	char name[NAME_MAX];
	printf("请输入要查找的用户姓名\n");
	scanf("%s", name);

	contact* cur = FindByName(con, name);
	if (cur == NULL) {
		printf("用户不存在！\n");
		return;
	}
	printf("查找成功！，用户信息如下：\n");
	printf("%-10s %-4s  %-4s  %-15s  %20s\n",
		cur->data.name,
		cur->data.sex,
		cur->data.age,
		cur->data.tel,
		cur->data.addr);
}

//修改
void ModifyContact(contact* con) {
	char name[NAME_MAX];
	printf("请输入要查找的用户姓名\n");
	scanf("%s", name);
	contact* pos = FindByName(con,name);
	if (pos == NULL) {
		printf("用户不存在！\n");
		return;
	}
	int choice;
	printf("请选择要修改的信息：\n");
	printf("1. 姓名\n2. 性别\n3. 年龄\n4. 联系电话\n5. 地址\n");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		printf("请输入要修改的姓名：\n");
		scanf("%s", pos->data.name);
		break;
	case 2:
		printf("请输入要修改的性别：\n");
		scanf("%s", pos->data.sex);
		break;
	case 3:
		printf("请输入要修改的年龄：\n");
		scanf("%d", &pos->data.age);
		break;
	case 4:
		printf("请输入要修改的联系电话：\n");
		scanf("%s", pos->data.tel);
		break;
	case 5:
		printf("请输入要修改的地址：\n");
		scanf("%s", pos->data.addr);
		break;
	default:
		printf("无效的选项！\n");
		break;
	}
	printf("修改成功！\n");
}

//保存
void SaveContact(contact* con) {
	FILE* pf = fopen("Contact.txt", "wb");
	if (pf == NULL) {
		perror("未找到对应文件！\n");
		return;
	}
	contact* cur = con;
	while (cur)
	{
		fwrite(&(cur->data), sizeof(cur->data), 1, pf);
		cur = cur->next;
	}
	printf("保存成功！\n");
}

//销毁
void DestoryContact(contact** con) {
	SaveContact(*con);
	SListDesTroy(con);
}