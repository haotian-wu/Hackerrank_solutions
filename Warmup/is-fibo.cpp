/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/is-fibo
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map <long long,int> mp;
void init()
{
    mp[0]=1;
    long long a=0,b=1;
    while (1)
    {
        long long c = a+b;
        if (c>10000000000ll)
            break;
        mp[c]=1;
        a=b;
        b=c;
    }
}
int main() {
    // Fibonacci sequence grows EXPONENTIALLY. So there are only a few fibos.
    // We precompute all these fibos, and save them in the hash.
    // Use long long to avoid overflow.
    init();
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        long long x;
        scanf("%lld",&x);
        printf("%s\n",mp[x]?"IsFibo":"IsNotFibo");
    }
    return 0;
}
