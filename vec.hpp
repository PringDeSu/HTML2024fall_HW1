#pragma once

#include <array>
using namespace std;

const int DIM = 47205;
typedef array<long double, DIM + 1> vec;
// typedef vector<long double> vec;

vec &operator+=(vec &a, vec b) {
    for (int i = 0; i <= DIM; i++) a[i] += b[i];
    return a;
}

vec operator*(vec &a, long double b) {
    // vec ans(DIM + 1);
    vec ans;
    for (int i = 0; i <= DIM; i++) ans[i] = a[i] * b;
    return ans;
}

long double operator*(vec &a, vec &b) {
    long double ans = 0.0;
    for (int i = 0; i <= DIM; i++) ans += a[i] * b[i];
    return ans;
}

struct TRAIN {
    vec x;
    int y;
    TRAIN() : x(), y() {}
};
