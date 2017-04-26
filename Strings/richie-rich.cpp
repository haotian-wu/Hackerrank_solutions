/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/richie-rich
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
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The algorithm is:
// 1. Count how many chars we need to change to make it a palindrome. Say it's d.
// 2. Compare d with k. If d>k, then it's impossible. Output -1.
// 3. Now we have d<=k. Go ahead and make it palindrome by changing the smaller char to the larger one. We have k-d steps remaining.
// While we modifying the string, we keep track of which char is changed and which is not. This will be helpful in the future.
// 4. Use the remaining moves to change chars to 9. 
// Obviously we want to change the first and last chars to 9, then second and second but last... If it's already 9, ignore it.
// Changing first and last chars to 9 will take 2 moves... or maybe less?
// Well, if we changed one of the chars in step 3, then we only need one move here to change both to 9.
// This is because we no longer need to match both chars first, then change both to 9. We can change them to 9 directly.
// This takes 2 moves, and since we counted 1 move in step 3, we will need 1 extra move here.
// If they are originally matched (we didn't change them in step 3), we will need 2 extra moves here.
// 5. Lastly, deal with the case that n is odd. If we have remaining steps, change the middle char to 9.

int main() {
    int n, k;
    string str;
    cin >> n >> k >> str;
    bool changed[n];
    int diff_cnt=0;
    for (int i=0; i<n/2; i++)
        if (str[i] != str[n-1-i])
            diff_cnt++;
    if (diff_cnt > k)
        cout << -1 << endl;
    else
    {
        for (int i=0; i<n/2; i++)
            if (str[i] != str[n-1-i])
            {
                char tmp = max(str[i], str[n-1-i]);
                str[i] = str[n-1-i] = tmp;
                changed[i] = true;
            }
            else
                changed[i] = false;
        k -= diff_cnt;
        for (int i=0; i<n/2 && k>0; i++)
            if (str[i] != '9')
            {
                if (changed[i])
                {
                    str[i] = str[n-1-i] = '9';
                    k--;
                }
                else if (k >= 2)
                {
                    str[i] = str[n-1-i] = '9';
                    k-=2;
                }
            }
        if (k>0)
            str[n/2] = '9';
        cout << str << endl;
    }
}
