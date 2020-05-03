/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/missing-numbers
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
// HHHHHHHHHHHHHHHHHHHHHHHash!
int n,m,A[1000010];
map <int,int> mp;
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&A[i]);
    scanf("%d",&m);
    int tmp;
    while (m--)
    {
        scanf("%d",&tmp);
        mp[tmp]++;
    }
    for (int i=0;i<n;i++)
        mp[A[i]]--;
    for (map<int,int> :: iterator j = mp.begin();j!=mp.end();j++)
    {
        if (j->second > 0)
            cout << j->first << " ";
    }
    
}
