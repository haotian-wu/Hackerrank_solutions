/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/equality-in-a-array
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

// Simply check which element has the greatest number of occurrences in the array, and remove all others.

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        mp[tmp] ++;
    }
    int maxv = 0;
    for (map<int, int> :: iterator j = mp.begin(); j!=mp.end(); j++)
        if (j->second > maxv)
            maxv = j->second;
    cout << (n - maxv) << endl;
}
