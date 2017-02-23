/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/bomber-man
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

// Considering N is huge, we need to find out if there's a pattern, 
// i.e. some boards appear periodically, or all cells become bomb or empty, etc.
// Consider a simple board: 2x2, only upperleft has a bomb. Here dot means empty, 
// and a number represents a bomb and the time it was set up.
// Time     0   1   2   3   4   5   6
//         0.  0.  02  ..  44  4.  46
//         ..  ..  22  .2  42  ..  66
// Obviously time 1 is identical to time 5, and also 2 with 6 ... this tells us the board has a periodic pattern with 4 second cycle!
// However, only calculating the first 4 seconds is not enough. Consider the following board:
// Time     0   1   2   3   4   5   6   7   8
//         0.  0.  02  ..  44  44  44  ..  88
//         .0  .0  20  ..  44  44  44  ..  88
// It tells us the board will fall in a loop eventually with 4 second cycle, though not necessarily from second 1.
// All we need to do is to find a time when the board is identical with 4 seconds ago.
// In fact, provably, it will fall in a loop in the first 10 seconds.

int main() {
    int m,n,t;
    scanf("%d %d %d", &n, &m, &t);
    char board[10][n][m+1];
    for (int i=0;i<n;i++)
        scanf("%s", board[1][i]);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (board[1][i][j] == 'O')
                board[1][i][j] = '0';
    for (int tt=2; tt<10; tt++)
    {
        if (tt % 2 == 0)
        {
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (board[tt-1][i][j] == '.')
                        board[tt][i][j] = '0' + tt;
                    else
                        board[tt][i][j] = board[tt-1][i][j];
        }
        else if (tt >= 3)
        {
            int remove[n][m];
            memset(remove, 0, sizeof(remove));
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    board[tt][i][j] = board[tt-1][i][j];
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (board[tt][i][j] + 3 == '0' + tt)
                    {
                        remove[i][j] = 1;
                        if (i>0)
                            remove[i-1][j] = 1;
                        if (i<n-1)
                            remove[i+1][j] = 1;
                        if (j>0)
                            remove[i][j-1] = 1;
                        if (j<m-1)
                            remove[i][j+1] = 1;
                    }
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (remove[i][j])
                        board[tt][i][j] = '.';
        }
    }
    
    int time = (t<10?t:(t-4)%4+4);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            printf("%c", board[time][i][j]=='.'?'.':'O');
        printf("\n");
    }
    
}
