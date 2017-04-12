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

// See reduced-string-2.cpp for algorithm explanation. 

int main() {
    char str[101];
    scanf("%s", str);
    char out[101];
    int top = 0, len = strlen(str);
    for (int i=0; i<len; i++)
    {
        if (top == 0 || str[i] != out[top-1])
            out[top++] = str[i];
        else
            top--;
    }
    out[top] = '\0';
    if (top == 0)
        printf("Empty String\n");
    else
        printf("%s\n",out);
}
