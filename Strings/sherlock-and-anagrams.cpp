/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-anagrams
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;


int main() {
    // In naive approach, we search all left string (O(N^2)), all right string with the same length (O(N)), and compare the strings O(N). Overall time complexity O(N^4).
    // Instead, we can use hash! We hash all SORTED substrings and count their occurence. If it occurs K times, we have (K(K-1)/2) such pairs.
    int tt;
    scanf("%d",&tt);
    map <string,int> mp;
    while (tt--)
    {
        mp.clear();
        char str[101];
        scanf("%s",str);
        int l = strlen(str);
        string s = str;
        for (int i=0;i<l;i++)
            for (int j=i;j<l;j++)
            {
                string sub = s.substr(i,(j-i+1));
                sort(sub.begin(),sub.end());
                mp[sub]++;
            }
        int sum=0;
        for (map<string,int> :: iterator j=mp.begin();j!=mp.end();j++)
            sum += (j->second*(j->second-1))/2;
        printf("%d\n",sum);
    }
    return 0;
}
