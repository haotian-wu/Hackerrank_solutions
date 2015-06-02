/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/song-of-pi
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

char pi[] = "31415926535897932384626433833";

int main() {
    // Hmm. Splitting a string in C++ is a big problem...
    int tt;
    char line[501];
    scanf("%d%*c",&tt);
    vector<int> mypi;
    while (tt--)
    {
        mypi.clear();
        gets(line);
        string str = line, tmp;
        stringstream ss(str);
        while (ss >> tmp)
            mypi.push_back(tmp.length());
        int flag=1;
        for (int i=0;i<mypi.size();i++)
            if (pi[i]-'0' != mypi[i])
            {
                flag=0;
                break;
            }
        if (flag)
            printf("It's a pi song.\n");
        else
            printf("It's not a pi song.\n");
    }
    return 0;
}
