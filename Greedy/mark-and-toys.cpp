/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/mark-and-toys
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

// We sort the price of the toys and buy from the cheapest. 
// Watch out the case that he's very rich and afford all toys...
int arr[100000];
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int cnt = 0;
    for (int i=0;i<n;i++)
    {
        if (k>=arr[i])
        {
            cnt++;
            k-=arr[i];
        }
        else
            break;
    }
    printf("%d\n",cnt);
    return 0;
}

