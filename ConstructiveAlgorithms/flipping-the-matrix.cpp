/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/flipping-the-matrix
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

// Look at the example in the problem description. There's a 56 in the final answer. 
// Can we do better? There's a 112 in the upper right of the matrix. Can we use it to substitute 56?
// The answer is absolutely NO. Number 56 is located here:
// ....
// X...
// ....
// ....
// Flipping the row will result in:  | Flipping the column:  | Flipping row then column:
//                             ....  |                 ....  |                      ....
//                             ...X  |                 ....  |                      ....
//                             ....  |                 X...  |                      ...X
//                             ....  |                 ....  |                      ....
// These are all the places that number 56 can go. Vice versa, these are the only numbers that can be moved to the place 56 resides.
// We call this a "group". Since we can only move numbers within a group, and 56 is the largest in this group,
// it's quite reasonable that we pick 56.
// The entire matrix can be splitted into n*n groups, and all we need to do is to find the largest number within each group, and sum them up;
// given the fact that we can move the greatest number in the group to the upper left matrix, 
// without interfering other numbers already in the upper left matrix.
// The groups look like: (the same letter means they're in the same group)
// ABBA
// CDDC
// CDDC
// ABBA
// In the following matrix, if we want to move C to place X, without moving A, B and D:
// AB..    AB..    .B..    .B..    AB..
// XD.C => XD.. => .D.. => .D.. => CD..
// ....    ...C    X..C    C..X    ...X
// ....    ....    A...    A...    ....

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int n;
        int mat[256][256];
        scanf("%d", &n);
        for (int i=0; i<2*n; i++)
            for (int j=0; j<2*n; j++)
                scanf("%d", &mat[i][j]);
        int result = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                int maxv = mat[i][j];
                if (mat[2*n-1-i][j] > maxv)
                    maxv = mat[2*n-1-i][j];
                if (mat[i][2*n-1-j] > maxv)
                    maxv = mat[i][2*n-1-j];
                if (mat[2*n-1-i][2*n-1-j] > maxv)
                    maxv = mat[2*n-1-i][2*n-1-j];
                result += maxv;
            }
        printf("%d\n", result);
    }
    
}
