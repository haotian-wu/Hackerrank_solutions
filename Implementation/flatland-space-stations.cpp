/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/flatland-space-stations
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

// Find the maximum distance between two space stations, and the distance is the half of this value.
// The maximum distance can be found by sorting.
// Don't forget the first city and last city.

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[100000];
    for (int i=0; i<m; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+m);
    int maxd = 0;
    for (int i=0; i<m-1; i++)
        if (arr[i+1] - arr[i] > maxd)
            maxd = arr[i+1] - arr[i];
    maxd /= 2;
    // The first and last city
    if (arr[0] > maxd)
        maxd = arr[0];
    if (n-1 - arr[m-1] > maxd)
        maxd = n-1 - arr[m-1];
    printf("%d\n", maxd);
}
