/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/utopian-tree
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <iostream>
using namespace std;

int height(int n) {
    int h = 1;
    for (int i=1;i<=n;i++)
        if (i%2==1)
            h*=2;
        else
            h++;
    return h;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
