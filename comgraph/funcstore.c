//
// Created by nyx_f on 11/07/2018.
//

double add1(const double *a, int b) {
    return *a + *(a+1);
};

double mul1(const double *a, int b) {
    return (*a) * (*(a+1));
};

double min1(const double *a, int b) {
    return *a - *(a+1);
};