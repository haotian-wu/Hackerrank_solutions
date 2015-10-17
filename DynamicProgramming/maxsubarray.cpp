/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/maxsubarray
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


// This problem is so well-known and I'm not elaborating it here. 
// We deal with the case that all numbers are negative separately.
// In the non-conseguous case, simply add up all positive numbers.
int arr[100000];
int main() {
    int tt,n;
    scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d",&n);
        int allnegflag = 1, maxi = -100000;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if (arr[i] > 0)
                allnegflag = 0;
            if (arr[i] > maxi)
                maxi = arr[i];
        }
        if (allnegflag) // is all negative?
            printf("%d %d\n",maxi,maxi);
        else
        {
            int maxsum = 0, cursum = 0, allpossum = 0;
            for (int i=0;i<n;i++)
            {
                cursum += arr[i];
                if (cursum > maxsum)
                    maxsum = cursum;
                if (cursum < 0)
                    cursum = 0;
                if (arr[i] > 0)
                    allpossum += arr[i];
            }
            printf("%d %d\n",maxsum, allpossum);
        }
    }
    return 0;
}

