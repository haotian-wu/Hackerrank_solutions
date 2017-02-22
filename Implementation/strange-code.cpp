/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/strange-code
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

// Well I think the code itself is self-explanatory...

int main() {
    long long t;
    scanf("%lld", &t);
    long long cur = 3;
    while (t > cur)
    {
        t -= cur;
        cur *= 2;
    }
    printf("%lld\n", cur+1-t);
}
