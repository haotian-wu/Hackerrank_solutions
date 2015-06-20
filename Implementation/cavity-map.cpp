/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/cavity-map
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

char mp[100][101];
char out[100][101]; // Output map. We can get rid of this if we use a more fancy way to write... but this is more understandable.
int main() {
    // OK. Simulation again. Watch out for edge checking.
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%s",mp[i]);
        strcpy(out[i],mp[i]);
    }
    for (int i=1;i<n-1;i++)
        for (int j=1;j<n-1;j++) //We carefully pick start and end point so we don't have to check edges!
            if (mp[i][j]>mp[i][j-1] && mp[i][j]>mp[i][j+1] && mp[i][j]>mp[i-1][j] && mp[i][j]>mp[i+1][j])
                out[i][j] = 'X';
    for (int i=0;i<n;i++)
        printf("%s\n",out[i]);
    return 0;
}
