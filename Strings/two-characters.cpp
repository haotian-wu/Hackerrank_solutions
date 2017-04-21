/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/two-characters
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Traverse all possible 2-char combinations, remove all other chars except them, and check if it's alternating.
// Pretty brute force.
bool isalter(string& str)
{
    for (int i=1; i<str.size(); i++)
        if (str[i] == str[i-1])
            return false;
    return true;
}

int main() {
    int len;
    string str;
    cin >> len >> str;
    set<char> charset;
    for (int i=0; i<len; i++)
        charset.insert(str[i]);
    string allchar="";
    for (set<char> :: iterator i=charset.begin(); i!=charset.end(); i++)
        allchar += *i;
    int maxresult = 0;
    for (int i=0; i<allchar.size(); i++)
        for (int j=i+1; j<allchar.size(); j++)
        {
            string copy;
            for (int k=0; k<len; k++)
            {
                if (str[k] == allchar[i] || str[k] == allchar[j])
                    copy += str[k];
            }
            if (isalter(copy))
                maxresult = max(maxresult, (int)(copy.size()));
        }
    cout << maxresult << endl;
}
