#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>



typedef int STDataType;

typedef struct Stack {
    STDataType* a;
    int top;
    int capacity;
} ST;

void STInit(ST* ps);
void STDestroy(ST* ps);
void STPush(ST* ps, STDataType x);
void STPop(ST* ps);
int STSize(const ST* ps);
bool STEmpty(const ST* ps);
STDataType STTop(const ST* ps);
