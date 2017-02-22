/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/happy-ladybugs
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

// 1. If there's only one ladybug of its own color, there's no way we can make it happy.
// 2. If there's at least one empty cell, we can permute the ladybugs in any permutation we desire.
// Therefore, if for any color we have at least 2 ladybugs, and (all ladybugs are initially happy or there's an empty cell),
// We can make them happy.

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int emptycellflag = 0, singleladybugflag = 0, allhappyflag = 1;
        int n;
        char board[10000];
        int count[26] = {0};
        scanf("%d %s", &n, board);
        for (int i=0; i<n; i++)
        {
            if (board[i] == '_')
                emptycellflag = 1;
            else
            {
                count[board[i]-'A'] ++;
                if ( (i == n-1 || board[i] != board[i+1]) && (i == 0 || board[i] != board[i-1]) )
                    allhappyflag = 0;
            }
        }
        for (int i=0; i<26; i++)
            if (count[i] == 1)
                singleladybugflag = 1;
        if (!singleladybugflag && (allhappyflag || emptycellflag))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
