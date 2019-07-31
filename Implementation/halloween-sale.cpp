/*******************************************************
 * Copyright (C) 2019 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/halloween-sale/problem
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
 #include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the howManyGames function below.
int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    int cnt = 0;
    int cur_price = p;
    while (s >= cur_price) 
    {
        s -= cur_price;
        cnt ++;
        cur_price -= d;
        if (cur_price < m)
            cur_price = m;
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string pdms_temp;
    getline(cin, pdms_temp);

    vector<string> pdms = split_string(pdms_temp);

    int p = stoi(pdms[0]);

    int d = stoi(pdms[1]);

    int m = stoi(pdms[2]);

    int s = stoi(pdms[3]);

    int answer = howManyGames(p, d, m, s);

    fout << answer << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
