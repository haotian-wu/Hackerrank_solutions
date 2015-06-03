/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/make-it-anagram
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
    // If it occurs oa[i] times in str_a, ob[i] times in str_b, we should delete (abs(oa[i]-ob[i])) characters for char i.
    // Sum up for all i's.
    char str[10001];
    int count[2][26];
    memset(count,0,sizeof(count));
    for (int i=0;i<2;i++)
    {
        scanf("%s",str);
        int l = strlen(str);
        for (int j=0;j<l;j++)
            count[i][str[j]-'a']++;
    }
    int sum=0;
    for (int j=0;j<26;j++)
        sum += abs(count[0][j]-count[1][j]);

    printf("%d\n",sum);
    
    return 0;
}
