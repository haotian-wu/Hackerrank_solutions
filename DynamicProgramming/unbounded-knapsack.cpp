/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/unbounded-knapsack
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

// This is a special case of knapsack, in the way that an item's value equal to its weight (also known as bin packing).
// If you have no idea what knapsack problem is, search kanpsack problem and dynamic programming in Wikipedia.
// We use dp[i][j] = k to denote the maximum value we can obtain is k if we only use first i items and j capacity of the knapsack.
// dp[i][j] = max (dp[i-1][j], dp[i][j-w[i]] + v[i]). 
// dp[i][j] = -inf when j<0. dp[i][j] = 0 when j=0 or i=0.
int dp[2001][2001];
int w[2001];
int main() {
    int tt,n,k;
    scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d %d",&n,&k);
        for (int i=1;i<=n;i++)
            scanf("%d",&w[i]);
        for (int i=0;i<=2000;i++)
            dp[0][i] = dp[i][0] = 0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=k;j++)
                if (j >= w[i])
                    dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]] + w[i]);
                else
                    dp[i][j] = dp[i-1][j];
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
