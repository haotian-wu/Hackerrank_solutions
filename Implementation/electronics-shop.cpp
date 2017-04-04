/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/electronics-shop
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

// Iterate all possible total costs, and keep track of the maximal one.

int main() {
    int s, n, m;
    int keyboard[1000], usb[1000];
    scanf("%d %d %d", &s, &n, &m);
    for (int i=0; i<n; i++)
        scanf("%d", &keyboard[i]);
    for (int i=0; i<m; i++)
        scanf("%d", &usb[i]);
    int maxcost = -1;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (keyboard[i] + usb[j] <= s && keyboard[i] + usb[j] > maxcost)
                maxcost = keyboard[i] + usb[j];
    printf("%d\n", maxcost);
}
