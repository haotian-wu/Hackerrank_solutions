/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/kangaroo
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

// Let's name the two kangaroos A and B. B is ahead of A.
// In order to meet, A necessary condition is that VA > VB. Otherwise A can never catch up with B.
// However this is not sufficient. (XB - XA) must be devisible by (VA - VB), 
// otherwise A will jump over B, without landing on the same spot.

int main() {
    int xa, va, xb, vb;
    scanf("%d %d %d %d", &xa, &va, &xb, &vb);
    printf("%s\n", (va > vb && (xb - xa) % (va - vb) == 0)?"YES":"NO");
    return 0;
}
