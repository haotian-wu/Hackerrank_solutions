/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/matrix-rotation-algo
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
// The main observation is, we need to figure out the length of each loop, and module R by each length.
struct point {
    int x;
    int y;
};
int main()
{
    int tt;
    int n, m, r;
    scanf("%d %d %d",&n,&m,&r);
    int arr[300][300];
    int newarr[300][300];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&arr[i][j]);
    int l = min(n,m) / 2;
    vector <point> loops[l];
    for (int i=0;i<l;i++) // Put all coordinates of a loop in an array
    {
        int a = i+1, b = i;
        while (a < n-i)
        {
            loops[i].push_back((point){a,b});
            a++;
        }
        a = n-i-1; b = i+1;
        while (b < m-i)
        {
            loops[i].push_back((point){a,b});
            b++;
        }
        a = n-i-2; b = m-i-1;
        while (a >= i)
        {
            loops[i].push_back((point){a,b});
            a--;
        }
        a = i; b = m-i-2;
        while (b >= i)
        {
            loops[i].push_back((point){a,b});
            b--;
        }
    }
    for (int i=0;i<l;i++)
    {
        int lenloop = loops[i].size();
        int rl = r % lenloop;
        for (int j=0;j<lenloop;j++)
        {
            point oricor = loops[i][j];
            point newcor = loops[i][(j+rl)%lenloop];
            newarr[newcor.x][newcor.y] = arr[oricor.x][oricor.y];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            printf("%d ",newarr[i][j]);
        printf("\n");
    }
}
