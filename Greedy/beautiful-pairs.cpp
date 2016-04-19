/*******************************************************
 * Copyright (C) 2016 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/beautiful-pairs
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

// Check how many pairs can be matched between a and b.
// Simply output that number plus 1 since you can modify a number in b.
// BUT something seems wrong... what if all pairs are matched? If you thought about this, give yourself an apploud.
// Because you HAVE TO modify a number in b in this question, 
// if all pairs are matched, you have to output n-1, since you modified a matched pair to unmatched.

int main() {
    int n;
    int a,b;
    scanf("%d",&n);
    map<int,int> cnta;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a);
        cnta[a] ++;
    }
    int cntmatch=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&b);
        if (cnta[b] > 0)
        {
            cnta[b]--;
            cntmatch ++;
        }
    }
    if (cntmatch == n)
        printf("%d\n",cntmatch-1);
    else
        printf("%d\n",cntmatch+1);
}
