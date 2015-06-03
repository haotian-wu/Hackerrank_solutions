/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/gem-stones
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
using namespace std;


int main() {
    // Just hash!
    char str[101];
    int _hash[100][26];
    int n;
    scanf("%d",&n);
    memset(_hash,0,sizeof(_hash));
    for (int i=0;i<n;i++)
    {
        scanf("%s",str);
        int l = strlen(str);
        for (int j=0;j<l;j++)
            _hash[i][str[j]-'a']++;
    }
    int cnt=0;
    for (int j=0;j<26;j++)
    {
        int flag=1;
        for (int i=0;i<n;i++)
            if (_hash[i][j]==0)
            {
                flag=0;
                break;
            }
        if (flag)
            cnt++;
    }
    printf("%d\n",cnt);
    
    return 0;
}
