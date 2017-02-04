/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/beautiful-triplets
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

// This is method 1. 
// Considering the array is given in ascending order, and d <= 20, we can do a very straightforward linear search.
// We can traverse all possible i's, and perform linear search on the array for j and k. 
// It's guaranteed for each i, this can be done within 40 searches.
// If d is large, this algorithm will be slow. Binary search will solve this issue; see method 2 for detail.

bool linearsearch(int arr[], int len, int startidx, int target)
{
    for (int i=startidx; i<len; i++)
        if (arr[i] == target)
            return true;
        else if (arr[i] > target)
            return false;
    return false;
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    int arr[10000];
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int cnt = 0;
    for (int i=0; i<n; i++)
        if (linearsearch(arr, n, i+1, arr[i]+d) && linearsearch(arr, n, i+1, arr[i] + 2*d))
            cnt++;
    printf("%d\n", cnt);
}
