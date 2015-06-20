/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/staircase
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Just draw it!
void draw(int row, int n)
{
    for (int i=0;i<(n-row);i++)
        printf(" ");
    for (int i=0;i<row;i++)
        printf("#");
    printf("\n");
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        draw(i,n);
    return 0;
}
