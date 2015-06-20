/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/time-conversion
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// We don't even have to convert the time to int!
int main() {
    char time[20];
    scanf("%s",time);
    if (time[0] == '1' && time[1] == '2') // 12 -> 0
        time[0] = time[1] = '0';
    if (time[8] == 'P') // AM or PM? if PM then hour += 12
    {
        time[0] += 1; 
        time[1] += 2;
    }
    time[8] = '\0';
    if (time[1] > '9')
    {
        time[0]++;
        time[1]-=10;
    }
    printf("%s\n",time);
    return 0;
}
