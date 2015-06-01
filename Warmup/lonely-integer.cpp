/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/lonely-integer
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>

using namespace std;
int main() {
    // Algorithm: XOR all integers and we get the result. 
    // That's because A ^ A = 0, A ^ 0 = A, and sequence doesn't matter.
    int n;
    scanf("%d",&n);
    int ret = 0;
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        ret ^= x;
    }
    printf("%d\n",ret);
    return 0;
}
