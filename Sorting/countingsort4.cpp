/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/countingsort4
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
// Put the strings in a bucket!
int main()
{
    int n,x;
    char str[20];
    vector <string> buckets[100];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d%s",&x,str);
        string s = str;
        if (i<n/2)
            s = "-";
        buckets[x].push_back(s);
    }

    for (int i=0;i<100;i++)
        for (int j=0;j<buckets[i].size();j++)
            printf("%s ",buckets[i][j].c_str());
}
