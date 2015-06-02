/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/identify-smith-numbers
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// We first get all primes from 1 to sqrt(N). In this case we precompute all primes in range (1,50000).
// Decomposite N using the primes we get. If something leftover, that is the last prime factor.
// e.g. 2000000014, we found 2 is a factor, but we can't find another int which is a factor of 1000000007. Thus 1000000007 is another prime.
int prime[10000],top=0,prhash[50000];
void getprime()
{
    memset(prhash,0,sizeof(prhash));
    for (int i=2;i<50000;i++)
    {
        if (prhash[i]==0)
        {
            prime[top++]=i;
            for (int j=2;i*j<50000;j++)
                prhash[i*j]=1;
        }
    }
}
int sumdigit(int x)
{
    int sum=0;
    while (x>0)
    {
        sum += x%10;
        x/=10;
    }
    return sum;
}
int main() {
    getprime();
    int n,sumpr=0,sumn=0,ori_n;
    scanf("%d",&n);
    ori_n = n;
    sumn=sumdigit(n);
    for (int i=0;i<top;i++)
    {
        while (n%prime[i]==0)
        {
            n/=prime[i];
            sumpr += sumdigit(prime[i]);
        }
    }
    if (n>1)
        sumpr += sumdigit(n);
    if (n<ori_n && sumpr == sumn) //n<ori_n to guarantee n is not prime. In the question it says "A Smith number is a composite number".
        printf("1\n");
    else
        printf("0\n");
    return 0;
}
