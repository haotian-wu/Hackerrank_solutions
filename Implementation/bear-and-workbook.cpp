/*******************************************************
 * Copyright (C) 2016 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/bear-and-workbook
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

// Just implement!

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[100];
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    // lu[i] stores the lower bound and upper bound of question numbers on page i.
    pair<int,int> lu[10001];
    int curpage = 1;
    for (int i=0;i<n;i++)
    {
        for (int j=0; j<(arr[i]+k-1)/k; j++)
            lu[j+curpage] = make_pair(k*j+1, min(k*(j+1), arr[i]));
        curpage += (arr[i]+k-1)/k;
    }
    int cnt = 0;
    for (int i=1; i<curpage; i++)
        if (lu[i].first <= i && i <= lu[i].second)
            cnt++;
    printf("%d\n",cnt);
    return 0;
}
