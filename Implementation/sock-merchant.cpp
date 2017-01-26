/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sock-merchant
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

// Use map to keep track of how many socks that belong to a color.

int main() {
    int n;
    scanf("%d", &n);
    map<int,int> mp;
    for (int i=0; i<n; i++)
    {
        int color;
        scanf("%d", &color);
        mp[color]++;
    }
    int cnt=0;
    for (map<int,int> :: iterator j = mp.begin(); j!=mp.end(); j++)
        cnt += j->second / 2;
    printf("%d\n",cnt);
    return 0;
}
