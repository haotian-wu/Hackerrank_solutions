/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/journey-to-the-moon
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

// This is a standard Find-Union Set problem.
int fa[100001];
int getfather(int x)
{
    if (x == fa[x])
        return x;
    fa[x] = getfather(fa[x]);
    return fa[x];
}
int main()
{
    int n,p;
    scanf("%d %d",&n,&p);
    for (int i=0;i<n;i++)
        fa[i] = i;
    for (int i=0;i<p;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if (getfather(a) != getfather(b)) // Merge two trees at the root!
            fa[getfather(a)] = getfather(b);
    }
    int count[100001]={0};
    vector<int> c;
    for (int i=0;i<n;i++)
        count[getfather(i)] ++;
    for (int i=0;i<n;i++)
        if (count[i] != 0)
            c.push_back(count[i]);
    int l = c.size();
    /* The following is my previous approach. It got TLE at extreme conditions.
    long long sum = 0;
    for (int i=0;i<l;i++)
        for (int j=i+1;j<l;j++)
            sum += c[i]*c[j];
    printf("%lld\n",sum);
    */
    // Here We need pairwise product sum. For example, if we have a, b, c, d, we want ab+ac+ad+bc+bd+cd
    // Naive approach is too slow. Here we can use ((a+b+c+d)^2 - (a^2+b^2+c^2+d^2)) / 2 to calculate. It's way faster.
    long long sumsquare=0, squaresum=0;
    for (int i=0;i<l;i++)
    {
        sumsquare += c[i];
        squaresum += c[i] * c[i];
    }
    sumsquare = sumsquare * sumsquare;
    long long ans = ( sumsquare - squaresum ) / 2;
    printf("%lld\n",ans);
    
}
