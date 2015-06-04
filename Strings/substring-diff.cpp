/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/substring-diff
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

int getmax1(vector<bool> str,int s)
{
    int m=-1,n=str.size();
    int j=0,js=s;
    while (j<n)
    {
        if (js>0 && str[j]==false) 
        {
            j++;
            js--;
        }
        else if (js==0 && str[j]==false)
            break;
        else
            j++;
    }
    m=j;
    for (int i=1;i<n;i++)
    {
        if (str[i-1]==false)
        {
            js = 1;
            while (j<n)
            {
                if (js>0 && str[j]==false)
                {
                    j++;
                    js--;
                }
                else if (js==0 && str[j]==false)
                    break;
                else
                    j++;
            }
            if (j-i>m)
                m=j-i;
        }
    }
    return m;
}
int main() {
    // Obviously there's a O(N^3) algorithm. We want to reduce it to O(N^2). What's the redundant calculation?
    // When s1 starts at P[1], s2 starts at Q[3], we compare P[1] == Q[3], P[2] == Q[4], P[3] == Q[5], ...
    // When s1 starts at P[2], s2 starts at Q[4], we compare P[2] == Q[4], P[3] == Q[5], ...
    // The point is, we should only care the starting point of P and Q has a differnce of 2 (Q-P=2), instead of caring where P and Q really start. 
    // Now we get a BOOL STRING. It indicate whether or not the corresponding characters match.
    // e.g. P = "abcaabc", Q = "bdacbca", S=1
    // We are checking the case where P-Q=1. i.e. We should compare "bcaabc"(string starts from P[1]) and "bdacbc"(string starts from Q[0]).
    // The bool string we get is 101011, where 1 means matching and 0 means not matching.
    // Now the problem becomes, how to change some (no more than S) 0's to 1's, to make the 1's string as long as possible.
    // This can be done using two pointers algorithm (sliding window).
    int n;
    cin >> n;
    while (n--)
    {
        int s;
        cin >> s;
        string p,q;
        cin >> p >> q;
        int max1=-1;
        int l=p.size();
        vector<bool> boolstr;
        for (int i=0;i<l;i++) //Compare p with q+i
        {
            boolstr.clear();
            for (int j=0;j+i<l;j++)
                boolstr.push_back(p[j]==q[j+i]);
            int tmp = getmax1(boolstr,s);
            if (tmp>max1)
                max1=tmp;
        }
        for (int i=0;i<l;i++) //Compare p+i with q
        {
            boolstr.clear();
            for (int j=0;j+i<l;j++)
                boolstr.push_back(p[j+i]==q[j]);
            int tmp = getmax1(boolstr,s);
            if (tmp>max1)
                max1=tmp;
        }
        printf("%d\n",max1);
    }
    return 0;
}
