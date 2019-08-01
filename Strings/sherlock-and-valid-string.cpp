/*******************************************************
 * Copyright (C) 2019 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int m[26] = {0};
    for (char c : s)
        m[c-'a'] ++;
    map<int,int> mp;
    for (int i=0; i<26; i++)
        if (m[i] != 0)
            mp[m[i]] ++;
    bool valid = true;
    if (mp.size() >= 3)
        valid = false;
    else if (mp.size() == 2)
    {
        auto it1 = mp.begin(), it2 = mp.begin();
        it2++;
        if (! (it1->first == 1 && it1->second == 1 || it1->first+1 == it2->first && it2->second == 1) )
            valid = false;
    }
    return valid? "YES":"NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
