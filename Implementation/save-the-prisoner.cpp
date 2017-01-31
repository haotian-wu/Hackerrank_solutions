/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/save-the-prisoner
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

// ... You want to REALLY implement the process they distribute the sweets? Seriously?
// OK. Before you solve a problem, you should take a look at the range of the input. 
// Here N = 10^9, which means an O(N) algorithm won't work for sure.
// Ask yourself. If S = 1, what will happen? It will be a simple module problem. 
// It's just ((M-1) % N) + 1. Here "+1" is because the numbers are 1-based, not 0-based.
// What if S = 2? Poisoned prisoner is one number greater, so it's ((M-1) % N + 1) + 1.
// Therefore, in general, poisoned prisoner is numbered ((M-1) % N + (S-1)) + 1. 
// The number within the parenthesis is a 0-based prisoner number. Plus one to make it 1-based.
// Considering this number may be greater than N, we have to write it in this way: ((M-1)%N+(S-1))%N + 1
// We can take the module N out from the parenthesis, so this will be the same as (M+S-2)%N+1.

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, s;
        cin >> n >> m >> s;
        cout << (m+s-2)%n + 1 << endl;
    }
}
