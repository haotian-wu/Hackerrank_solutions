/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sam-and-substrings
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

// For example, we are given the string "123". We can calculate in the sequence of:
// In the first run:
// 1
// Second Run:
//  2
// 12
// Third Run:
//   3
//  23
// 123
// We notice in the k'th run, The sum of all numbers s[k] = s[k-1]*10 + k * (num[k]).
const int MOD = 1000000007;
int s[200001];
int main() {
    char str[200001];
    scanf("%s",str);
    int len = strlen(str);
    s[0] = str[0] - '0';
    for (int i=1; i<len; i++)
        s[i] = ((long long)s[i-1]*10 + (i+1) * (str[i] - '0')) % MOD;
    int ans = 0;
    for (int i=0; i<len; i++)
        ans = (ans + s[i]) % MOD;
    printf("%d\n",ans);
}
