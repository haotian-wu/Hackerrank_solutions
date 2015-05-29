/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/antipalindromic-strings
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstdlib>
#define MOD 1000000007

/*
The code can be a lot easier if written in Python.
How can a string become antipalindromic? 
If we already have an antipalindromic string, and we will add a new character str[i] on the right,
we should avoid str[i-1..i], str[i-2..i], str[i-3..i] ... to be palindromic.
To make str[i-1..i] be antipalindromic, we have str[i] != str[i-1].
To make str[i-2..i] be antipalindromic, we have str[i] != str[i-2].
Can str[i-3..i] be palindromic? If so, we must have str[i-2] == str[i-1]. This is contradictory to our assumption.
So we only need to make str[i] different from str[i-1] and str[i-2]!!! In other words, we have (M-2) choices in str[i].
Lastly we consider the case N=1 and N=2. We have M choices when N=1, and M-1 choices when N=2.
Therefore the result is M when N=1, M(M-1) when N=2, and M(M-1)(M-2)^(N-2) when N>2.
*/
int exp_mod(int base, int exp, int mod)
{
    /* Returns 1 if base == 0 && exp == 0*/
    long long ans = 1;
    int a = base;
    while (exp)
    {
        if (exp & 0x1) ans = ans * a % mod;
        a = (long long) a * a % mod;
        exp >>= 1;
    }
    return (int) ans;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n,m,ans;
        scanf("%d %d",&n,&m);
        if (n==1)
            ans = m;
        else if (n==2)
            ans = (int) (((long long) m) * (m-1) % MOD);
        else
            ans = (int) (((long long) m) * (m-1) % MOD * exp_mod(m-2, n-2, MOD) % MOD);
        printf("%d\n",ans);
    }
    return 0;
}
