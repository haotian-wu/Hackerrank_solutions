/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/drawing-book
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

// Find the turns needed (1) from the front and (2) from the back, then find the minimal.
// You may think there're too many cases to consider (from even to even, from even to odd, ...). There's not.
// We can try to find "equivalent page" for each "page" here. 
// An "equivalent page" is the page number on the left for a page when it shows up. 
// For example, page 4 and page 5 will show up together, so page 5's equivalent page is page 4; page 4's equivalent page is also page 4.
// What about page 1? Well, we can imagine there's a page 0 on its left, so page 1's equivalent page is page 0.
// What's the advantage of doing this? 
// By using equivalent page, we can consider only the case that turn from an even page a to an even page b.
// And this is fairly simple; the number of turns needed is abs(a-b)/2.
// And you may think I've complicated this problem... I'm not. Check out the code.

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    if (n%2==1)
        n--;
    if (p%2==1)
        p--;
    int turnfromstart = p/2, turnfromend = (n-p)/2;
    printf("%d\n", min(turnfromstart, turnfromend));
}
