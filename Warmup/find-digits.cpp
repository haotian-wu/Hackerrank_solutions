/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/find-digits
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
    // JUST COUNT!
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n,cnt=0;
        scanf("%d",&n);
        int tmp = n;
        while (tmp>0)
        {
            int d = tmp%10;
            tmp/=10;
            if (d>0 && n%d==0)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
