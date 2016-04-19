/*******************************************************
 * Copyright (C) 2016 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/bear-and-steady-gene
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

// To rephrase the question, how can you chose i and j wisely, such that if we count the occurrence of each letter, it's no more than n/4.
// The objective is to minimize the number of letters in between i and j.
// Naive approach (with some optimization) is O(n^2), if you traverse all possible combinations of i and j.
// Two pointers algorithm will be much better. It will be O(n).
// First, we let j move from right to left, until moving left will be infeasible (one of the letters occur more than n/4 times).
// We need a counter for each letter to do this.
// Then we move i from left to right. For each move, if this move will cause this letter occur more than n/4 times, 
// we move j to the right until we reach this letter, than move right one more to keep this letter occur n/4 times.
// During this process, we keep track of the minimum letters in between i and j.

int main() {
    int n;
    char str[500001];
    scanf("%d %s",&n,str);
    int i=0, j=n-1, minl=n;
    int cnt[128] = {0};
    while (1)
    {
        if (j<0 || cnt[str[j]]==n/4)
        {
            j++;
            break;
        }
        else
        {
            cnt[str[j]]++;
            j--;
        }
    }
    if (j < minl)
        minl = j;
    for (i=0; i<n; i++)
    {
        cnt[str[i]]++;
        while (j<n && cnt[str[i]] > n/4)
        {
            cnt[str[j]]--;
            j++;
        }
        if (j==n)
            break;
        if (j-i-1 < minl)
            minl = j-i-1;
    }
    printf("%d\n",minl);
}
