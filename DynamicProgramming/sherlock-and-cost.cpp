/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-cost
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

// We notice picking a number in between doesn't make sense. 
// That is, for every A_i, it either equal to 1 or B_i.
// We use dp[i][j] = k to denote, the first i elements will have largest cost = k, with A[i] = (j==0?1:B[i]).
// Here j is a state variable. We use j=0 denote A[i] = 1, and j=1 denote A[i] = B[i].
int main() {
    int tt,n;
    int num[100000];
    int dp[100000][2];
    scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&num[i]);
        dp[0][0] = 0;
        dp[0][1] = 0;
        for (int i=1;i<n;i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + (num[i-1]-1));
            dp[i][1] = max(dp[i-1][0] + num[i] - 1, dp[i-1][1] + abs(num[i] - num[i-1]));
        }
        printf("%d\n",max(dp[n-1][0], dp[n-1][1]));
    }
    return 0;
}
