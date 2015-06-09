/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/quicksort3
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
// A new way of partitioning.
int n;
void quicksort(int arr[], int st, int ed)
{
    if (st >= ed)
        return;
    int pivot = arr[ed];
    int i=st,j=st;
    for (j=st;j<ed;j++)
    {
        if (arr[j]<pivot)
        {
            swap(arr[j],arr[i]);
            i++;
        }
    }
    swap(arr[ed],arr[i]);
    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    quicksort(arr,st,i-1);
    quicksort(arr,i+1,ed);
}
int main()
{
    scanf("%d",&n);
    int arr[5000];
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,n-1);
}
