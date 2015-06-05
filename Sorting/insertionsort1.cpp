/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/insertionsort1
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main() {
    // Check if it is less than the smallest element in the sorted array.
    int n,arr[1000];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int tmp=arr[n-1];
    for (int i=n-2;i>=0;i--)
    {
        if (tmp >= arr[i])
        {
            for (int j=0;j<=i;j++)
                printf("%d ",arr[j]);
            printf("%d ",tmp);
            for (int j=i+1;j<n-1;j++)
                printf("%d ",arr[j]);
            printf("\n");
            break;
        }
        else
        {
            for (int j=0;j<=i;j++)
                printf("%d ",arr[j]);
            for (int j=i;j<n-1;j++)
                printf("%d ",arr[j]);
            printf("\n");
        }
    }
    if (tmp < arr[0])
    {
        printf("%d ",tmp);
        for (int j=0;j<n-1;j++)
            printf("%d ",arr[j]);
        printf("\n");
    }
    return 0;
}
