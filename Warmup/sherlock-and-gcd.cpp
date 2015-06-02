/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-gcd
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Why bother looking at a "subset"? We just look at the whole array.
    // Brute force. Try all integers in the range [2,min(arr)].
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n;
        scanf("%d",&n);
        int arr[100],minarr=10000000;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if (arr[i]<minarr)
                minarr = arr[i];
        }
        int flag = 0;
        for (int i=2;i<=minarr;i++)
        {
            flag = 1;
            for (int j=0;j<n;j++)
                if (arr[j]%i!=0)
                {
                    flag=0;
                    break;
                }
            if (flag==1)
                break;
        }
        if (flag==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
