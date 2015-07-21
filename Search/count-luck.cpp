/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/count-luck
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
// We can first BFS to find the exit, then trace back to get the path, finally count the time "magic" is needed.
// Just watch out you shouldn't check if there's a branch at the '*' point.
struct point {
    int x;
    int y;
};
int deltax[] = {0, 0,  1, -1};
int deltay[] = {1, -1, 0, 0};
int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int m,n,k;
        char mp[101][101];
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
            scanf("%s",mp[i]);
        scanf("%d",&k);
        int visited[101][101];
        memset(visited,0,sizeof(visited));
        point start;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (mp[i][j]=='M')
                {
                    start = (point){i,j};
                    goto out;
                }
        out:
        point q[10000];
        point pre[101][101];
        q[0] = start;
        visited[start.x][start.y] = 1;
        pre[start.x][start.y] = (point){-1,-1};
        int be = 0, ed = 1;
        while (be < ed)
        {
            int x = q[be].x;
            int y = q[be].y;
            if (mp[x][y] == '*')
                break;
            for (int dir = 0; dir < 4; dir ++)
                if (x+deltax[dir] >= 0 && x+deltax[dir] < n && y+deltay[dir] >= 0 && y+deltay[dir] < m &&
                    visited[x+deltax[dir]][y+deltay[dir]] == 0 && mp[x+deltax[dir]][y+deltay[dir]] != 'X')
                {
                    q[ed++] = (point){x+deltax[dir],y+deltay[dir]};
                    pre[x+deltax[dir]][y+deltay[dir]] = (point){x,y};
                    visited[x+deltax[dir]][y+deltay[dir]] = 1;
                }
            be ++;
        }
        vector<point> path;
        point curpoint = q[be];
        curpoint = pre[curpoint.x][curpoint.y];
        while (curpoint.x != -1) //Push all but the '*' point on the path into the vector.
        {
            path.push_back(curpoint);
            curpoint = pre[curpoint.x][curpoint.y];
        } 
        int len = path.size();
        memset(visited,0,sizeof(visited));
        for (int i=len-1;i>=0;i--)
        {
            int cnt = 0;
            int x = path[i].x, y = path[i].y;
            visited[x][y] = 1;
            for (int dir = 0; dir < 4; dir ++)
                if (x+deltax[dir] >= 0 && x+deltax[dir] < n && y+deltay[dir] >= 0 && y+deltay[dir] < m &&
                        visited[x+deltax[dir]][y+deltay[dir]] == 0 && mp[x+deltax[dir]][y+deltay[dir]] != 'X')
                    cnt++;
            if (cnt >= 2)
                k--;
        }
        if (k==0)
            printf("Impressed\n");
        else
            printf("Oops!\n");
        
    }
}
