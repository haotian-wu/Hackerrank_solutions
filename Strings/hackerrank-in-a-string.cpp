/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/hackerrank-in-a-string
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

// Greedily match the earliest occurrence of each needed char.

int main() {
    int n;
    cin >> n;
    string match = "hackerrank";
    while (n--)
    {
        string str;
        cin >> str;
        int i=0;
        for (int j=0; j<str.size(); j++)
        {
            if (i!=10 && str[j] == match[i])
                i++;
        }
        if (i==10)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
