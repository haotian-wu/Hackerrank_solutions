/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/game-of-thrones
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
    // Count the time of occurence of each char. 
    // To get a palindrome, at most 1 char can occur odd times; all other should occur even times.
    char str[100001];
    int _hash[26];
    scanf("%s",str);
    int l = strlen(str);
    memset(_hash,0,sizeof(_hash));
    for (int i=0;i<l;i++)
        _hash[str[i]-'a']++;
    int odd=0;
    for (int i=0;i<26;i++)
        if (_hash[i]%2==1)
            odd++;
    if (odd<=1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
