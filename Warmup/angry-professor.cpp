/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/angry-professor
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
    // Very straight forward... Just note it is asking if the class is to be *CANCELLED*.
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        while (n--)
        {
            int t;
            scanf("%d",&t);
            if (t<=0)
                k--;
        }
        if (k<=0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
