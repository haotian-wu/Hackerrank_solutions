/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/halloween-party
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
    // Math problem. The conclusion is, if K is even, we give K/2 horizontal cuts and K/2 vertical cuts;
    // if K is odd, we give (K-1)/2 horizontal cuts and (K+1)/2 vertical cuts.
    // You can try to prove it. Proof is trivial.
    // Just watch out the result may exceed the range of int.
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int k;
        scanf("%d",&k);
        printf("%lld\n",(k/2)*(long long)(k-k/2));
    }
    
    return 0;
}
