/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/jim-and-the-orders
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

// We first compute the finish time for everyone, then sort.
struct order {
    int ftime;
    int ind;
    bool inline friend operator < (order a, order b)
    {
        if (a.ftime != b.ftime )
            return a.ftime < b.ftime;
        return a.ind < b.ind;
    }
}o[10000];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        o[i].ftime = a+b;
        o[i].ind = i+1;
    }
    sort(o,o+n);
    for (int i=0;i<n;i++)
        printf("%d ",o[i].ind);
    return 0;
}

