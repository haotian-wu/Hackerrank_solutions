/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/picking-numbers
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

// Count how many occurrences a number has, and find the maximum of cnt[i] + cnt[i+1].

int main() {
    int n;
    int cnt[100] = {0};
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        int t;
        scanf("%d", &t);
        cnt[t]++;
    }
    int maxsum = 0;
    for (int i=1; i<99; i++)
        if (cnt[i] + cnt[i+1] > maxsum)
            maxsum = cnt[i] + cnt[i+1];
    printf("%d\n", maxsum);
}
