/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/counting-valleys
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

// Just count the number of times we go up to sea level. 
// We really don't care when we went down below sea level... 

int main() {
    int n;
    char str[1000001];
    scanf("%d %s", &n, str);
    int height = 0, valleycnt = 0;
    for (int i=0; i<n; i++)
        if (str[i] == 'U')
        {
            height ++;
            if (height == 0)
                valleycnt ++;
        }
        else 
            height --;
    printf("%d\n", valleycnt);
}
