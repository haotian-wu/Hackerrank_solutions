/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited
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

// Simple!

int main() {
    int n, k;
    cin >> n >> k;
    int c[100];
    for (int i=0; i<n; i++)
        cin >> c[i];
    int energy = 100;
    for (int i=0; i<n; i+=k)
        energy -= 1 + c[i] * 2;
    cout << energy << endl;
}
