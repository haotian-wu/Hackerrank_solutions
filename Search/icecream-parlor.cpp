/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/icecream-parlor
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// Hash!
// Since there's only one solution, we put the last index in the hash.

int main() {
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        int arr[10001];
        int ha[10001];
        memset(ha,0,sizeof(ha));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
            ha[arr[i]] = i;
        }
        for (int i=1;i<=n;i++)
            if (m >= arr[i] && ha[m-arr[i]] != 0 && ha[m-arr[i]] != i)
            {
                printf("%d %d\n",i,ha[m-arr[i]]);
                break;
            }
    }
    return 0;
}
