/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/play-game
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

// We use an array to keep track of the maximum score j one can get when brick i is on the top. (dp[i] = j)
// When there're less than 3 bricks, one just take them all.
long long dp[100010];
int choice[100010]; // How many bricks should I pick
long long brick[100000];
int main() {
    int tt,n;
    scanf("%d",&tt);
    while (tt--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%lld",&brick[i]);
        dp[n-1] = brick[n-1];
        dp[n-2] = brick[n-1] + brick[n-2];
        dp[n-3] = brick[n-1] + brick[n-2] + brick[n-3];
        choice[n-1] = 1;
        choice[n-2] = 2;
        choice[n-3] = 3;
        for (int i=n-4;i>=0;i--)
        {
            long long sumj[] = {0, brick[i], brick[i]+brick[i+1], brick[i]+brick[i+1]+brick[i+2]};
            //Which should I choose?
            long long maximum = -1;
            int ind = 0;
            for (int j=1;j<=3;j++)
            {
                if (sumj[j] + dp[i+j+choice[i+j]] > maximum)
                {
                    maximum = sumj[j] + dp[i+j+choice[i+j]];
                    ind = j;
                }
            }
            dp[i] = maximum;
            choice[i] = ind;
        }
        printf("%lld\n",dp[0]);
    }
    return 0;
}
