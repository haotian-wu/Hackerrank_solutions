/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/find-median
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
#include <vector>
#include <algorithm>
using namespace std;
// Sort the numbers, then look at the number on index n/2.
int main()
{
    int n;
    int arr[1000001];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    printf("%d\n",arr[n/2]);
}
