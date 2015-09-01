/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/primsmstsub
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

// Simple Algorithm.
// When there are multiple edges between a given pair, we just use the smallest weight one.
// The starting point doesn't matter.
int adj[3001][3001];
int main()
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
    scanf("%*d"); //starting point doesn't matter
    int dis[3001],visited[3001];
    memset(dis,-1,sizeof(dis)); // dis = -1: Unvisited. 
    memset(visited,0,sizeof(visited));
    dis[1] = 0; // We pick 1 as starting point
    visited[1] = 1;
    int cur = 1, sum = 0;
    while (1) // N^2 approach. Can be faster if you use heap 
    {
        for (int i=1;i<=n;i++)
        {
            if (visited[i] == 0)
            {
                if (adj[cur][i] > -1 && (dis[i] == -1 || dis[i] > adj[cur][i]))
                    dis[i] = adj[cur][i];
            }
        }
        int flag = 1, mini = 10000000, ind = -1;
        for (int i=1;i<=n;i++)
        {
            if (visited[i] == 0 && dis[i] != -1)
            {
                flag = 0;
                if (mini > dis[i])
                {
                    mini = dis[i];
                    ind = i;
                }
            }
        }
        if (flag)
            break;
        visited[ind] = 1;
        sum += mini;
        cur = ind;
    }
    printf("%d\n",sum);
}
