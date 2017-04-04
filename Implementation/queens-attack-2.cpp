/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/queens-attack-2
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// First we should notice building the entire chessboard in memory is not possible, because 10^5 * 10^5 is huge.
// There're many ways of solving this problem. For example, 
// (1) iterate all obstacles and see if it's on the way of the queen. 
// Find the closest obstacle to the queen on all 8 directions. (O(k))
// (2) save all obstacles in a map or hashmap. 
// Simulate the movement of the queen, and check if we're running into an obstacle. (O(n+k))
// We will implement method 2.

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    pair<int,int> start;
    int x, y;
    scanf("%d %d", &x, &y);
    start = make_pair(x,y);
    set<pair<int,int> > ob;
    for (int i=0; i<k; i++)
    {
        scanf("%d %d", &x, &y);
        ob.insert(make_pair(x,y));
    }
    int totalcnt = 0;
    for (int dir=0; dir<8; dir++)
    {
        pair<int,int> cur = start;
        while(1)
        {
            cur.first += dx[dir];
            cur.second += dy[dir];
            if (cur.first >= 1 && cur.first <= n && cur.second >= 1 && cur.second <= n && (!ob.count(cur)) )
                totalcnt ++;
            else 
                break;
        }
    }
    printf("%d\n", totalcnt);
}
