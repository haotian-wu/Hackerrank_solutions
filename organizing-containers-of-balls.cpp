/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/organizing-containers-of-balls
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Please don't implement the ball swapping.
// PLEASE DON'T IMPLEMENT THE BALL SWAPPING!!!
// First observation, the number of balls in a container will never change. Because we are just swapping, instead of taking a ball out.
// Second observation, the total number of balls of a givin color will never change. It just moved from one container to another.
// So if we have 4 red balls and a container of size 3 (or 5), it's not a suitable container for red balls.
// We have to find a container of exact size 4. (If this part is not obvious for you, read the problem description again)
// So the problem becomes: count the number of balls for each color, and the size of each container;
// then check if there's an one-to-one correspondence between the two arrays.
// The last step can be easily done by sorting both arrays.

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n;
        scanf("%d", &n);
        vector<int> sumrow(n,0), sumcolumn(n,0);
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                sumrow[i] += tmp;
                sumcolumn[j] += tmp;
            }
        sort(sumrow.begin(), sumrow.end());
        sort(sumcolumn.begin(), sumcolumn.end());
        if (sumrow == sumcolumn)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
}
