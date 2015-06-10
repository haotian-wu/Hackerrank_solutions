/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/chocolate-in-box
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
// Classical Nim model.
// See http://en.wikipedia.org/wiki/Nim 
int main()
{
    int n;
    int cnt=0;
    int arr[1000000];
    int allxor = 0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        allxor ^= arr[i];
    }
    for (int i=0;i<n;i++)
        if (arr[i] > (allxor^arr[i]))
            cnt++;
    printf("%d\n",cnt);
    
}
