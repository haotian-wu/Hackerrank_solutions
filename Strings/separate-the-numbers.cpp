/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/separate-the-numbers
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

// Traverse all possible split method; then do several +1s, merge them together and compare with original string.

string str_plus1(string str)
{
    int carry = 1;
    for (int i=str.size()-1; i>=0; i--)
    {
        str[i] += carry;
        if (str[i] > '9')
        {
            str[i] = '0';
            carry = 1;
        }
        else
            carry = 0;
    }
    if (carry)
        str = '1' + str;
    return str;
}
int main() {
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        int flag = 0;
        for (int i=1; i<str.size()-1; i++)
        {
            string sub = str.substr(0,i);
            if (sub[0] == '0' && sub != "0")
                break;
            string cur = sub;
            while (cur.size() < str.size())
            {
                sub = str_plus1(sub);
                cur += sub;
            }
            if (cur == str)
            {
                flag = 1;
                cout << "YES " << str.substr(0,i) << endl;
                break;
            }
        }
        if (flag == 0)
            cout << "NO" << endl;
    }
}
