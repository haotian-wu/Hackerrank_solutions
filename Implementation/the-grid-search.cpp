/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/the-grid-search
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
// Naive approach seems to have O(RCrc) complexity in worst case...
int main()
{
    char ori[1001][1001];
    char pattern[1001][1001];
    int tt;
    int R, C, r, c;
    scanf("%d",&tt);
    while (tt--)
    {
        scanf("%d %d",&R,&C);
        for (int i=0;i<R;i++)
            scanf("%s",ori[i]);
        scanf("%d %d",&r,&c);
        for (int i=0;i<r;i++)
            scanf("%s",pattern[i]);
        for (int i=0;i<R;i++)
        {
            if (i+r-1>=R)
                break;
            for (int j=0;j<C;j++)
            {
                if (j+c-1>=C)
                    break;
                int flag=1;
                for (int k=0;k<r;k++)
                {
                    for (int l=0;l<c;l++)
                        if (ori[i+k][j+l] != pattern[k][l])
                        {
                            flag=0;
                            break;
                        }
                    if (flag==0)
                        break;
                }
                if (flag==1)
                {
                    printf("YES\n");
                    goto out;
                }
            }
        }
        printf("NO\n");
        out:
        ;
        
    }
    
}
