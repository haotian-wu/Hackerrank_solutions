/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/permutation-equation
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// We define a function called "indexof". If p(a) = b, then indexof(b) = a.
// Clearly indexof is an inverse function of p. Which means, indexof(p(a)) = a, p(indexof(a)) = a.
// Also, p(a) = b will result in a = indexof(b).
// For x, we are looking for y such that p(p(y)) = x. This means y = indexof(indexof(x)).

int indexof[51];

int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        int t;
        scanf("%d", &t);
        indexof[t] = i;
    }
    for (int i=1; i<=n; i++)
        printf("%d\n", indexof[indexof[i]]);
}
