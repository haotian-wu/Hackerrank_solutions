/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-pairs
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
// You don't really want to count, do you?
// (10^5)^2 will exceed the time limit for sure.
// If there are k elements equal to a same number, it will yield k(k-1) pairs.
// Just watch out for overflow.
int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        map <int,int> mp;
        int n,x;
        scanf("%d",&n);
        while (n--)
        {
            scanf("%d",&x);
            mp[x]++;
        }
        long long sum=0;
        for (map<int,int> :: iterator j = mp.begin();j!=mp.end();j++)
            sum += (j->second - 1) * (long long)(j->second); // single occurence doesn't matter. 
        printf("%lld\n",sum);

    }
}
