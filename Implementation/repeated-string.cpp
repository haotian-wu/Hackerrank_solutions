/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/repeated-string
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

// We suppose the infinitely repeated string starts with index 0. Then the first n letters are index 0 to n-1.
// Considering the string is repeated, we can split the string into two pieces: 0 to k-1 and k to n-1, 
// where k is the largest number that is a multiple of |S| and no greater than n-1.
// Now we know the 0 ~ k-1 part are (k/|S|) occurrences of string S, and k to n-1 part is a partial string.
// And this partial string is exactly the same with the string indexed 0 to (n-1)%|S| .

int main() {
    string str;
    long long n;
    cin >> str >> n;
    long long cnt_S = 0, cnt_all = 0;
    for (int i=0; i<str.size(); i++)
        if (str[i] == 'a')
            cnt_S ++;
    cnt_all = cnt_S * ((n-1) / str.size());
    for (int i=0; i<=(n-1)%str.size(); i++)
        if (str[i] == 'a')
            cnt_all ++;
    cout << cnt_all << endl;
}
