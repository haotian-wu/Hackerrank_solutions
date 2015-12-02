/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/coin-on-the-table
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


// We use dp[s][i][j] = p to denote we have to make p changes if we want to reach (i,j) in no more than s steps.
// dp[k][x][y] is the answer we need where (x,y) is '*' cell resides.
// Initially, dp[0][0][0] = 0, dp[0][i][j] = INF for any other cell.
// We can update dp[s+1][i-1][j], dp[s+1][i][j-1], dp[s+1][i+1][j], dp[s+1][i][j+1] using dp[s][i][j].
// Say dp[s][i][j] = p, then we can also use p changes to its pointed cell in s+1 steps, and p+1 changes in other three directions.
// Each cell can be updated by four adjacent cells; we want to pick the minimum value among them.
// Also don't forget dp[s+1][i][j] should be no greater than dp[s][i][j] by definition. 

const int INF = 1000000;

int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    char mp[52][52];
    int x,y;
    for (int i=0;i<n;i++)
    {
        scanf("%s",mp[i]);
        for (int j=0;j<m;j++)
            if (mp[i][j] == '*')
            {
                x = i;
                y = j;
            }
    }
    int dp[1001][51][51];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            dp[0][i][j] = INF;
    dp[0][0][0] = 0;
    for (int s=1;s<=k;s++)
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                dp[s][i][j] = dp[s-1][i][j];
                if (i>0) dp[s][i][j] = min(dp[s][i][j], dp[s-1][i-1][j] + (mp[i-1][j] != 'D'));
                if (j>0) dp[s][i][j] = min(dp[s][i][j], dp[s-1][i][j-1] + (mp[i][j-1] != 'R'));
                if (i<n-1) dp[s][i][j] = min(dp[s][i][j], dp[s-1][i+1][j] + (mp[i+1][j] != 'U'));
                if (j<m-1) dp[s][i][j] = min(dp[s][i][j], dp[s-1][i][j+1] + (mp[i][j+1] != 'L'));
            }
    if (dp[k][x][y] != INF) 
        printf("%d\n",dp[k][x][y]);
    else
        printf("-1\n");
    return 0;
}
