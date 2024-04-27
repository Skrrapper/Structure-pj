//#include "Contact.h"//在SeqList.h中已经包含了该头文件
#include "SeqList.h"

//通讯录菜单
void menu()
{
printf("---------------通讯录----------------\n");
printf("---------1.添加       2.删除---------\n");
printf("---------3.修改       4.查找---------\n");
printf("---------5.查看       0.关闭---------\n");
printf("-------------------------------------\n");

}

int main()
{
	int op = -1;
	Contact con;
	ContactInit(&con);
	do {
		menu();
		printf("请选择操作\n");
		scanf("%d", &op);//用户输入想要进行的操作
		switch (op)
		{
		case 1:
		    //添加联系人
			ContactAdd(&con);
			break;
		case 2:
			//删除联系人
			ContactDel(&con);
			break;
		case 3:
			//修改联系人
			ContactModify(&con);
			break;
		case 4:
			//查找联系人
			ContactFind(&con);
			break;
		case 5:
			//查看联系人
			ContactShow(&con);
			break;
		case 0:
			//退出
			printf("通讯录退出");
			break;
		default:
			printf("没有你想进行的选项！\n");
			break;
		}



	} while (op!=0);//循环操作达到反复操作的目的
	//销毁通讯录
	ContactDestory(&con);
	return 0;
}
