/*******************************************************
 * Copyright (C) 2019 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/strong-password/problem
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <bits/stdc++.h>

using namespace std;

bool contains(string password, string pattern)
{
    for (char p : password)
        for (char c : pattern)
            if (p == c)
                return true;
    return false;
}
// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    int charneeded = 0;
    if (!contains(password, numbers)) charneeded++;
    if (!contains(password, lower_case)) charneeded++;
    if (!contains(password, upper_case)) charneeded++;
    if (!contains(password, special_characters)) charneeded++;
    return max(charneeded, 6-n);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
