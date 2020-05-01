#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include "myhead.h"

int main() {
    struct operationNode *o0, *o1, *o2, *v0, *v1, *v2, *v3;
    v0 = newOpNode(NULL, 0);
    v1 = newOpNode(NULL, 0);
    v2 = newOpNode(NULL, 0);
    v3 = newOpNode(NULL, 0);
    o0 = newOpNode(add1, 2);
    o1 = newOpNode(min1, 2);
    o2 = newOpNode(mul1, 2);

    (*o0).opNext[0] = v0; (*o0).opNext[1] = o1;
    (*o1).opNext[0] = o2; (*o1).opNext[1] = v3;
    (*o2).opNext[0] = v1; (*o2).opNext[1] = v2;

    struct gHead *head = newGH(o0, 3, 4);
    (*head).varList[0] = v0;
    (*head).varList[1] = v1;
    (*head).varList[2] = v2;
    (*head).varList[3] = v3;
    double value[VARLIST] = {3, 4, 5, 6, 0};
    double output = evalGraph(head, value);
    printf("output: %f", output);

    return 0;
}

