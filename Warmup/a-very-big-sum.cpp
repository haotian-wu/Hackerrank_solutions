/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/a-very-big-sum
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// LONG LONG!
int main() {
    int n,x;
    long long sum;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&x);
        sum += x;
    }
    printf("%lld\n",sum);
    return 0;
}
