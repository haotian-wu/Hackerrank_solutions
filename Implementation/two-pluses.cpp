/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/two-pluses
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
#define INF 1000000
using namespace std;

// Brute force search. 1. Pick a central grid for plus #1; 2. traverse all possible sizes;
// 3. pick a central grid for plus #2 in the remaining grids; 4. expand plus #2 to its maximum possible size.
// The only thing we need to be aware of, is that in step 2, 
// we can't pick the "plus"'s size greedily. We have to traverse all possiblities.
// For example, we have the following grid: (. for bad grid)
// ..G..G..
// ..G..G..
// GGGGGGGG
// ..G..G..
// ..G..G..
// We can see that if we pick plus #1's size greedily, it has a length of 5 and area of 9; 
// however plus #2 only have length 1, size 1. This yields 9 in the final result.
// Instead, we can let both pluses' length to be 3, which is an area of 5, and their product is 25.

int main() {
    int n, m;
    cin >> n >> m;
    string grid[15];
    for (int i=0; i<n; i++)
        cin >> grid[i];
    int maxp = 0;
    // Traverse the first plus
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (grid[i][j] != 'G')
                continue;
            // Traverse all possible lengths
            for (int k=0; i-k>=0 && grid[i-k][j]=='G' && j-k>=0 && grid[i][j-k]=='G' && 
                          i+k<n && grid[i+k][j]=='G' && j+k<m && grid[i][j+k]=='G' ; k++)
            {
                grid[i-k][j] = grid[i][j-k] = grid[i+k][j] = grid[i][j+k] = 'T'; // A temporary mark for occupied grids
                // Traverse the second plus
                for (int p=0; p<n; p++)
                {
                    for (int q=0; q<m; q++)
                    {
                        if (grid[p][q] != 'G')
                            continue;
                        // Find the maximum size of second plus
                        for (int r=0; p-r>=0 && grid[p-r][q]=='G' && q-r>=0 && grid[p][q-r]=='G' && 
                                      p+r<n && grid[p+r][q]=='G' && q+r<m && grid[p][q+r]=='G' ; r++)
                            if ((4*k+1) * (4*r+1) > maxp)
                                maxp = (4*k+1) * (4*r+1);
                    }
                }
            }
            // Reset all 'T' Grids to 'G'
            for (int p=0; p<n; p++)
                for (int q=0; q<m; q++)
                    if (grid[p][q] == 'T')
                        grid[p][q] = 'G';
        }
    }
    printf("%d\n", maxp);
}
