//
// Created by nyx_f on 11/07/2018.
//
#include <stdio.h>
#include <malloc.h>
#include "myhead.h"

struct gHead* newGH(struct operationNode *opNode, int op, int vl) {
    struct gHead *head = (struct gHead *)malloc(sizeof(struct gHead));
    (*head).operationNode = opNode;
    (*head).numVl = vl;
    (*head).numOp = op;
    for (int i = 0; i < VARLIST; (*head).varList[i++] = NULL) { }

    return head;
}

struct operationNode* newOpNode(double (*function)(const double *, int), int next) {
    struct operationNode* oppNode = (struct operationNode *)malloc(sizeof(struct operationNode));
    (*oppNode).numNext = next;
    (*oppNode).func = function;
    for (int i = 0; i < OPLIST; (*oppNode).opNext[i++] = NULL) {}

    return oppNode;
}

double searchVariable(struct gHead *head, struct operationNode *variable, double value[]) {
    for (int i = 0; i < (*head).numVl; i+=1) {
        if((*head).varList[i] == variable) {
            return value[i];
        }
    }
    printf("something goes wrong");
    return 0;
}

double evalNode(struct operationNode *star, struct gHead *head, double value[]) {
    if(!star->numNext) {
        return searchVariable(head, star, value);
    }
    double temp[VARLIST];
    for (int i = 0; i < star->numNext; i+=1) {
        temp[i] = evalNode(star->opNext[i], head, value);
        printf("%f\n",temp[i]);
    }
    return star->func(temp, star->numNext);
}

double evalGraph(struct gHead *head, double value[]) {
    if ((*head).numOp > 0) {
        return evalNode((*head).operationNode, head, value);
    } else {
        printf("no graph");
    }
}