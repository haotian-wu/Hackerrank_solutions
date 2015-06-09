/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/quicksort1
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
// Let's write a quick sort.
void quicksort(int arr[], int st, int ed)
{
    if (st >= ed)
        return;
    int pivot = arr[st];
    int i=st,j=ed;
    while (i<j)
    {
    	while (i<j && arr[j]>=pivot)
            j--;
        while (i<j && arr[i]<=pivot)
            i++;
        swap(arr[i],arr[j]);
    }
    swap(arr[st],arr[i]);
    //quicksort(arr,st,i-1); // We comment these two lines, so it will only partition once.
    //quicksort(arr,i+1,ed); 
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[1000];
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,n-1);
    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
