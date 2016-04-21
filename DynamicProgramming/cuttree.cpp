/*******************************************************
 * Copyright (C) 2016 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/cuttree
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

// Here, root can be chosen randomly (or just choose node 1 as root).
// We use a vector v to denote the status of a node. 
// v[i] = j means at this node, there are j ways to cut this subtree (with root being this node), with i edges cut.
// Thus for any leaf node, we only have v[0] = 1 on this node.
// For any non-leaf node, it must have at least a child. If it has only one child, then v[i] = v_child[i] except v[1] = v_child[1]+1.
// Because we have one more way to get a subtree with one cut.
// What if we have two or more children? First we add 1 to v[1] of all children, for the same reason above.
// Then we should combine these vectors together. Let's say we have two children for simplexity. 
// We have v[i] = \sum_{j=0}^i vc1[j]*vc2[i-j]. 
// This is obvious, meaning if the first subtree was cut j edges, the second subtree must cut i-j edges, to make up a total of i cuts. 
// We traverse all possible j's and sum them together to get v[i]. Do this bottom-up until we reach the root.
// Now what? Notice the result consists of an empty tree and trees with root being every node in the original tree.
// If the subtree has the same root with the original tree, all v[0] .. v[k] are acceptable results. Add them to our final result.
// If the subtree's root is different from our original one, only v[0] .. v[k-1] are acceptable. 
// This is because we already cut one edge above this subtree's root. k-1 cuts left. 
// After we sum all these up, don't forget to add 1 because of the empty tree.

vector<int> adj[51]; //Adjacency list
int visited[51];
long long final_result = 0;
int n,k;

vector<long long> operator * (vector<long long> a, vector<long long> b)
{
    vector<long long> c;
    int m = a.size() + b.size()-2;
    for (int i=0;i<=m;i++)
    {
        long long s=0;
        for (int j=0;j<a.size();j++)
            if (i-j>=0 && i-j<b.size())
                s += a[j] * b[i-j];
        c.push_back(s);
    }
    return c;
}

vector<long long> work(int node, int flag)
{
    vector<long long> ret(1,1);
    for (int i=0;i<adj[node].size();i++)
    {
        if (visited[adj[node][i]]==0)
        {
            visited[adj[node][i]]=1;
            vector<long long> vc = work(adj[node][i], 1);
            if (vc.size() == 1)
                vc.push_back(1);
            else
                vc[1] ++;
            ret = ret * vc;
        }
    }
    for (int i=0; i<min((int)ret.size(),k+1-flag); i++)
        final_result += ret[i];
    return ret;
}

int main() {
    scanf("%d %d",&n,&k);
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(visited,0,sizeof(visited));
    visited[1] = 1;
    work(1,0);
    printf("%lld\n",final_result+1);
}
