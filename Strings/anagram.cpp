/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/anagram
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
    // Count the time of occurrence of each character in both strings.
    // Compute the difference, sum up, divide it by 2 and you get the answer.
    // e.g.: you have 2 strings made up by a, b, and c;
    // # of occurrence | a | b | c
    //            Str1 | 0 | 2 | 3
    //            Str2 | 1 | 4 | 0
    // The difference is abs(0-1) + abs(2-4) + abs(3-0) = 6.
    // Since change a single character (for example, from c to a) reduces the difference by 2, 
    // we can make two strings anagram in 3 moves.
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        char str[10001];
        scanf("%s",str);
        int count[2][26];
        memset(count,0,sizeof(count));
        int l = strlen(str);
        if (l%2==1)
        {
            printf("-1\n");
            continue;
        }
        for (int j=0;j<l/2;j++)
            count[0][str[j]-'a']++;
        for (int j=l/2;j<l;j++)
            count[1][str[j]-'a']++;
        int sum=0;
        for (int j=0;j<26;j++)
            sum += abs(count[0][j]-count[1][j]);
        printf("%d\n",sum/2);
    }
    
    
    return 0;
}
