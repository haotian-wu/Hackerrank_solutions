/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/cut-the-tree
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
// Obviously, we cannot compute the sum of both subtrees on the fly while we traverse all the edges. 
// This problem can be solved using a search algorithm. We use recursive search here.
// The main observation is that, we can keep track of the sum of one subtree, and the sum of all nodes, so the sum of the other subtree can be computed.

int n;
int w[100001];
vector<int> adj[100001];
int visited[100001];
int ans = 200000000;
int sum = 0;
int search(int root)
{
    visited[root]=1;
    int len = adj[root].size();
    int sumofthistree = w[root];
    for (int i=0;i<len;i++)
    {
        if (visited[adj[root][i]] ==0)
        {
            int sumofsubtree = search(adj[root][i]);
            sumofthistree += sumofsubtree;
            int diff = abs(sum - sumofsubtree * 2);
            if (diff < ans)
                ans = diff;
        }
    }
    return sumofthistree;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        sum += w[i];
    }
    for (int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a); // Adjacency list
    }
    
    memset(visited,0,sizeof(visited));
    // We choose node 1 to be the root
    search(1);
    printf("%d\n",ans);
}
