/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/grid-challenge
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

// We sort all row arrays and see if all columns form a sorted array.

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n;
        scanf("%d",&n);
        char str[101][101];
        for (int i=0;i<n;i++)
            scanf("%s",str[i]);
        for (int i=0;i<n;i++)
            sort(str[i],str[i]+n);
        int flag = 1;
        for (int i=0;i<n;i++)
            for (int j=0;j<n-1;j++)
                if (str[j][i]>str[j+1][i])
                    flag = 0;
        printf("%s\n",flag?"YES":"NO");
    }
}
