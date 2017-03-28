/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/grading
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

// For a grade g, we use (g/5+1)*5 to compute the next multiple of 5 greater than g,
// then check if the difference is less than 3.

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int g;
        scanf("%d",&g);
        int roundup = (g/5+1)*5;
        if (g < 38)
            cout << g << endl;
        else if (roundup - g <= 2)
            cout << roundup << endl;
        else
            cout << g << endl;
    }
}
