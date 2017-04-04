/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/magic-square-forming
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

// Interesting question; it's not that complicated. Ask yourself: how many different magic squares are there?
// Hundreds? Thousands? No... just 8. For a detailed explaination see:
// https://mindyourdecisions.com/blog/2015/11/08/how-many-3x3-magic-squares-are-there-sunday-puzzle/
// Therefore, we can simply compare the input with all 8 magic squares, and output the minimal cost.
// Considering all 8 magic squares are a rotation or reflections of a base solution,
// We only input one base solution, then rotate three times, and do a flip for each.

vector<string> rotate(vector<string> sol, int times)
{
    while (times--)
    {
        int tmp = sol[0][2];
        sol[0][2] = sol[0][0];
        sol[0][0] = sol[2][0];
        sol[2][0] = sol[2][2];
        sol[2][2] = tmp;
        tmp = sol[0][1];
        sol[0][1] = sol[1][0];
        sol[1][0] = sol[2][1];
        sol[2][1] = sol[1][2];
        sol[1][2] = tmp;
    }
    return sol;
}

vector<string> flip(vector<string> sol)
{
    vector<string> newsol;
    newsol.push_back(sol[2]);
    newsol.push_back(sol[1]);
    newsol.push_back(sol[0]);
    return newsol;
}

int main() {
    vector<vector<string> > solutions;
    vector<string> base_sol;
    base_sol.push_back("492");
    base_sol.push_back("357");
    base_sol.push_back("816");
    solutions.push_back(base_sol);
    for (int i=1; i<=3; i++)
        solutions.push_back(rotate(base_sol, i));
    for (int i=0; i<4; i++)
        solutions.push_back(flip(solutions[i]));
    // Initialization finished
    
    int c[3][3], mincost = 1000;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            scanf("%d", &c[i][j]);
    for (int s=0; s<8; s++)
    {
        int cost = 0;
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                cost += abs(c[i][j] - (solutions[s][i][j] - '0'));
        if (cost < mincost)
            mincost = cost;
    }
    printf("%d\n", mincost);
}
