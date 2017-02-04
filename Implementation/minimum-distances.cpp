/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/minimum-distances
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
#define INF 1000000
using namespace std;

// We can use brute force algorithm since n is small. 
// If n is large (10^6), we can use a map to keep track of the previous index of a given number, 
// and update it from time to time.

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int mind = INF;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (arr[i] == arr[j])
            {
                if (mind > j-i)
                    mind = j-i;
                break;
            }
    if (mind == INF)
        mind = -1;
    printf("%d\n", mind);
}
