/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/day-of-the-programmer
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The length of each month for Julian is the same with Gregorian.

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1918)
        printf("26.09.1918\n");
    else if (n%400 == 0 || (n%4 == 0 && (n < 1918 || n%100 != 0)))
        printf("12.09.%d\n", n);
    else
        printf("13.09.%d\n", n);
}
