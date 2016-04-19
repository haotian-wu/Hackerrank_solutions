/*******************************************************
 * Copyright (C) 2016 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/larrys-array
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

// A trivial answer can be implementing the rotations. 
// First rotate the smallest number to the first, then secend smallest to the second....
// Until we have two numbers left. If they are in the correct order, then print yes. Otherwise print no.
// I will introduce a better approach: Inversion. See https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics) for definition.
// Let's consider three numbers A, B, C (A<B<C). In ABC->BCA->CAB rotation group, the inversion numbers are: 0, 2, 2.
// In ACB->CBA->BAC rotation group, the inversion numbers are: 1, 3, 1.
// Which means, rotation will never change the even/odd nature of the inversion number of the entire array.
// Also, we notice our final objective, sorted array, has an inversion number of 0.
// So we can first compute the inversion number of the array, and if it's even, we can safely print yes; if it's odd, print no.
// Lastly, there is an O(nlgn) algorithm for inversion number computation. We use O(n^2) since it's fast enough for this problem.

int main() {
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        int arr[1000];
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int inv = 0;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                if (arr[i] > arr[j])
                    inv ++;
        if (inv%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
