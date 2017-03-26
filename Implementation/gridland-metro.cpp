/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/gridland-metro
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

// Just sort and merge the intervals! 
// We use map because row index is too big for array.
// Count how many grids are occupied, so we know how many grids are vacant.
// Can be solved with segment tree as well; see gridland-metro-seg.cpp.

int main() {
    int n,m,k; 
    scanf("%d %d %d",&n,&m,&k);
    map<int,vector<pair<int,int> > > mp;
    for (int i=0; i<k; i++)
    {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        mp[a].push_back(make_pair(b,c));
    }
    long long sum_occupied = 0;
    for (map<int,vector<pair<int,int> > > :: iterator j = mp.begin(); j!=mp.end(); j++)
    {
        vector<pair<int,int> > v = j->second;
        sort(v.begin(), v.end());
        v.push_back(make_pair(2000000001,2000000001));
        int l=0, r=-1;
        for (int i=0; i<v.size(); i++)
        {
            if (v[i].first > r)
            {
                sum_occupied += (r-l+1);
                l = v[i].first;
                r = v[i].second;
            }
            else
                r = max(r, v[i].second);
        }
    }
    printf("%lld\n", (long long)n * m - sum_occupied);
}
