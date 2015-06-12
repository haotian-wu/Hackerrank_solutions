/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/encryption
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
// Compute sqrt(L). Watch out float point error.
int main()
{
    char str[100];
    scanf("%s",str);
    int l = strlen(str);
    int floorl = (int)(sqrt(l)+1e-9); 
    int ceill = (l==floorl*floorl? floorl : floorl+1);
    char grid[10][10] = {0};
    int x=0,y=0;
    for (int i=0;i<strlen(str);i++)
    {
        grid[x++][y] = str[i];
        if (x==ceill)
        {
            x = 0;
            y++;
        }
    }
    for (int i=0;i<ceill;i++)
        printf("%s ",grid[i]);
    
}
