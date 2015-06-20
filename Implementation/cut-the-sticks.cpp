/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/cut-the-sticks
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // You don't really have to cut every stick :) 
    // In the first example, we first cut 2 and then cut another 2, and another 1.
    // We can also treat it as: we first cut 2, then they MAGICALLY recovered, and we cut 4, and they recover, and cut 5...
    // So we don't have to change the lengths every time!
    int n;
    int sticks[1000];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&sticks[i]);
    sort(sticks,sticks+n);
    printf("%d\n",n);
    for (int i=0;i<n;)
    {
        int cur = sticks[i];
        while (sticks[i]==cur)
            i++;
        if (n!=i)
            printf("%d\n",n-i);
    }
    return 0;
}
