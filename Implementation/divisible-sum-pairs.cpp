/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/divisible-sum-pairs
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

// Just implement!

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[100];
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    int cnt = 0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
        {
            if ((a[i] + a[j]) % k == 0)
                cnt ++;
        }
    printf("%d\n", cnt);
    return 0;
}
