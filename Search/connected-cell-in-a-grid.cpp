/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/connected-cell-in-a-grid
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
// Can be done in a variety of ways, DFS, BFS or even Union-Find set. 
// We will use the very basic DFS.
// Note to check if a node is within the range of the grid (you shouldn't check if the value of visited[-1][0], etc.)
struct point {
    int x;
    int y;
};
int deltax[] = {0, 0,  1, -1, -1, -1, 1, 1};
int deltay[] = {1, -1, 0, 0,  -1, 1, -1, 1};
int main()
{
    int m,n;
    int g[11][11];
    scanf("%d %d",&m,&n);
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    int visited[11][11];
    memset(visited,0,sizeof(visited));
    int maxi = -1;
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
        {
            if (visited[i][j] == 0 && g[i][j] == 1)
            {
                int cnt = 1;
                visited[i][j] = 1;
                point q[200];
                q[0] = (point){i,j};
                int be = 0, ed = 1;
                while (be < ed)
                {
                    int x = q[be].x;
                    int y = q[be].y;
                    for (int dir = 0; dir < 8; dir ++)
                        if (x+deltax[dir] >= 0 && x+deltax[dir] < m && y+deltay[dir] >= 0 && y+deltay[dir] < n &&
                            visited[x+deltax[dir]][y+deltay[dir]] == 0 && g[x+deltax[dir]][y+deltay[dir]] == 1)
                        {
                            q[ed++] = (point){x+deltax[dir],y+deltay[dir]};
                            visited[x+deltax[dir]][y+deltay[dir]] = 1;
                            cnt++;
                        }
                    be ++;
                }
                if (cnt > maxi)
                    maxi = cnt;
            }
        }
    printf("%d\n",maxi);
}
