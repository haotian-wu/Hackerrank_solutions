/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/the-birthday-bar
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

// Firstly, you can simply iterate all possible m consecutive squares, and check its sum. Time complexity O(nm).
// Instead of calculating the sum for every segment, we can get the sum by adding the next number and subtracting previous number.
// This gives us a time complexity of O(n). See code for detail.

int main() {
    int n, arr[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int sum=0, m, d, cnt=0;
    scanf("%d %d", &d, &m);
    for (int i=0; i<m; i++)
        sum += arr[i];
    if (sum == d)
        cnt++;
    for (int i=m; i<n; i++)
    {
        sum += arr[i];
        sum -= arr[i-m];
        if (sum == d)
            cnt++;
    }
    printf("%d\n", cnt);
}
