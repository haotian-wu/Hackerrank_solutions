/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/pairs
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
// HASH

int main()
{
    int n,k,tmp;
    map<int,int> mp;
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        mp[tmp]++;
    }
    long long ans = 0;
    for (map<int,int> :: iterator j = mp.begin(); j != mp.end() ; j++)
    {
        if (mp.find((j->first) + (long long)k) == mp.end())
            continue;
        else
            ans += (j->second) * (long long)(mp[(j->first) + (long long)k]);
    }
    
    printf("%lld\n",ans);
}
