/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/diagonal-difference
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
// Sum up and substract. Straightforward.
int main()
{
    int n;
    scanf("%d",&n);
    int mat[100][100];
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    int sum1=0,sum2=0;
    for (int i=0;i<n;i++)
    {
        sum1 += mat[i][i];
        sum2 += mat[i][n-1-i];
    }
    printf("%d\n",abs(sum1-sum2));
}
