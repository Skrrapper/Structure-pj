#include "StackB.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// ��ʼ��ջ
void STInit(ST* ps) {
    assert(ps);

    ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ps->a == NULL) {
        perror("malloc fail");
        exit(EXIT_FAILURE); // ȷ���ʵ����˳��������
    }

    ps->capacity = 4;
    ps->top = 0; // top ����һ��Ԫ�ص�λ��
}

// ����ջ���ͷ��ڴ�
void STDestroy(ST* ps) {
    assert(ps);

    free(ps->a);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

// ��Ԫ��ѹ��ջ
void STPush(ST* ps, STDataType x) {
    assert(ps);

    if (ps->top == ps->capacity) {
        // ��������ڴ�
        STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
        if (tmp == NULL) {
            perror("realloc fail");
            exit(EXIT_FAILURE); // ȷ���ʵ����˳��������
        }
        ps->a = tmp;
        ps->capacity *= 2;
    }

    ps->a[ps->top] = x; // ѹ��Ԫ��
    ps->top++;
}

// ��ջ�е���Ԫ��
void STPop(ST* ps) {
    assert(ps);
    assert(!STEmpty(ps));

    ps->top--;
}

// ��ȡջ�Ĵ�С
int STSize(const ST* ps) {
    assert(ps);

    return ps->top;
}

// ���ջ�Ƿ�Ϊ��
bool STEmpty(const ST* ps) {
    assert(ps);

    return ps->top == 0;
}

// ��ȡջ��Ԫ��
STDataType STTop(const ST* ps) {
    assert(ps);
    assert(!STEmpty(ps));

    return ps->a[ps->top - 1];
}


//ʹ������ջʵ�ֶ��е�push��pop��peek��empty
void push(int x,int s1)
{
    STPush(&s1, x);
}

void pop(int s1, int s2)//�Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
{
    if (STEmpty(&s2))//���ջ2Ϊ�գ���ô�ͽ�ջ1�е�Ԫ��ȫ��ѹ��ջ2��
    {
        while (!STEmpty(&s1))//ֱ��ջ1�е�Ԫ��ȫ��ѹ��ջ2��
        {
            STPush(&s2, STTop(&s1));
            STPop(&s1);
        }
    }
    STPop(&s2);//��ʱ����ջ��Ԫ�ؾ��Ƕ��еĶ���Ԫ��
}

void peek(int s1, int s2)// ���ض��п�ͷ��Ԫ��
{
    if (STEmpty(&s2))//���ջ2Ϊ�գ���ô�ͽ�ջ1�е�Ԫ��ȫ��ѹ��ջ2��
    {
        while (!STEmpty(&s1))//ֱ��ջ1�е�Ԫ��ȫ��ѹ��ջ2��
        {
            STPush(&s2, STTop(&s1));
            STPop(&s1);
        }
    }
    printf("%d\n", STTop(&s2));//��ʱ����ջ��Ԫ�ؾ��Ƕ��еĶ���Ԫ��
}

bool empty(int s1, int s2)//�������Ϊu�շ���true�����򷵻�false
{
	if (STEmpty(&s1) && STEmpty(&s2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
