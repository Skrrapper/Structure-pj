//#include "Contact.h"//��SeqList.h���Ѿ������˸�ͷ�ļ�
#include "SeqList.h"

//ͨѶ¼�˵�
void menu()
{
printf("---------------ͨѶ¼----------------\n");
printf("---------1.���       2.ɾ��---------\n");
printf("---------3.�޸�       4.����---------\n");
printf("---------5.�鿴       0.�ر�---------\n");
printf("-------------------------------------\n");

}

int main()
{
	int op = -1;
	Contact con;
	ContactInit(&con);
	do {
		menu();
		printf("��ѡ�����\n");
		scanf("%d", &op);//�û�������Ҫ���еĲ���
		switch (op)
		{
		case 1:
		    //�����ϵ��
			ContactAdd(&con);
			break;
		case 2:
			//ɾ����ϵ��
			ContactDel(&con);
			break;
		case 3:
			//�޸���ϵ��
			ContactModify(&con);
			break;
		case 4:
			//������ϵ��
			ContactFind(&con);
			break;
		case 5:
			//�鿴��ϵ��
			ContactShow(&con);
			break;
		case 0:
			//�˳�
			printf("ͨѶ¼�˳�");
			break;
		default:
			printf("û��������е�ѡ�\n");
			break;
		}



	} while (op!=0);//ѭ�������ﵽ����������Ŀ��
	//����ͨѶ¼
	ContactDestory(&con);
	return 0;
}
