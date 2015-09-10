/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-minimax
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The min value will only occur at p, q, or the mean of two adjacent numbers in the sorted array.

int main()
{
    int n;
    int arr[100];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int p,q;
    scanf("%d %d",&p,&q);
    sort(arr,arr+n);
    int mini=100000001,minm;
    int maxi = -1, maxm;
    for (int i=0;i<n;i++)
        if (abs(arr[i] - p) < mini)
        {
            mini = abs(arr[i] - p);
            minm = p;
        }
    if (maxi < mini)
    {
        maxi = mini;
        maxm = minm;
    }
    
    for (int j=0;j<n-1;j++)
    {
        mini = 1000000001;
        int d = (arr[j]+arr[j+1])/2;
        if (d > p && d < q)
        {
            for (int i=0;i<n;i++)
                if (abs(arr[i] - d) < mini)
                {
                    mini = abs(arr[i] - d);
                    minm = d;
                }
            if (maxi < mini)
            {
                maxi = mini;
                maxm = minm;
            }
        }
    }
    
    mini = 1000000001;
    for (int i=0;i<n;i++)
        if (abs(arr[i] - q) < mini)
        {
            mini = abs(arr[i] - q);
            minm = q;
        }
    if (maxi < mini)
    {
        maxi = mini;
        maxm = minm;
    }
    printf("%d\n",maxm);
}
