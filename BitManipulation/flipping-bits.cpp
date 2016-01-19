/*******************************************************
 * Copyright (C) 2016 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/flipping-bits
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

// Operator ~
int main() {
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        unsigned int n;
        scanf("%u",&n);
        printf("%u\n",~n);
    }
    return 0;
}
