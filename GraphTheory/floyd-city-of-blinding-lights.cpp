/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights
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

// Floyd Algorithm. Directed edges are used in this problem.

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int adj[401][401];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = 10000000;
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a][b] = c; // Adjacent matrix, directed edges
    }
    int dis[401][401];
    int newdis[401][401];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dis[i][j] = adj[i][j];
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    newdis[i][j] = dis[i][k] + dis[k][j];
                else
                    newdis[i][j] = dis[i][j];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                dis[i][j] = newdis[i][j];
    }
    
    int q;
    scanf("%d",&q);
    while (q--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if (dis[a][b] < 10000000)
            printf("%d\n",dis[a][b]);
        else
            printf("-1\n");
    }
    
}
