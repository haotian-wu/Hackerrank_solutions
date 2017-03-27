/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/gridland-metro
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
#include <climits>
#include <algorithm>
using namespace std;

// Segment tree!
// Discretize needed.

int data[100001];
int sum[100001*4];
int minv[100001*4];
int lazy[100001*4];
void push_up(int root)
{
  sum[root] = sum[root<<1] + sum[root<<1|1];
  minv[root] = min(minv[root<<1], minv[root<<1|1]);
}

void push_down(int root, int l, int r)
{
  int len = r-l+1;
  sum[root<<1] = lazy[root]*(len - (len>>1));
  minv[root<<1] = lazy[root];
  lazy[root<<1] = lazy[root];
  sum[root<<1|1] = lazy[root]*(len>>1);
  minv[root<<1|1] = lazy[root];
  lazy[root<<1|1] = lazy[root];
  lazy[root] = 0;
}

void build(int root, int l, int r)
{
  lazy[root] = 0;
  if (l==r)
  {
    // Change here for initial value
    //sum[root] = data[l];
    //minv[root] = data[l];
    sum[root] = 2;
    minv[root] = 2;
    return;
  }
  int m = (l+r) >> 1;
  build(root<<1, l, m);
  build(root<<1|1, m+1, r);
  push_up(root);
}

void set_value_seg(int ul, int ur, int value, int root, int l, int r)
{
  if (ul <= l && ur >= r)
  {
    sum[root] = value * (r-l+1);
    minv[root] = value;
    lazy[root] = value;
    return;
  }
  if (lazy[root])
    push_down(root, l, r);
  int m = (l+r)>>1;
  if (ul<=m)
    set_value_seg(ul, ur, value, root<<1, l, m);
  if (ur>=m+1)
    set_value_seg(ul, ur, value, root<<1|1, m+1, r);
  push_up(root);
}

int query_sum(int ql, int qr, int root, int l, int r)
{
  if (ql <= l && qr >= r)
    return sum[root];
  if (lazy[root])
    push_down(root, l, r);
  int m = (l+r) >> 1, ret = 0;
  if (ql <= m)
    ret += query_sum(ql, qr, root<<1, l, m);
  if (qr >= m+1)
    ret += query_sum(ql, qr, root<<1|1, m+1, r);
  return ret;
}

int query_min(int ql, int qr, int root, int l, int r)
{
  if (ql <= l && qr >= r)
    return minv[root];
  if (lazy[root])
    push_down(root, l, r);
  int m = (l+r) >> 1, ret = INT_MAX;
  if (ql <= m)
    ret = min(ret, query_min(ql, qr, root<<1, l, m));
  if (qr >= m+1)
    ret = min(ret, query_min(ql, qr, root<<1|1, m+1, r));
  return ret;
}


int main() {
    int n,m,k; 
    scanf("%d %d %d",&n,&m,&k);
    map<int,vector<pair<int,int> > > mp;
    for (int i=0; i<k; i++)
    {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        mp[a].push_back(make_pair(b,c));
    }
    long long sum_occupied;
    for (map<int,vector<pair<int,int> > > :: iterator j = mp.begin(); j!=mp.end(); j++)
    {
        vector<pair<int,int> > &v = j->second;
        map<int,int> disc; //discretize
        for (int i=0; i<v.size(); i++)
        {
            disc[v[i].first] = 1;
            disc[v[i].first-1] = 1;
            disc[v[i].second] = 1;
            disc[v[i].second+1] = 1;
        }
        int dedisc[100000], desize=1;
        for (map<int,int> :: iterator j = disc.begin(); j!=disc.end(); j++)
        {
            j->second = desize;
            dedisc[desize++] = j->first;
        }
        desize--;
        build(1,1,desize);
        for (int i=0; i<v.size(); i++)
            set_value_seg(disc[v[i].first], disc[v[i].second], 1, 1,1,desize);
        int l=0, ans[100000];
        for (int i=1; i<=desize; i++)
            ans[i] = query_sum(i,i,1,1,desize);
        for (int i=1; i<=desize; i++)
        {
            if (ans[i] == 1)
            {
                if (l == 0)
                    l = i;
            }
            else if (l != 0)
            {
                sum_occupied += (dedisc[i-1] - dedisc[l] + 1);
                l = 0;
            }
        }
    }
    printf("%lld\n", (long long)n * m - sum_occupied);
}
