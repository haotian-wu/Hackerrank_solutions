/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/dijkstrashortreach
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

// Dijkstra Algorithm.
// When there are multiple edges between a given pair, we just use the smallest weight one.

int adj[3001][3001];
int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        memset(adj,-1,sizeof(adj));
        for (int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if (adj[a][b] == -1 || adj[a][b] > c) // In case of multiple edges
                adj[a][b] = adj[b][a] = c; // Adjacent matrix
        }
        int s;
        scanf("%d",&s);
        int dis[3001],visited[3001];
        memset(visited,0,sizeof(visited));
        for (int i=1;i<=3000;i++)
            dis[i] = 10000000;
        visited[s] = 1;
        dis[s] = 0;
        int cur = s;
        for (int k=0;k<n-1;k++) // Loop n-1 times to get the exact distance of the other n-1 nodes
        {
            for (int i=1;i<=n;i++)
            {
                if (visited[i] == 0)
                {
                    if (adj[cur][i] != -1 && dis[i] > dis[cur] + adj[cur][i])
                        dis[i] = dis[cur] + adj[cur][i];
                }
            }
            int mini = 10000000, ind = -1;
            for (int i=1;i<=n;i++)
            {
                if (visited[i] == 0 && dis[i] < mini)
                {
                    mini = dis[i];
                    ind = i;
                }
            }
            if (ind != -1)
            {
                visited[ind] = 1;
                cur = ind;
            }
            else
                break;
        }
        for (int i=1;i<=n;i++)
            if (i != s)
                if (dis[i] < 10000000)
                    printf("%d ",dis[i]);
                else
                    printf("-1 ");
        printf("\n");
    }
}
