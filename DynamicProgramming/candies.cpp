/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/candies
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


// How many candies should we give to a child? 
// If there are l children on its left forming a strict increasing sequence, 
// and r children on its right forming a string decreasing sequence,
// then we should give the child max(l,r) candies.

int main() {
    int n;
    int arr[100000];
    int l[100000],r[100000];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    l[0] = 1;
    for (int i=1;i<n;i++)
        if (arr[i]>arr[i-1])
            l[i] = l[i-1] + 1;
        else
            l[i] = 1;
    r[n-1] = 1;
    for (int i=n-2;i>=0;i--)
        if (arr[i]>arr[i+1])
            r[i] = r[i+1] + 1;
        else
            r[i] = 1;
    long long sum = 0;
    for (int i=0;i<n;i++)
        sum += max(l[i],r[i]);
    printf("%lld\n",sum);
    return 0;
}

