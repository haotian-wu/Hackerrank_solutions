/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/jumping-on-the-clouds
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

// Greedy. Jump 2 steps whenever possible.

int main() {
    int n;
    int c[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &c[i]);
    int steps = 0, cur = 0;
    while (cur != n-1)
    {
        if (c[cur+2] == 0)
            cur += 2;
        else
            cur ++;
        steps ++;
    }
    printf("%d\n", steps);
}
