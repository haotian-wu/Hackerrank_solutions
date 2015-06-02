/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-gcd
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    while (a%b!=0)
    {
        int tmp = b;
        b = a%b;
        a = tmp;
    }
    return b;
}
int main() {
    // Why bother looking at a "subset"? We just look at the whole array.
    // In short, it is asking if the GCD of the array is 1.
    // We use Euclid's algorithm for GCD calculation.
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n;
        scanf("%d",&n);
        int arr[100];
        for (int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int arrgcd=arr[0];
        for (int i=1;i<n;i++)
            arrgcd = gcd(arrgcd,arr[i]);
        if (arrgcd==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
