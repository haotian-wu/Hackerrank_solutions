/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/pangrams
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int _hash[26];
int main() {
    // Instead of going through the sentence 26 times, we use hash.
    char str[1001];
    gets(str);
    int l = strlen(str);
    memset(_hash,0,sizeof(_hash));
    for (int i=0;i<l;i++)
        if (str[i]>='a' && str[i]<='z')
            _hash[str[i]-'a']=1;
        else if (str[i]>='A' && str[i]<='Z')
            _hash[str[i]-'A']=1;
    int flag=1;
    for (int i=0;i<26;i++)
        if (_hash[i]==0)
        {
            flag=0;
            printf("not pangram\n");
            break;
        }
    if (flag)
        printf("pangram\n");
    return 0;
}
