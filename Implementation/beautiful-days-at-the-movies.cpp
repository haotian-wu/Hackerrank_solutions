/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/beautiful-days-at-the-movies
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

// Implement reverse and count!

int reverse(int n)
{
    int r = 0;
    while (n > 0)
    {
        r = 10 * r + n % 10;
        n /= 10;
    }
    return r;
}

int main() {
    int i, j, k;
    cin >> i >> j >> k;
    int cnt = 0;
    for (int l = i; l <= j; l++)
        if (abs(l - reverse(l)) % k == 0)
            cnt ++;
    cout << cnt << endl;
}
