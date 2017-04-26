/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/beautiful-binary-string
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

// When we see a 010, we have to change one character. But which?
// Considering string 01010, the 0 in the middle is shared by two "010"s. 
// No other cases in which a char will be shared by two 010s.
// So the optimal solution is to change the middle 0 to 1. 
// In fact, if we search from left to right and run into a 010, it never hurts if we change the rightmost 0 to 1.
// Simulate this and you'll get the answer.

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt=0;
    for (int i=2; i<n; i++)
        if (str[i-2] == '0' && str[i-1] == '1' && str[i] == '0')
        {
            cnt++;
            str[i] = '1';
        }
    cout << cnt << endl;
}
