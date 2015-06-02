/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-the-beast
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Greedy. Get as many 5's as possible, and put all the 5's in front.
    // Note the number of occurrence of 3 will loop with a size of 15. But the first 15 may differ a little bit.
    // e.g. for 6, we have 3+3; for 21, we have 3+3 + 5+5+5.
    // However, for 1, we cannot make it; but for 16, we have 3+3 + 5+5.
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int n;
        scanf("%d",&n);
        int r = (n-15)%30+15;
        int flag=0;
        for (int i=r/3;i>=0;i--) //Use as many 5's as possible
        {
            if ((r-i*3)%5==0)
            {
                for (int i=0;i<(n-15)/30*30;i++)
                    printf("5");
                for (int j=0;j<i*3;j++)
                    printf("5");
                for (int j=0;j<r-i*3;j++)
                    printf("3");
                flag=1;
                break;
            }
        }
        if (flag==0)
            printf("-1");
        printf("\n");
    }
    return 0;
}
