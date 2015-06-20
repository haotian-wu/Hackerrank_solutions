/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/chocolate-feast
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
    // Simulation!
    int tt,n,c,m;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d %d %d",&n,&c,&m);
        int cnt = 0;
        cnt += n/c;
        int w = n/c;
        while (w >= m)
        {
            cnt += w/m;
            w = w%m + w/m;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
