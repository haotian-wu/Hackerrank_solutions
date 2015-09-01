/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/even-tree
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

// We will use a greedy approach. Search bottom up. Whenever we see a subtree with even number of vertices, we decompose it.
// It doesn't matter which node is the root. We just use node 1 as root.
int ans = 0;
int n,m;
vector <int> adj[101];
int work(int node, int parent) // This function counts how many nodes are there in its subtree
{
    int sum = 1; // Count the node itself
    for (int i=0;i<adj[node].size();i++)
    {
        if (adj[node][i]==parent)
            continue;
        int sub = work(adj[node][i], node);
        if (sub % 2 == 0)
        {
            ans++;
            sub = 0; //Not necessary
        }
        sum += sub;
    }
    return sum;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b); // Adjacent list
        adj[b].push_back(a);
    }
    work(1,-1); // Start from node 1. Its parent is -1 (doesn't exist).
    printf("%d\n",ans);
}
