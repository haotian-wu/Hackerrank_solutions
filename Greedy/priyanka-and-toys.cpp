/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/priyanka-and-toys
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

// She should sort the weight of all toys, and buy from the lightest. 
// Proof: Say the lightest toy has weight w. If all other toys has weight heavier than w+4, we must buy this toy anyway.
// If there's other toys lies in the range [w+1, w+4] and we bought that one instead, we still have to buy this toy later.
// Note there's overlapping in the free interval so it can't be the best strategy (or at least no better than our strategy).
int w[100000];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&w[i]);
    sort(w,w+n);
    int cnt=1,curw=w[0]; // we initially buy the first toy
    for (int i=1;i<n;i++)
    {
        if (w[i] > curw + 4)
        {
            cnt++;
            curw = w[i];
        }
    }
    printf("%d\n",cnt);
    return 0;
}

