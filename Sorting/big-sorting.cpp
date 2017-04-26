/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/big-sorting
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

// Write your own string compare algorithm!
bool cmp(string& a, string& b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    else
        return a < b;
}

int main() {
    int n;
    vector<string> a;
    string str;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> str;
        a.push_back(str);
    }
    sort(a.begin(), a.end(), cmp);
    for (int i=0; i<n; i++)
        cout << a[i] << endl;
}
