/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence
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

// We use dp[i][j] to denote the length of LCS of arra[1..i] and arrb[1..j].
// dp[i][j] = dp[i-1][j-1] + 1 if arra[i] == arrb[j], 
// dp[i][j] = max(dp[i-1][j], dp[i][j-1]) if arra[i] != arrb[j].
// And after we get the length, we trace back.

int dp[101][101];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int arra[101], arrb[101];
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++)
        scanf("%d",&arra[i]);
    for (int i=1;i<=m;i++)
        scanf("%d",&arrb[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (arra[i] == arrb[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    // If you just want the length of LCS, you are done here. The length is dp[n][m].
    vector <int> ret;
    int x=n, y=m;
    while (dp[x][y] > 0)
    {
        if (dp[x][y] == dp[x-1][y])
            x--;
        else if (dp[x][y] == dp[x][y-1])
            y--;
        else if (dp[x][y] == dp[x-1][y-1] + 1)
        {
            ret.push_back(arra[x]);
            x--;
            y--;
        }
    }
    for (int i=ret.size()-1;i>=0;i--)
        printf("%d ",ret[i]);
    return 0;
}
