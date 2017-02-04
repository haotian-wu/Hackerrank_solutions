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

// This is method 2. 
// Very similar to method 1, but we perform a binary search. 
// Or we can also put the numbers in a map; basically the same thing.
// However, these two methods are all based on the assumption that the array is sorted.
// If we need a fast algorithm which works on an array which is not sorted, see method 3.

bool binarysearch(int arr[], int begin, int end, int target)
{
    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            begin = mid + 1;
    }
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
        if (binarysearch(arr, i+1, n-1, arr[i]+d) && binarysearch(arr, i+1, n-1, arr[i] + 2*d))
            cnt++;
    printf("%d\n", cnt);
}
