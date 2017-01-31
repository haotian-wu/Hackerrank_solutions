/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/append-and-delete
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

// We call a string whose length is a even number "even string", and odd length, "odd string".
// We call this "parity of strings".
// Obviously the operations 1 and 2 will change an even string to odd, or an odd string to even, guaranteed. 
// That's why we can never change "abcde" to "abcdf" in 3 steps; 3 steps will change an odd string to an even string.
// That is to say, in order to change one string to another, we need to find out how many operations are required. 
// Say d operations are required; then we must have k >= d, and k has the same parity with d, 
// in order to change string a to string b in k moves.
// However we notice that we can remove a char from an empty string, which results in an empty string as well.
// This is a rule breaker; it invented a new way of changing string a to b by: 
// First remove all characters in a, then remove characters from this empty string a few times 
// (this does nothing but change the parity), then add all chars from b.
// As long as k is greater than the sum of lengths of the two strings, this is guaranteed to work, regardless of parities of the strings.

int main() {
    string str1, str2;
    int moves;
    cin >> str1 >> str2 >> moves;
    int i;
    for (i = 0; i < min(str1.size(), str2.size()); i++)
        if (str1[i] != str2[i])
            break;
    int diff = str1.size() - i + str2.size() - i;
    if (moves >= str1.size() + str2.size() || (moves >= diff && (moves - diff) % 2 == 0) )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
