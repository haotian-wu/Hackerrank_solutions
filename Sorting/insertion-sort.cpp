/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/insertion-sort
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
// A number will move X times to the left where X is the number of numbers that is greater than it on its left.
// That is the inversion number of the array. We use the divide and conquer algorithm to compute.
int arr[100001];
long long divide(int be, int ed)
{
    if (ed <= be)
        return 0;
    else if (ed - be == 1 )
    {
        if (arr[be] > arr[ed])
        {
            swap(arr[be],arr[ed]);
            return 1;
        }
        else
            return 0;
    }
    else
    {
        int mid = (be+ed)/2;
        long long ret = 0;
        ret += divide(be,mid);
        ret += divide (mid+1,ed);
        int i=be,j=mid+1;
        int arrn[100001],nt=i;
        while (i <= mid && j <= ed)
        {
            if (arr[i] <= arr[j])
            {
                arrn[nt++] = arr[i];
                i++;
            }
            else if (arr[i] > arr[j])
            {
                arrn[nt++] = arr[j];
                ret += (mid+1-i);
                j++;
            }
        }

        if (i<=mid)
        {
            for (;i<=mid;i++)
                arrn[nt++] = arr[i];
        }
        else if (j<=ed)
        {
            for (;j<=ed;j++)
                arrn[nt++] = arr[j];
        }
        for (int k=be;k<=ed;k++)
            arr[k] = arrn[k];
        return ret;
    }
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        printf("%lld\n",divide(0,n-1));
    }
}
