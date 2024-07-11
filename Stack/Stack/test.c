#include "StackB.h"
#include <stdio.h>

int main()
{
    ST st;
    STInit(&st);
    STPush(&st, 1);
    STPush(&st, 2);
    STPush(&st, 3);
    STPush(&st, 4);
    STPush(&st, 5);

    while (!STEmpty(&st)) {
        printf("%d ", STTop(&st)); // 添加空格以便输出结果更清晰
        STPop(&st);
    }
    STDestroy(&st);
    return 0;
}
