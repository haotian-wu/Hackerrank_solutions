/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/maximise-sum
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
// First we compute the sum from arr[0] to arr[i] for all i's.
// We can acquire a subarray sum by substracting sum[j] by sum[i] (j>i). In a special case, if we need the sum from arr[0] to arr[j], we just use sum[j].
// Now the question becomes: For each sum[j], find a sum[i] such that sum[i]>sum[j], i<j. 
// We use set to solve this. It inserts an element in O(lg(n)) time, and finds an element in O(lg(n)) time.
int main()
{
    int tt;
    scanf("%d",&tt);
    long long arr[100000];
    long long sum[100000];
    while (tt--)
    {
        long long n,m;
        scanf("%lld %lld",&n,&m);
        for (int i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        sum[0] = arr[0] % m;
        for (int i=1;i<n;i++)
            sum[i] = (sum[i-1] + arr[i]) % m;
        set <long long> s;
        s.insert(m);
        long long maxi = -1;
        for (int i=0;i<n;i++)
        {
            set<long long> :: iterator it = s.lower_bound(sum[i]+1);
            long long diff = (sum[i]+m-(*it))%m;
            if (diff > maxi)
                maxi = diff;
            s.insert(sum[i]);
        }
        printf("%lld\n",maxi);
    }
}
