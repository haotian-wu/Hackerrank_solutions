/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-array
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// We can traverse all possible i's, then calculate the sum of numbers to it's left & right.
// However this a an O(N^2) approach. We can do better when computing the sum.
// There are several ways of doing this.

int main() {
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n;
        scanf("%d",&n);
        int arr[100000];
        for (int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int lsum=0,rsum=0;
        for (int i=1;i<n;i++)
            rsum+=arr[i];
        int flag = (lsum == rsum); // In case (n==1)
        for (int i=1;i<n-1;i++)
        {
            lsum += arr[i-1];
            rsum -= arr[i];
            if (lsum == rsum)
            {
                flag = 1;
                break;
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}
