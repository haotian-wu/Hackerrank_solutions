/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/cats-and-a-mouse
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

// Absolute value!

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int ca, cb, m;
        scanf("%d %d %d", &ca, &cb, &m);
        int da = abs(ca-m), db = abs(cb-m);
        if (da < db)
            printf("Cat A\n");
        else if (da > db)
            printf("Cat B\n");
        else
            printf("Mouse C\n");
    }
}
