/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/caesar-cipher-1
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Watch out (1) char overflow, (2) K = K % 26
int main() {
    int n,k;
    char str[101];
    scanf("%d %s %d",&n,str,&k);
    k %= 26;
    for (int i=0;i<n;i++)
    {
        if (str[i]>='A' && str[i]<='Z')
            str[i] = (str[i]-'A'+k)%26+'A';
        else if (str[i]>='a' && str[i]<='z')
            str[i] = (str[i]-'a'+k)%26+'a';
    }
    printf("%s\n",str);
    return 0;
}
