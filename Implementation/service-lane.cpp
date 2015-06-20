/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/service-lane
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int w[100000];
int main() {
    // Straight forward. Find the minimum in range [i,j]. 
    // Use segment tree if the input is larger.
    int n,t;
    scanf("%d %d",&n,&t);
    for (int i=0;i<n;i++)
        scanf("%d",&w[i]);
    for (int i=0;i<t;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int minw = 4;
        for (int j=a;j<=b;j++)
            if (w[j]<minw)
                minw = w[j];
        printf("%d\n",minw);
    }
    return 0;
}
