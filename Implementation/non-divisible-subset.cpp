/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/non-divisible-subset
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

// It doesn't matter what a_i is; it's (a_i % k) that matters.
// Suppose (a_i + a_j) is divisible by k, then we will have "a_i % k + a_j % k = 0 or k" for sure.
// Therefore, if we want a_i to be in S', whose remainder is r_i, we must avoid adding a number whose remainder is k-r_i.
// At the mean time, we want to put all numbers whose remainders are r_i into S', to maximize the number of elements in S'.
// So the algorithm is basically traverse all possible r_i and k-r_i pairs. 
// Check whether there are more numbers whose remainder are r_i or k-r_i, and put these numbers into S'.
// For example, k = 3, and there are 9 numbers have a remainder of 1, 10 numbers have a remainder of 2.
// We should put the 10 numbers with remainder of 2 into S'.
// What if the remainder is 0? What if the remainder is k/2 when k is even?
// Well, it's clear that we can only put one such number into S' in either case.
// For example, k = 4, and S = [8 6 12 14]. We can have [8 6] in S', but no more.

int main() {
    int n, k;
    int r_cnt[100] = {0};
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        r_cnt[ tmp % k ] ++;
    }
    int s_cnt=0;
    for (int i=0; i<=k/2; i++)
    {
        if (i == 0 || (i == k/2 && k % 2 == 0) )
            s_cnt += (r_cnt[i] > 0); // If there is at least a number with such remainder, add one
        else
        {
            if (r_cnt[i] > r_cnt[k-i])
                s_cnt += r_cnt[i];
            else
                s_cnt += r_cnt[k-i];
        }
    }
    printf("%d\n", s_cnt);
}
