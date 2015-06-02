/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/taum-and-bday
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Greedy. If converting a black gift from a white one is cheaper, we will only buy white gifts and convert. Vice versa.
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int b,w,x,y,z;
        scanf("%d %d %d %d %d",&b,&w,&x,&y,&z);
        long long ans=0;
        if (x+z<y)
            ans = b*(long long)x + w*(long long)(x+z); //Watch out int overflow
        else if (y+z<x)
            ans = b*(long long)(y+z) + w*(long long)y;
        else
            ans = b*(long long)x + w*(long long)y;
        printf("%lld\n",ans);
    }
    return 0;
}
