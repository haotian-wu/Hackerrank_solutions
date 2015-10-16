/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/two-arrays
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

// We can sort A ascendingly and B descendingly, and check if A[i]+b[i] >= k for all i's.
// Proof: (In the proof, A and B always means the array after permutation.)
// We know the order of A doesn't matter, because we can always permute B.
// So we may as well assume A is sorted ascendingly. 
// For any i < j, we have a_i < a_j. 
// If we also have b_i < b_j, and a_i + b_i >= k, a_j + b_j >= k both hold,
// Then we can safely swap b_i and b_j, because a_i + b_j > a_i + b_i >= k, and a_j + b_i > a_i + b_i >= k.
// In other words, sorting B in descending order can no worse than any other permutation.
int A[1000],B[1000];
int main() {
    int tt,n,k;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d %d",&n,&k);
        for (int i=0;i<n;i++)
            scanf("%d",&A[i]);
        for (int i=0;i<n;i++)
            scanf("%d",&B[i]);
        sort(A,A+n);
        sort(B,B+n,greater<int>());
        int flag = 1;
        for (int i=0;i<n;i++)
            if (A[i] + B[i] < k)
            {
                flag = 0;
                break;
            }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}

