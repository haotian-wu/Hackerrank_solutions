/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/kruskalmstrsub
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

// Kruskal Algorithm. Find-Union Set used here.
// The starting node makes no sense. Ignore it.
struct edge {
    int a; //From
    int b; //To
    int w; //Weight
    bool inline friend operator < (edge x, edge y) // Compare function. Used in sort.
    {
        if (x.w < y.w)
            return true;
        return false;
    }
} e[4500000];
int fa[3001];
int getfa(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = getfa(fa[x]);
}
int main()
{
    int n,m,top=0;
    scanf("%d %d",&n,&m);
    
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        e[top].a = a;
        e[top].b = b;
        e[top].w = c;
        top++;
    }
    scanf("%*d"); //starting point doesn't make sense
    sort(e,e+m);
    
    for (int i=1;i<=n;i++)
        fa[i] = i;
    int cnt = n, cur = 0; // cnt: how many components are there, exit when cnt == 1; cur: iterator of array e
    int sum = 0;
    while (1)
    {
        if (cnt == 1)
            break;
        if (getfa(e[cur].a) != getfa(e[cur].b))
        {
            fa[getfa(e[cur].b)] = getfa(e[cur].a);
            sum += e[cur].w;
            cnt--;
        }
        cur++;
    }

    printf("%d\n",sum);
}
