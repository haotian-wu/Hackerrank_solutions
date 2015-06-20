/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 * 
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/the-time-in-words
 * 
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> name {"zero", "one","two","three","four","five","six","seven","eight","nine","ten",
                     "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
string num2str(int x)
{
    // We will deal with the special cases later.
    if (x<=20)
        return name[x];
    else 
        return name[20]+" "+name[x-20];
}
int main() {
    // What on earth make you think this is "medium" level?!
    int h,m;
    scanf("%d %d",&h,&m);
    if (m==0)
        cout << num2str(h) << " o' clock" << endl;
    else if (m==15)
        cout << "quarter past " << num2str(h) << endl;
    else if (m==30)
        cout << "half past " << num2str(h) << endl;
    else if (m==45)
        cout << "quarter to " << num2str(h%12+1) << endl; //%12 deal with 12pm -> 1pm
    else if (m<30)
        cout << num2str(m) << (m>1?" minutes":" minute") << " past " << num2str(h) << endl;
    else
        cout << num2str(60-m) << ((60-m)>1?" minutes":" minute") << " to " << num2str(h%12+1) << endl;
    return 0;
}
