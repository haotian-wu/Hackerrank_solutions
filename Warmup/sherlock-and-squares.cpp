/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-squares
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
    // How to make the code both efficient and free of floating point error?
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int sqa, sqb; //sqa: smallest int with sqa*sqa>=a, sqb: largest int with sqb*sqb<=b
        sqa = (int)(sqrt(a)+1e-9);
        if (sqa*sqa<a)
            sqa++;
        sqb = (int)(sqrt(b)+1e-9);
        if (sqb*sqb>b) //Perhaps this is not necessary; just for insurance.
            sqb--;
        printf("%d\n",sqb-sqa+1); //This considered the case that 0 squares within the range.
    }
    
    
    return 0;
}
