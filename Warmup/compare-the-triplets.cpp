/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/compare-the-triplets
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Just compare!
int main() {
    int a[3], b[3];
    cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
    int ascore = 0, bscore = 0;
    for (int i=0; i<3; i++)
        if (a[i] > b[i])
            ascore++;
        else if (a[i] < b[i])
            bscore++;
    printf("%d %d\n",ascore,bscore);
    return 0;
}
