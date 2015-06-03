/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/palindrome-index
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
#include <map>
using namespace std;

bool palindromechecker(string str)
{
    int l=str.size();
    for (int i=0;i<l/2;i++)
        if (str[i]!=str[l-1-i])
            return false;
    return true;
}
int main() {
    // We search on which index, str[i] != str[l-1-i]. That means we have to delete either one.
    // So just check if str[i..l-2-i] is a palindrome. If so, we delete str[l-1-i]; if not, we delete str[i].
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        if (palindromechecker(str))
        {
            printf("-1\n");
            continue;
        }
        int l=str.size();
        for (int i=0;i<l;i++)
            if (str[i]!=str[l-1-i])
            {
                if (palindromechecker(str.substr(i,l-1-2*i)))
                    printf("%d\n",l-1-i);
                else
                    printf("%d\n",i);
                break;
            }
    }
    return 0;
}
