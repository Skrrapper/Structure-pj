#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//��ʼ��������
void SLInit(SL* ps) {
	ps->arr = NULL; //����int ����Info���� 
	ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL) {
			perror("realloc fail!");
			exit(1);
		}
		//���ݳɹ�
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

//˳����ͷ��/β������
void SLPushBack(SL* ps, SLDataType x) {
	//����--�ֱ��Ľ����ʽ
	//assert(ps != NULL);
	assert(ps);

	//if�ж�--����Ľ����ʽ
	//if (ps == NULL) {
	//	return;
	//}

	//�ռ䲻��������
	SLCheckCapacity(ps);

	//�ռ��㹻��ֱ�Ӳ���
	ps->arr[ps->size++] = x;
	//ps->size++;
}
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);

	//�ж��Ƿ�����
	SLCheckCapacity(ps);

	//����������Ų��һλ
	for (int i = ps->size; i > 0; i--) //i = 1
	{
		ps->arr[i] = ps->arr[i - 1]; //ps->arr[1] = ps->arr[0]
	}
	ps->arr[0] = x;
	ps->size++;
}

//˳����ͷ��/β��ɾ��
void SLPopBack(SL* ps) {
	assert(ps);
	assert(ps->size);

	//˳���Ϊ��
	//ps->arr[ps->size - 1] = -1;
	ps->size--;
}
void SLPopFront(SL* ps) {
	assert(ps);
	assert(ps->size);

	//��Ϊ��ִ��Ų������
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//ָ��λ��֮ǰ��������
void SLInsert(SL* ps, int pos, SLDataType x) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLCheckCapacity(ps);

	//pos��֮�����������Ų��һλ��pos�ճ���
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1]; //ps->arr[pos+1] = ps->arr[pos]
	}
	ps->arr[pos] = x;
	ps->size++;
}
//ɾ��ָ��λ������
void SLErase(SL* ps, int pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	//pos�Ժ��������ǰŲ��һλ
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];//ps->arr[i-2] = ps->arr[i-1];
	}
	ps->size--;
}

//��˳����в���X
//int SLFind(SL* ps, SLDataType x) {
//	//���϶��ԶԴ���Ľ�׳�Ը���
//	assert(ps);
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->arr[i] == x) {
//			return i;
//		}
//	}
//	return -1;
//}

void SLDestroy(SL* ps) {
	assert(ps);

	if (ps->arr) {
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SLPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ",ps->arr[i]);
	}
	printf("\n");
}