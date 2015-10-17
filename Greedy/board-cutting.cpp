/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/board-cutting
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


// Greedy. Cut from the highest cost to lowest cost (no matter direction). 
// We can prove that for all cuts in the same direction, we cut highest cost first can be always better.
// For two cuts in different direction, we either spend a_i * k + b_j * (l+1) or a_i * (k+1) + b_j * l. 
// Compare these two values we find we should always cut higher cost one first.
struct cuts {
    int cost;
    int dir; //direction
    bool inline friend operator < (cuts a, cuts b)
    {
        return a.cost > b.cost;
    }
} c[2000000];
int main() {
    int n,m,tt;
    scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d %d",&n,&m);
        n--;
        m--;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&c[i].cost);
            c[i].dir = 0;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d",&c[i+n].cost);
            c[i+n].dir = 1;
        }
        sort(c,c+(n+m));
        int cnt[2]={1,1};
        long long sum = 0;
        for (int i=0;i<n+m;i++)
        {
            sum += cnt[1-c[i].dir] * (long long)c[i].cost;
            cnt[c[i].dir] ++;
        }
        printf("%lld\n",sum % 1000000007);
    }
    return 0;
}

