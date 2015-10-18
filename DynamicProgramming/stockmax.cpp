/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/stockmax
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

// There's a greedy approach. 
// Say the highest price occurs on day d. If there's a tie, we pick the largest d. Then from day 1 through day d-1, buy 1 share every day. Then sale all on day d.
// Then we remove day 1 to day d, and repeat this approach on remaining days, until we reach day n.
// Proof: the highest price occurs on day d. So we should sale everything we have on that day. 
// That is because if we buy on that day, we can never sale at a higher price so we lose money. If we have stock in hand and we don't sale on day d, we can never sale at a higher price. So we must sale all we have on day d.
// On day 1 to day d-1, the price is not greater than that on day d. We know we will sale everything on day d, so we can safely buy on every day.

int main() {
    int tt,n;
    int arr[50000];
    scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int cur = 0;
        long long sum=0;
        while (1)
        {
            int maxi = -1, ind = -1;
            for (int i=cur;i<n;i++)
            {
                if (arr[i] >= maxi)
                {
                    maxi = arr[i];
                    ind = i;
                }
            }
            if (ind == -1)
                break;
            for (int i=cur;i<ind;i++)
                if (arr[i] < maxi)
                    sum += maxi - arr[i];
            cur = ind+1;
        }
        printf("%lld\n",sum);
    }
    return 0;
}

