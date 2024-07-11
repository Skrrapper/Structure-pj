#include"SList.h"
void SLTPrint(SLTNode* phead) {
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

SLTNode* SLTBuyNode(SLTDataType x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) {
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);

	SLTNode* newnode = SLTBuyNode(x);

	//����Ϊ�գ��½ڵ���Ϊphead
	if (*pphead == NULL) {
		*pphead = newnode;
		return;
	}
	//����Ϊ�գ���β�ڵ�
	SLTNode* ptail = *pphead;
	while (ptail->next)
	{
		ptail = ptail->next;
	}
	//ptail����β�ڵ�
	ptail->next = newnode;
}
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);

	//newnode *pphead
	newnode->next = *pphead;
	*pphead = newnode;
}
void SLTPopBack(SLTNode** pphead) {
	assert(pphead);
	//������Ϊ��
	assert(*pphead);

	//����Ϊ��
	//����ֻ��һ���ڵ㣬�ж���ڵ�
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLTNode* ptail = *pphead;
	SLTNode* prev = NULL;
	while (ptail->next)
	{
		prev = ptail;
		ptail = ptail->next;
	}

	prev->next = NULL;
	//����β���
	free(ptail);
	ptail = NULL;
}
void SLTPopFront(SLTNode** pphead) {
	assert(pphead);
	//������Ϊ��
	assert(*pphead);

	//�õڶ����ڵ��Ϊ�µ�ͷ
	//�Ѿɵ�ͷ����ͷŵ�
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//����
SLTNode* SLTFind(SLTNode** pphead, SLTDataType x) {
	assert(pphead);

	//��������
	SLTNode* pcur = *pphead;
	while (pcur) //�ȼ���pcur != NULL`
	{
		if (pcur->data == x) {
			return pcur;
		}
		pcur = pcur->next;
	}
	//û���ҵ�
	return NULL;
}
//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead);
	assert(pos);
	//Ҫ����������Ϊ��
	assert(*pphead);

	SLTNode* newnode = SLTBuyNode(x);
	//pos�պ���ͷ���
	if (pos == *pphead) {
		//ͷ��
		SLTPushFront(pphead, x);
		return;
	}

	//pos����ͷ�������
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	//prev -> newnode -> pos
	prev->next = newnode;
	newnode->next = pos;
}
//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);

	SLTNode* newnode = SLTBuyNode(x);

	//pos newnode pos->next
	newnode->next = pos->next;
	pos->next = newnode;
}
//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead);
	assert(*pphead);
	assert(pos);

	//pos�պ���ͷ��㣬û��ǰ���ڵ㣬ִ��ͷɾ
	if (*pphead == pos) {
		//ͷɾ
		SLTPopFront(pphead);
		return;
	}

	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	//prev pos pos->next
	prev->next = pos->next;
	free(pos);
	pos = NULL;
}
//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos) {
	assert(pos);
	//pos->next����Ϊ��
	assert(pos->next);

	//pos  pos->next  pos->next->next
	SLTNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}
//��������
void SListDesTroy(SLTNode** pphead) {
	assert(pphead);
	assert(*pphead);

	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}