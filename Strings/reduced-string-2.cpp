/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/reduced-string
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

// Consider a stack. When a new char arrives, we check if this is the same char with the top-stack char.
// If so, we remove the top-stack char. Else, we push the char to the stack.
// This algorithm works, obviously. It's best implemented with deque, since when we convert the stack to string,
// we still want a FIFO feature.
// See reduced-string-3.cpp if you want code for this algorithm WITHOUT STL (i.e. solve it with C-like code).

int main() {
    string str;
    cin >> str;
    deque <char> dq;
    for (int i=0; i<str.size(); i++)
    {
        if (dq.empty() || dq.back() != str[i])
            dq.push_back(str[i]);
        else
            dq.pop_back();
    }
    if (dq.empty())
        cout << "Empty String" << endl;
    else
        for (deque<char> :: iterator j = dq.begin(); j!=dq.end(); j++)
            cout << *j;
}
