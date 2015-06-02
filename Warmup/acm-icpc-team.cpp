/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/acm-icpc-team
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
    // Brute force! O(N^2*M).
    int n,m;
    scanf("%d %d",&n,&m);
    char k[500][501];
    for (int i=0;i<n;i++)
        scanf("%s",k[i]);
    int maxn = -1, maxcnt=0; //maxn: maximum number of topics; maxcnt: number of teams.
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
        {
            int cnt=0;
            for (int l=0;l<m;l++)
                if (k[i][l]=='1' || k[j][l]=='1')
                    cnt++;
            if (cnt>maxn)
            {
                maxn = cnt;
                maxcnt = 1;
            }
            else if (cnt==maxn)
                maxcnt++;
        }
    printf("%d\n%d\n",maxn,maxcnt);
    return 0;
}
