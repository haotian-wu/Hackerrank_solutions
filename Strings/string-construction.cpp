/*******************************************************
 * Copyright (C) 2019 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/string-construction/problem
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <bits/stdc++.h>

using namespace std;

// Since appending a substring of p is at no charge, the best strategy
// is to always pick a substring of len=1. If we are about to append
// a substring with len=2 for example, we can instead append two substrings,
// each has len=1. Either way, it doesn't cost us anything.
// So the problem becomes: if a char is going to be appended in p and it
// never showed up before in p, cost 1 dollar; if it exists in p already, 
// we can append it for free. So checking how many distinct chars are in p
// will suffice.
// Complete the stringConstruction function below.
int stringConstruction(string s) {
    bool m[26] = {0};
    for (char c : s)
        m[c-'a'] = 1;
    int res = 0;
    for (int i=0; i<26; i++)
        res += m[i];
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
