/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/quicksort2
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
// This is NOT a good way of writing quicksort. Please look at quicksort1.cpp for a good quicksort example.
// The question is so silly that we have to write in this way...
int n;
void quicksort(int arr[], int st, int ed)
{
    if (st >= ed)
        return;
    int pivot = arr[st];
    int arr2[n],top=st,mid;
    for (int i=st;i<=ed;i++)
        if (arr[i]<pivot)
            arr2[top++]=arr[i];
    mid = top;
    arr2[top++]=pivot;
    for (int i=st;i<=ed;i++)
        if (arr[i]>pivot)
            arr2[top++]=arr[i];
    for (int i=st;i<=ed;i++)
        arr[i]=arr2[i];
    quicksort(arr,st,mid-1); 
    quicksort(arr,mid+1,ed); 
    for (int i=st;i<=ed;i++) //Put the print here to print the whole process bottom-up.
        printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    scanf("%d",&n);
    int arr[1000];
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,n-1);
}
