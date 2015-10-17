/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/coin-change
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


// We use dp[i][j] = k to denote There are k ways to give charge with first i kinds of coins for j cents.
// dp[i][j] = dp[i-1][j] + dp[i][j-c_i]
long long dp[51][251]={0};
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int c[51];
    for (int i=1;i<=m;i++)
        scanf("%d",&c[i]);
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1; // With no coins, we have 1 way to make 0 cents (that is to give nothing).
    for (int i=1;i<=m;i++)
        for (int j=0;j<=n;j++)
        {
            if (j >= c[i])
                dp[i][j] = dp[i][j-c[i]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    printf("%lld\n",dp[m][n]);
    return 0;
}

