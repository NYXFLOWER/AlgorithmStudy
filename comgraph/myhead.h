//
// Created by nyx_f on 11/07/2018.
//

#ifndef CALCUL_GRAPH_MYHEAD_H
#define CALCUL_GRAPH_MYHEAD_H
#endif //CALCUL_GRAPH_MYHEAD_H

#define VARLIST 5
#define OPLIST 3

// function store
double add1(const double *a, int b);
double mul1(const double *a, int b);
double min1(const double *a, int b);

// graph
struct gHead {
    struct operationNode *varList[VARLIST];       // linked list, store variable
    struct operationNode *operationNode;
    int numOp;
    int numVl;
};

struct operationNode {
    double (*func)(const double *, int);
    struct operationNode *(opNext[OPLIST]);
    int numNext;
};

struct gHead* newGH(struct operationNode *opNode, int op, int vl);
struct operationNode* newOpNode(double (*function)(const double *, int), int next);
double searchVariable(struct gHead *head, struct operationNode *variable, double value[]);
double evalNode(struct operationNode *star, struct gHead *head, double value[]);
double evalGraph(struct gHead *head, double value[]);
