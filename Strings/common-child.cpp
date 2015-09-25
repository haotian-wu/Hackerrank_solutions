/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/common-child
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Longest Common String Problem.
int dp[5001][5001];

int main()
{
    char str1[5002],str2[5002];
    scanf("%s %s",str1,str2);
    int n=strlen(str1),m=strlen(str2);
    for (int i=0;i<n;i++)
        dp[i][0] = 0;
    for (int j=0;j<m;j++)
        dp[0][j] = 0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    printf("%d\n",dp[n][m]);
}
