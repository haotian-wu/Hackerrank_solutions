/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/breaking-best-and-worst-records
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

// After reading n, we read a number first as both highest and lowest;
// then we read n-1 numbers to check if it breaks the records.

int main() {
    int n;
    scanf("%d",&n);
    int high, low, highcnt=0, lowcnt=0;
    scanf("%d", &high);
    low = high;
    for (int i=0;i<n-1;i++)
    {
        int p;
        scanf("%d",&p);
        if (p > high)
        {
            high = p;
            highcnt ++;
        } 
        if (p < low)
        {
            low = p;
            lowcnt ++;
        }
    }
    printf("%d %d\n", highcnt, lowcnt);
}
