/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/kaprekar-numbers
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getd(int i)
{
    int d = 0;
    while (i>0)
    {
        d++;
        i/=10;
    }
    return d;
}
int pow10(int d)
{
    int mul=1;
    while (d--)
        mul*=10;
    return mul;
}
int main() {
    // Use long long to avoid overflow.
    int p,q,flag=0;
    scanf("%d %d",&p,&q);
    for (int i=p;i<=q;i++)
    {
        long long sq = (long long)i*i;
        int p10 = pow10(getd(i));
        if (sq%p10 + sq/p10 == i)
        {
            flag=1;
            printf("%d ",i);
        }
    }
    if (flag==0)
        printf("INVALID RANGE");
    return 0;
}
