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

	//链表为空，新节点作为phead
	if (*pphead == NULL) {
		*pphead = newnode;
		return;
	}
	//链表不为空，找尾节点
	SLTNode* ptail = *pphead;
	while (ptail->next)
	{
		ptail = ptail->next;
	}
	//ptail就是尾节点
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
	//链表不能为空
	assert(*pphead);

	//链表不为空
	//链表只有一个节点，有多个节点
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
	//销毁尾结点
	free(ptail);
	ptail = NULL;
}
void SLTPopFront(SLTNode** pphead) {
	assert(pphead);
	//链表不能为空
	assert(*pphead);

	//让第二个节点成为新的头
	//把旧的头结点释放掉
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//查找
SLTNode* SLTFind(SLTNode** pphead, SLTDataType x) {
	assert(pphead);

	//遍历链表
	SLTNode* pcur = *pphead;
	while (pcur) //等价于pcur != NULL`
	{
		if (pcur->data == x) {
			return pcur;
		}
		pcur = pcur->next;
	}
	//没有找到
	return NULL;
}
//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead);
	assert(pos);
	//要加上链表不能为空
	assert(*pphead);

	SLTNode* newnode = SLTBuyNode(x);
	//pos刚好是头结点
	if (pos == *pphead) {
		//头插
		SLTPushFront(pphead, x);
		return;
	}

	//pos不是头结点的情况
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	//prev -> newnode -> pos
	prev->next = newnode;
	newnode->next = pos;
}
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);

	SLTNode* newnode = SLTBuyNode(x);

	//pos newnode pos->next
	newnode->next = pos->next;
	pos->next = newnode;
}
//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead);
	assert(*pphead);
	assert(pos);

	//pos刚好是头结点，没有前驱节点，执行头删
	if (*pphead == pos) {
		//头删
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
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos) {
	assert(pos);
	//pos->next不能为空
	assert(pos->next);

	//pos  pos->next  pos->next->next
	SLTNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}
//销毁链表
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