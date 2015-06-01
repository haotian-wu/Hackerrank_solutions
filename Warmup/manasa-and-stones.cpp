/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/manasa-and-stones
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
    // The sequence of a,b's doesn't matter. The number of times a and b occur matters.
    // Note the case a>b or even a==b (I don't know if it is possible; I'll write it anyway)
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n,a,b;
        scanf("%d %d %d",&n,&a,&b);
        if (a==b)
        {
            printf("%d\n",(n-1)*a);
            continue;
        }
        int x=min(a,b),y=max(a,b);
        for (int i=0;i<n;i++)
            printf("%d%c",(n-1-i)*x+i*y,(i==n-1)?'\n':' '); //Get rid of the space at the end of line
    }
    return 0;
}
