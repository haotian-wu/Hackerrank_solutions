/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/countingsort1
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
using namespace std;
// Counting is always useful. The basic idea is hash.
// In this problem, we don't need to record every number. Just read, count and forget.
int main()
{
    int n,x;
    int count[100];
    memset(count,0,sizeof(count));
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        count[x]++;
    }
    for (int i=0;i<100;i++)
        printf("%d ",count[i]);
}
