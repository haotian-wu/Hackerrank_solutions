/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/funny-string
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Simulation.
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        char str[10001];
        scanf("%s",str);
        int l = strlen(str),flag=1;
        for (int i=0;i<l-1;i++)
            if (abs(str[i]-str[i+1])!=abs(str[l-1-i]-str[l-2-i]))
            {
                flag=0;
                break;
            }
        printf("%s\n",flag?"Funny":"Not Funny");
    }
    return 0;
}
