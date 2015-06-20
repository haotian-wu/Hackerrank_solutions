/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/extra-long-factorials
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define SLOT (1000000000000000ll)

// I rewrited operator * for the struct. Not necessary; just for practice.
// Note the preceeding zeros when printing.
struct largenumber
{
    long long num[100]={0};
    largenumber operator * (int b)
    {
        for (int i=0;i<100;i++)
            this->num[i]*=b;
        for (int i=0;i<100;i++)
            if (this->num[i]>SLOT)
            {
                this->num[i+1] += this->num[i]/SLOT;
                this->num[i] %= SLOT;
            }
        return *this;
    }
};
void print(largenumber a)
{
    int i=99;
    while (a.num[i]==0)
        i--;
    printf("%lld",a.num[i]);
    for (i--;i>=0;i--)
        printf("%015lld",a.num[i]);
}
int main() {
    int n;
    scanf("%d",&n);
    largenumber p;
    p.num[0] = 1;
    for (int i=1;i<=n;i++)
        p = p * i;
    print(p);
    return 0;
}
