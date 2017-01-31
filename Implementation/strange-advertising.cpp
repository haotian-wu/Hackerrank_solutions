/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/strange-advertising
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// There's nothing to say about this problem. 
// However, what if there're 1,000,000 queries, and in each query, the range of n is 1 to 1,000,000?
// We can pre-compute the answer for all queries, and then start to read query and output result. 
// This is called "offline" algorithm. 
// On the contrary, online algorithm does the calculation every time it receives a query. 
// When the input is huge, online algorithm will lead to a time limit exceed.

int main() {
    int n;
    cin >> n;
    int liked[50], sum = 2;
    liked[0] = 2;
    for (int i=1; i<n; i++)
    {
        liked[i] = liked[i-1] * 3 / 2;
        sum += liked[i];
    }
    cout << sum << endl;
}
