/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/longest-increasing-subsequent
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

// There're so many tutorials on nlogn LIS, so I'm not elaborating it here.
int arr[1000001];
int dp[1000001];
int binsearch(int a[], int be, int ed, int val)
{
    if (ed < be)
        return be;
    while (be <= ed)
    {
        int mid = (be + ed) / 2;
        if (a[mid] < val && a[mid+1] > val)
            return mid+1;
        else if (a[mid] < val)
            be = mid + 1;
        else
            ed = mid - 1;
    }
    return be;
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int maxlen = 1;
    dp[maxlen] = arr[0];
    for (int i=1;i<n;i++)
    {
        if (arr[i] > dp[maxlen])
            dp[++maxlen] = arr[i];
        else
        {
            int ind = binsearch(dp, 1, maxlen-1, arr[i]);
            dp[ind] = arr[i];
        }
    }
    printf("%d\n",maxlen);
    return 0;
}
