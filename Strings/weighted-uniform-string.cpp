/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/weighted-uniform-string
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

// Pre-compute all possible substring weights, and save them in a map.

int main() {
    string str;
    int n;
    cin >> str >> n;
    set<int> w;
    char pre_char = '@';
    int accu_weight;
    for (int i=0; i<str.size(); i++)
    {
        if (str[i] != pre_char)
        {
            pre_char = str[i];
            accu_weight = str[i] - 'a' + 1;
            w.insert(accu_weight);
        }
        else
        {
            accu_weight += str[i] - 'a' + 1;
            w.insert(accu_weight);
        }
    }
    while (n--)
    {
        int q;
        cin >> q;
        cout << (w.count(q)?"Yes":"No") << endl;
    }
}
