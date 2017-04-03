/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/migratory-birds
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

// There're several ways to do this. Using an array to count is the most obvious solution.
// We can either create an array of size 5, and use index 0, 1, 2, 3, 4 for 1, 2, 3, 4, 5 (type - 1 = index); 
// or we can create an array of size 6, ignore index 0, so we can use the type number as index directly.
// For this problem, using an array is enough. However, in another counting problem,
// what if the type number is too big (say something like 2017040302), or it's a string (say "AB0305")?
// In that case, map is the best solution. Google "C++ map" (or "Python dictionary") for detail. 

int main() {
    int n;
    scanf("%d",&n);
    int cnt[6] = {0};
    for (int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        cnt[t] ++;
    }
    int maxcnt = -1, maxidx = -1;
    for (int i=1; i<=5; i++)
        if (cnt[i] > maxcnt) // Change > to >= if you want the biggest id when a tie occurs
        {
            maxidx = i;
            maxcnt = cnt[i];
        }
    printf("%d\n", maxidx);
}
