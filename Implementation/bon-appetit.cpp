/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/bon-appetit
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
    int sum=0, tmp;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &tmp);
        if (i != k)
            sum += tmp;
    }
    int c;
    scanf("%d", &c);
    int refund = c - sum / 2;
    if (refund == 0)
        printf("Bon Appetit\n");
    else
        printf("%d\n", refund);
    return 0;
}
