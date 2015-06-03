/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/alternating-characters
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    // Whenever a character occurs consecutively, we need to delete all but one such characters.
    // So just count!
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        char str[100001];
        scanf("%s",str);
        int l = strlen(str),cnt=1;
        for (int i=1;i<l;i++) //i should start from 1
            if (str[i]!=str[i-1])
                cnt++;
        printf("%d\n",l-cnt);
    }
    return 0;
}
