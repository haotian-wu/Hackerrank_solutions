/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/bigger-is-greater
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
    int tt;
    scanf("%d",&tt);
    char str[101];
    while (tt--)
    {
        scanf("%s",str);
        int L=strlen(str), flag=0;
        for (int i=L-2;i>=0;i--) //Find the rightmost character with str[i]<str[i+1]
        {
            if (str[i]<str[i+1])
            {
                flag=1;  //Flag: can I find a character with str[i]<str[i+1]?
                int minc=128,minidx=i;
                for (int j=i+1;j<L;j++) //Find the smallest character which is greater than str[i]
                    if (str[j]<minc && str[j]>str[i])
                    {
                        minc=str[j];
                        minidx = j;
                    }
                swap(str[i],str[minidx]); //Put the smallest greater character in str[i]
                sort(str+(i+1), str+L); //Sort the characters on the right
                printf("%s\n",str);
                break;
            }
        }
        if (flag==0)
            printf("no answer\n");
    }
    return 0;
}
