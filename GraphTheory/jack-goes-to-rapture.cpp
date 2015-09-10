/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/jack-goes-to-rapture
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

// This problem is very interesting. The problem is not difficult, but it really costs me half hour to think of a solution.
// Clearly, the question is asking to find a path, such that the max weight edge in the path is minimum.
// We could binary search the answer, and check if we could reach the destination only using the edges less or equal to the value.

vector<pair <int,int> > adj[50001];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back(make_pair(b,c)); // Adjacent matrix
        adj[b].push_back(make_pair(a,c)); 
    }
    int be = 1, ed = 10000002;
    while (be <= ed)
    {
        int mid = (be + ed) / 2;
        // Check connectivity, using BFS
        int q[50001], visited[50001];
        int qbe = 0, qed = 1;
        q[0] = 1;
        memset(visited,0,sizeof(visited));
        visited[1] = 1;
        while (qbe < qed)
        {
            int len = adj[q[qbe]].size();
            for (int i=0; i<len; i++)
            {
                if (visited[adj[q[qbe]][i].first] == 0 && adj[q[qbe]][i].second <= mid)
                {
                    q[qed++] = adj[q[qbe]][i].first;
                    visited[adj[q[qbe]][i].first] = 1;
                }
            }
            qbe++;
        }
        if (visited[n] == 1)
            ed = mid-1;
        else
            be = mid+1;
    }
    if (be > 10000000)
        printf("NO PATH EXISTS\n");
    else
        printf("%d\n",be);
    
}
