/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/quicksort4
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
// We did the running time of insertion sort in "runningtime.cpp".
// Now we just copy the quicksort from "quicksort3.cpp", and measure the running time.
int n,sum_ins=0,sum_qs=0;
void insertionSort(int ar_size, int *  ar) {
    if (ar_size>=2)
        insertionSort(ar_size-1, ar);
    else
        return;
    int tmp = ar[ar_size-1];
    for (int i=ar_size-2;i>=0;i--)
    {
        if (tmp >= ar[i])
        {
            for (int j=ar_size-2;j>i;j--)
            {
                ar[j+1] = ar[j];
                sum_ins++;
            }
            ar[i+1] = tmp;
            break;
        }
    }
    if (tmp < ar[0])
    {
        for (int j=ar_size-2;j>=0;j--)
        {
            ar[j+1] = ar[j];
            sum_ins++;
        }
        ar[0] = tmp;
    }
    return;
}
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
            sum_qs++;
            i++;
        }
    }
    swap(arr[ed],arr[i]);
    sum_qs++;
    quicksort(arr,st,i-1);
    quicksort(arr,i+1,ed);
}
int main()
{
    scanf("%d",&n);
    int arr1[5000],arr2[5000];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
        arr2[i]=arr1[i];
    }
    quicksort(arr1,0,n-1);
    insertionSort(n,arr2);
    printf("%d\n",sum_ins-sum_qs);
}
