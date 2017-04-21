/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/camelcase
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

// Count the number of words... or just count the number of upper case letters?

int main() {
    string s;
    cin >> s;
    int cnt=0;
    for (int i=0; i<s.size(); i++)
        if (isupper(s[i])) // or s[i] >= 'A' && s[i] <= 'Z'
            cnt++;
    cout << cnt+1 << endl;
}
