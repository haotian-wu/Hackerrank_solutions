/*******************************************************
* Copyright (C) 2015 Haotian Wu
*
* This file is the solution to the question:
* https://www.hackerrank.com/challenges/hexagonal-grid
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
// Dynamic Programming. We can use dp[i][j] = k to denote the case that ...
// first row has i cells, and second line has j cells, is feasible (k=1) or not (k=0).
// When we encounter a black cell, we ignore it. For example, if row2[j] is black, dp[i][j] = dp[i][j-1].
int dp[11][11];
char row1[12],row2[12];
int getdp(int i, int j)
{
    if (i == 0 && j == 0)
        return 1;
    if ((i == 0 && j < 0) || (j == 0 && i < 0))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i > 0 && row1[i] == '1')
        return getdp(i-1,j);
    if (j > 0 && row2[j] == '1')
        return getdp(i,j-1);
    if (i < j)
    {
        if (j > 1 && row2[j-1] == '0') 
            dp[i][j] = getdp(i, j-2);
        else
            dp[i][j] = 0;
    }
    else if (i == j || i == j+1)
    {
        dp[i][j] = getdp(i-1, j-1);
    }
    else
    {
        if (i > 1 && row1[i-1] == '0')
            dp[i][j] = getdp(i-2, j);
        else
            dp[i][j] = 0;
    }
    return dp[i][j];
}
int main() {
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n;
        memset(dp,-1,sizeof(dp));
        scanf("%d %s %s",&n,row1+1,row2+1);
        printf("%s\n", getdp(n, n)? "YES":"NO");
    }
}
