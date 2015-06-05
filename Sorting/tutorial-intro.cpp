/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/tutorial-intro
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main() {
    // Can it be more easier?
    int q,n;
    scanf("%d %d",&q,&n);
    for (int i=0;i<n;i++)
    {
        int s;
        scanf("%d",&s);
        if (q==s)
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
