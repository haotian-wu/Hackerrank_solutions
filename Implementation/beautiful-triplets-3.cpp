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

// This is method 3. We consider the case that the array is not sorted.
// To check whether an element exists, we would consider using a map.
// However, since the elements are not sorted, a single map is not enough. 
// For example, arr = [10, 30, 20], d = 10, only knowing 20 and 30 exist is not enough. We need to know the order.
// Therefore, we traverse the middle element j, and use two maps: 
// one map keeping the elements before it, one map keeping the elements after it. We update the maps while we move j.

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    int arr[10000];
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int cnt = 0;
    map<int, int> before, after;
    for (int i=1; i<n; i++)
        after[arr[i]] = 1;
    for (int j=0; j<n-1; j++)
    {
        if (before.find(arr[j]-d) != before.end() && after.find(arr[j]+d) != after.end())
            cnt++;
        before[arr[j]] = 1;
        after.erase(after.find(arr[j+1]));
    }
    printf("%d\n", cnt);
}
