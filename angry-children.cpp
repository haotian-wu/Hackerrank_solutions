/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/angry-children
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // First sort the array, then we should always pick consecutive numbers in the array.
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[100000];
    for (int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int unfair = 1000000001;
    for (int i=k-1;i<n;i++)
        if (arr[i]-arr[i-k+1]<unfair)
            unfair = arr[i]-arr[i-k+1];
    printf("%d\n",unfair);
    return 0;
}
