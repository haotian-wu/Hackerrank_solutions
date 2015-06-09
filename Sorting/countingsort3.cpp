/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/countingsort3
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
// We don't care the string... Just get the cumulative sum and we are done!
int main()
{
    int n,x;
    int count[100];
    memset(count,0,sizeof(count));
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d%*s",&x);
        count[x]++;
    }
    for (int i=1;i<100;i++)
        count[i] = count[i-1]+count[i]; //Cumulative sum
    for (int i=0;i<100;i++)
        printf("%d ",count[i]);
}
