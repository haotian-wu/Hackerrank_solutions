/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/equal
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

// First, observe that give k candies to everyone but one is equivalent to taking away k candies from that poor one! 
// (You can have negative candies in this case)
// Next, we need to determine how many candies everyone has after the taking away. 
// To minimize the number of operations, it seems obvious that everyone should have k candies where k is the minimum number of candies among everyone.
// However, it's possible that having k-1 or k-2 candies each minimizes the number of operations!
// Why k-1 or k-2? Well, consider the case that there are n people in total, one has 1 candy while all others has 5. 
// If we want to reduce 5 to 1, we need 2 operations each. So it's (n-1)*2 operations.
// However, if we reduce 5 to 0, and also reduce 1 to 0, we only need n operations. And k-2 for the same reason.
int oper(int diff)
{
    if (diff == 0)
        return 0;
    if (diff <= 2 || diff == 5)
        return 1;
    if (diff <= 4)
        return 2;
    return oper(diff % 5) + diff / 5;
}
int main() {
    int tt,n;
    int candy[10000];
    scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d",&n);
        // operations variable keeps track of the minimum operations we need
        int operations = 100000000, minc = 100000000;
        for (int i=0;i<n;i++)
        {
            scanf("%lld",&candy[i]);
            if (candy[i] < minc)
                minc = candy[i];
        }
        for (int k = minc; k>=minc-2; k--)
        {
            int sum = 0;
            for (int i=0;i<n;i++)
                sum += oper(candy[i] - k);
            if (sum < operations)
                operations = sum;
        }
        printf("%d\n",operations);
    }
    return 0;
}
