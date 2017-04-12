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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Just implement as the problem's instruction. 
// Considering the size of array will change, instead of modifying on the original string,
// we will create a new string.
// Since if the size of string will reduce at least 2 if the algorithm does not terminate,
// which means it will terminte in at most n/2 runs, the algorithm is O(n^2).
// For an algorithm running in O(n), see reduced-string-2.cpp .

int main() {
    string str;
    cin >> str;
    while (1)
    {
        int flag = 1;
        char pre_char = '\0';
        string new_str;
        for (int i=0; i<str.size(); i++)
            if (i==str.size()-1 || str[i] != str[i+1])
                new_str += str[i];
            else
            {
                i++;
                flag = 0;
            }
        str = new_str;
        if (flag)
            break;
    }
    cout << (str==""?"Empty String":str) << endl;
}
