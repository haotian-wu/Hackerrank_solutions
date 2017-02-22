/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/absolute-permutation
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

// This problem is not as hard as it seems.
// We already know the number on position i has to be either i-k or i+k.
// If k=0, then the permutation array is the same with index array, i.e. [1, 2, 3, ...]
// Otherwise, the number on position 1 has to be 1+k, 
// since 1-k (less than or equal to 0) is not a valid number in the permutation.
// What about the number on position 1+k? You got it, it has to be 1.
// This is because, there has to be a 1 in the permutation. If we let (1+2k) be on position 1+k, then number 1 can be placed nowhere. 
// Then think about position 2... Using this method, we can fill in the first 2k numbers in the first 2k positions.
// Then think about position 1+2k... Only 1+k or 1+3k fit, however 1+k is already used. 
// Repeat this will get numbers 1+2k to 4k filled. Then repeat this until all are filled. 
// Also, we just learned that if n is not a multiple of 2k (k>0), the answer should be impossible.

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        if (k==0)
        {
            for (int i=1; i<=n; i++)
                printf("%d ", i);
            printf("\n");
            continue;
        }
        if (n % (2*k) != 0)
        {
            printf("-1\n");
            continue;
        }
        for (int i=0; i<(n/(2*k)); i++)
        {
            for (int j=1; j<=k; j++)
                printf("%d ", i*(2*k)+k+j);
            for (int j=1; j<=k; j++)
                printf("%d ", i*(2*k)+j);
        }
        printf("\n");
    }
}
