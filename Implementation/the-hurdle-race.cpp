/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/the-hurdle-race
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

// The only thing matters is the highest hurdle and Dan's initial jumping capability.

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int highest = -1;
    for (int i=0; i<n; i++)
    {
        int t;
        scanf("%d", &t);
        if (t > highest)
            highest = t;
    }
    if (k >= highest)
        printf("0\n");
    else
        printf("%d\n", highest - k);
}
