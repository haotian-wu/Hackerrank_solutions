/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/birthday-cake-candles
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

// Traverse all candles to find the highest candle, and traverse twice to find how many candles have this height!
// This can be done in one traverse as well. How?
// Well we can keep track of the number of candles of current highest height. 
// If we find a higher candle, we reset the counter.
// We will implement this method since the two traversal method is trivial.

int main() {
    int n;
    scanf("%d",&n);
    int highest=-1, cnt=0;
    for (int i=0;i<n;i++)
    {
        int h;
        scanf("%d",&h);
        if (h > highest)
        {
            highest = h;
            cnt = 1;
        }
        else if (h == highest) // Note this has to be "else if" not "if" !!
            cnt ++;
    }
    printf("%d\n", cnt);
}
