/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/closest-numbers
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
// Sort the numbers, then look at every two adjacent numbers. 
// Use sort algorithm in #include <algorithm>.
int main()
{
    int n;
    int arr[200000];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    vector <int> closest_idx;
    int min_close = arr[1]-arr[0]+1;
    for (int i=0;i<n-1;i++)
    {
        int dif = arr[i+1]-arr[i];
        if (dif < min_close)
        {
            closest_idx.clear();
            closest_idx.push_back(i);
            min_close = dif;
        }
        else if (dif == min_close)
            closest_idx.push_back(i);
    }
    for (int i=0;i<closest_idx.size();i++)
        printf("%d %d ",arr[closest_idx[i]],arr[closest_idx[i]+1]);
}
