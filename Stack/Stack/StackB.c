#include "StackB.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// 初始化栈
void STInit(ST* ps) {
    assert(ps);

    ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ps->a == NULL) {
        perror("malloc fail");
        exit(EXIT_FAILURE); // 确保适当地退出或处理错误
    }

    ps->capacity = 4;
    ps->top = 0; // top 是下一个元素的位置
}

// 销毁栈并释放内存
void STDestroy(ST* ps) {
    assert(ps);

    free(ps->a);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

// 将元素压入栈
void STPush(ST* ps, STDataType x) {
    assert(ps);

    if (ps->top == ps->capacity) {
        // 分配更多内存
        STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
        if (tmp == NULL) {
            perror("realloc fail");
            exit(EXIT_FAILURE); // 确保适当地退出或处理错误
        }
        ps->a = tmp;
        ps->capacity *= 2;
    }

    ps->a[ps->top] = x; // 压入元素
    ps->top++;
}

// 从栈中弹出元素
void STPop(ST* ps) {
    assert(ps);
    assert(!STEmpty(ps));

    ps->top--;
}

// 获取栈的大小
int STSize(const ST* ps) {
    assert(ps);

    return ps->top;
}

// 检查栈是否为空
bool STEmpty(const ST* ps) {
    assert(ps);

    return ps->top == 0;
}

// 获取栈顶元素
STDataType STTop(const ST* ps) {
    assert(ps);
    assert(!STEmpty(ps));

    return ps->a[ps->top - 1];
}


//使用两个栈实现队列的push、pop、peek、empty
void push(int x,int s1)
{
    STPush(&s1, x);
}

void pop(int s1, int s2)//从队列的开头移除并返回元素
{
    if (STEmpty(&s2))//如果栈2为空，那么就将栈1中的元素全部压入栈2中
    {
        while (!STEmpty(&s1))//直到栈1中的元素全部压入栈2中
        {
            STPush(&s2, STTop(&s1));
            STPop(&s1);
        }
    }
    STPop(&s2);//此时它的栈顶元素就是队列的队首元素
}

void peek(int s1, int s2)// 返回队列开头的元素
{
    if (STEmpty(&s2))//如果栈2为空，那么就将栈1中的元素全部压入栈2中
    {
        while (!STEmpty(&s1))//直到栈1中的元素全部压入栈2中
        {
            STPush(&s2, STTop(&s1));
            STPop(&s1);
        }
    }
    printf("%d\n", STTop(&s2));//此时它的栈顶元素就是队列的队首元素
}

bool empty(int s1, int s2)//如果队列为u空返回true，否则返回false
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
