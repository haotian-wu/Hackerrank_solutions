/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/largest-permutation
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


// Greedy. Always put the largest at first place, then second largest.
// Since the data is huge we need to keep track of where the number is, instead of searching it.
int arr[100001];
int loc[100001]; // loc[i] = j means number i is at location j.
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    if (k >= n) // k > n doesn't make sense. We need at most n-1 moves to sort the array descendingly, which is the largest.
        k = n-1;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        loc[arr[i]] = i;
    }
    for (int i=1;i<=n,k>0;i++)
    {
        if (arr[i] != n+1-i) // Not in place
        {
            int tmp = loc[n+1-i];
            swap(arr[i],arr[loc[n+1-i]]);
            loc[arr[tmp]] = tmp;
            loc[arr[i]] = i; // Actually not used any more
            k--;
        }
    }
    for (int i=1;i<=n;i++)
        printf("%d ",arr[i]);
    return 0;
}

