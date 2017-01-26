/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/between-two-sets
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

// Brute force solves this problem, but we can do better (we can solve a_i <= 10^9)
// First find the LCM of array A, the GCD of B, then we can simply check how many divisors are there in GCD_B/LCM_A.
// In case B%A != 0, output 0.
// How to count the number of divisors of a number? We can factorize a number into primes:
// X = p_1^r_1 * p_2^r_2 * ... * p_n^r_n
// Then the number of divisors is simply (r_1 + 1) * (r_2 + 1) * ... * (r_n + 1). (1 and X inclusive)
// However I'm too lazy to implement this :-) Just brute force here.

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[100], b[100];
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (int i=0; i<m; i++)
        scanf("%d", &b[i]);
    int cnt = 0;
    for (int k=1; k<=100; k++)
    {
        int flag = 1;
        for (int i=0; i<n; i++)
            if (k % a[i] != 0)
                flag = 0;
        for (int i=0; i<m; i++)
            if (b[i] % k != 0)
                flag = 0;
        if (flag == 1)
            cnt ++;
    }
    printf("%d\n", cnt);
    return 0;
}
