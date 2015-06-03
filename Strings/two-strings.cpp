/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/two-strings
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
    // We can simply look at if there's a single character in common.
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        char str[2][100001];
        for (int i=0;i<2;i++)
            scanf("%s",str[i]);
        int count[2][26];
        memset(count,0,sizeof(count));
        int l0 = strlen(str[0]);
        int l1 = strlen(str[1]);
        for (int j=0;j<l0;j++)
            count[0][str[0][j]-'a']++;
        for (int j=0;j<l1;j++)
            count[1][str[1][j]-'a']++;
        int flag=0;
        for (int j=0;j<26;j++)
            if (count[0][j]>0 && count[1][j]>0)
            {
                flag=1;
                break;
            }
        printf("%s\n",flag?"YES":"NO");
    }
    
    
    return 0;
}
