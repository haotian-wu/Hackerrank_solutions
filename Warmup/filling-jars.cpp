/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/filling-jars
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
    // You don't have to know how many candies are there exactly in a jar. Instead, we will only keep track the total number.
    int n,m;
    long long total=0;
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        total += (b-a+1)*(long long)c;
    }
    printf("%lld",total/n);
    return 0;
}
