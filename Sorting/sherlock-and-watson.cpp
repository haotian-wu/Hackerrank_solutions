/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-watson
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Why this is a "sort" problem?
// Instead of really rotate the array (Which is very expensive), we just rotate the index.
// After k rotations, array A becomes A', we have A'[i] = A[(i+n-k%n)%n].
// How did we get this? Well, We rotate A k times to the right to get A', so if we rotate A' k times to the left, we get A.
// That is A'[i] = A[i-k].
// But what's A[-1]? It should be A[n-1]. So it should be A'[i] = A[(i+n-k)%n].
// Considering the case k>n, we use k%n instead of k.
int main()
{
    int n,k,q;
    int arr[100000];
    scanf("%d %d %d",&n,&k,&q);
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    while (q--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",arr[(x+n-k%n)%n]);
    }
        
}
