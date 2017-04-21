/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/mars-exploration
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

// Modulo.

int main() {
    string str;
    cin >> str;
    int cnt = 0;
    for (int i=0; i<str.size(); i++)
        if (i%3==1 && str[i] != 'O')
            cnt++;
        else if (i%3!=1 && str[i] != 'S')
            cnt++;
    cout << cnt << endl;
}
