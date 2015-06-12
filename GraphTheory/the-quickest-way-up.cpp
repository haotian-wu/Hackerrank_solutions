/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/the-quickest-way-up
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
// Let's first create a graph, then run BFS on it.
// The graph is a directed graph.
// Every square is connected to its next 6 squares, unless that square is a starting point of a ladder of a snake.
// If there is a ladder from 12 to 98, when we roll a 2 at square 10, we reach 98. So 10 is connected to 98, instead of 12, because we cannot stop at 12. This seems not important, but actually it is very inportant. 
// Consider a square, whose all next 7 squares are ladders. We cannot reach the 7th ladder. However, if you don't remove the link (from 10 to 12, as the example above), there can be a problem as you can reach the 7th ladder.
int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
        int dest[101];
        for (int i=1;i<=100;i++)
            dest[i] = i;
        int l,s; // ladder, snake
        int a,b; //TEMP
        scanf("%d",&l);
        while (l--)
        {
            scanf("%d %d",&a,&b);
            dest[a] = b;
        }
        scanf("%d",&s);
        while (s--)
        {
            scanf("%d %d",&a,&b);
            dest[a] = b;
        }
        vector<int> adj_lst[101];
        for (int i=1;i<=100;i++)
            for (int j=1;j<=6;j++)
                if (i+j<=100)
                    adj_lst[i].push_back(dest[i+j]);
        int dis[101];
        memset(dis,-1,sizeof(dis)); // distant from 1. -1 denotes unvisited.
        dis[1] = 0;
        int fr = 0, ed = 1;
        int q[200] = {1};
        while (fr < ed)
        {
            int cur = q[fr];
            int l = adj_lst[cur].size();
            for (int i=0;i<l;i++)
                if (dis[adj_lst[cur][i]]==-1)
                {
                    q[ed++] = adj_lst[cur][i];
                    dis[adj_lst[cur][i]] = dis[cur] + 1;
                }
            fr++;
        }
        printf("%d\n",dis[100]); // I can simply write this, because dis[100] is initiallized to -1. In the case no solution exists, -1 is printed.
    }
}
