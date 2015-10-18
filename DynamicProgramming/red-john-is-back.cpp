/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/red-john-is-back
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

// We use dp[i] to denote the number of ways to arrange the bricks for n*4 wall.
// dp[i] = dp[i-1] + dp[i-4]. Because we can either use a 4*1 brick when we have already filled (n-1)*4 wall, or we use 4 1*4 bricks when we filled (n-4)*4 wall.
int primes[300000],primetop=0;
int numberofprimes[41],pointer = 1;
int isprime(int x)
{
    if (x == 1)
        return false;
    for (int i=0;i<primetop;i++)
        if (x % primes[i] == 0)
            return false;
    return true;
}
int main() {
    int tt,n;
    scanf("%d",&tt);
    int dp[41];
    dp[0] = 1;
    for (int i=1;i<=40;i++)
        dp[i] = (i>=4?dp[i-4]:0) + dp[i-1];
    // Then we calculate how many primes are there no greater than dp[i].
    for (int i=1;i<=dp[40];i++)
    {
        while (i > dp[pointer])
        {
            numberofprimes[pointer+1] = numberofprimes[pointer]; 
            pointer ++;
        }
        if (isprime(i))
        {
            primes[primetop++] = i;
            numberofprimes[pointer] ++;
        }
    }
    while (tt--)
    {
        scanf("%d",&n);
        printf("%d\n",numberofprimes[n]);
    }
    return 0;
}
