/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/grid-walking
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

// First we precompute C(n,k), i.e. the combinatory number of n choose k.
// We notice every dimension is independent from each other. 
// So we can solve each dimension separately, then merge them together.
// We compute the number of ways l when we are in dimension i, position j and move k steps. 
// We represent it as dim1[i][j][k] = l. dim1[i][j][k] = dim1[i][j-1][k-1] + dim1[i][j+1][k-1]. Of course you should deal with the case j-1<=0 or j+1 > d[i].
// Then we compute the number of ways if we only use the first k dimensions (dim 1 to k, inclusive) and make i moves.
// w[k][i] = sum_{j=0 to i, inclusive}(C[i][j] * w[k-1][j] * dim1[k][x[k]][i-j])
// w[1][i] = dim1[1][x[1]][i]
// That means we can use first k-1 dimensions and make j moves, and make i-j moves in the k'th dimension. 
// There're i moves and we can pick any j for the moves in first k-1 dimensions. That's C[i][j].
int n,m;
int C[301][301];
int dim1[11][101][301];
int w[11][301];
int d[101];
int x[101];
const int MOD = 1000000007;
void init()
{
    for (int i=1;i<=300;i++)
        for (int j=0;j<=i;j++)
            if (j==0 || j==i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
}
int main() {
    int tt;
    scanf("%d",&tt);
    init();
    while (tt--)
    {
        scanf("%d %d",&n,&m);
        memset(dim1,0,sizeof(dim1));
        memset(w,0,sizeof(w));
        for (int i=1;i<=n;i++)
            scanf("%d",&x[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&d[i]);
        // Compute dim1
        for (int i=1;i<=n;i++)
            for (int j=1;j<=d[i];j++)
                dim1[i][j][0] = 1;
        for (int i=1;i<=n;i++)
            for (int k=1;k<=m;k++)
                for (int j=1;j<=d[i];j++)
                {
                    if (j==1)
                        dim1[i][j][k] = dim1[i][j+1][k-1];
                    else if (j==d[i])
                        dim1[i][j][k] = dim1[i][j-1][k-1];
                    else
                        dim1[i][j][k] = (dim1[i][j+1][k-1] + dim1[i][j-1][k-1]) % MOD;
                }
        // Compute w
        for (int i=1;i<=m;i++)
            w[1][i] = dim1[1][x[1]][i];
        for (int k=1;k<=n;k++)
            w[k][0] = 1;
        for (int k=2;k<=n;k++)
            for (int i=1;i<=m;i++)
            {
                long long sum = 0;
                for (int j=0;j<=i;j++)
                    sum = (sum + C[i][j] * (long long) w[k-1][j] % MOD * (long long) dim1[k][x[k]][i-j] % MOD) % MOD;
                w[k][i] = sum;
            }
        printf("%d\n",w[n][m]);
    }
    return 0;
}
