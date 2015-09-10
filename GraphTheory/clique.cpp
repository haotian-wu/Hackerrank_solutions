/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/clique
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

// See https://en.wikipedia.org/wiki/Tur%C3%A1n%27s_theorem
// I don't like this problem.

int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int be = 2, ed = 10000;
        while (be <= ed)
        {
            int r = (be + ed)/2;
            int arr[r];
            for (int j=0;j<r;j++)
                arr[j] = n/r;
            for (int j=0;j<n-n/r*r;j++)
                arr[j]++;
            int sqs = 0, ssq = 0; //square sum and sum square. Used in computing a*b + a*c + b*c + ...
            for (int j=0;j<r;j++)
            {
                sqs += arr[j] * arr[j];
                ssq += arr[j];
            }
            ssq = ssq * ssq;
            int ans = (ssq - sqs) / 2;
            if (m <= ans)
                ed = r-1;
            else 
                be = r+1;
        }
        printf("%d\n",be);
    }
}
