/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/bfsshortreach
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

// We don't care the '6' distance. We just treat this as a unweighted graph, and we multiply 6 when output.
// Simple BFS.

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        vector<int> adj[1001];
        for (int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            adj[a].push_back(b); // Adjacent list
            adj[b].push_back(a);
        }
        int s;
        scanf("%d",&s); //starting point
        int dis[1001];
        memset(dis,-1,sizeof(dis));
        int q[1001],be=0,ed=1; // FIFO queue. We will use BFS here.
        q[0] = s;
        dis[s] = 0; // dis = -1: Unvisited. 
        while(be<ed)
        {
            for (int i=0;i<adj[q[be]].size();i++)
            {
                if (dis[adj[q[be]][i]] == -1)
                {
                    dis[adj[q[be]][i]] = dis[q[be]] + 1;
                    q[ed++] = adj[q[be]][i];
                }
            }
            be++;
        }
        for (int i=1;i<=n;i++)
            if (i == s)
                continue;
            else if (dis[i] == -1)
                printf("%d ",-1);
            else
                printf("%d ",dis[i]*6); // Times 6!
        printf("\n");
    }
}
