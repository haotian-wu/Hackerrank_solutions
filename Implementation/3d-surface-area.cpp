/*******************************************************
 * Copyright (C) 2019 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/3d-surface-area/problem
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// We can compute the surface area direction by direction (front, back, left, right, up&down.)
// For front direction, we compute from the frontmost row, and each block will contribute
// A[i][j] - A[i-1][j] front direction surface, if A[i][j] > A[i-1][j]. 
// Do the same thing for back, left & right.
// Then for up & down, simply check how many A[i][j] is non-zero, and they contribute
// twice as many to the total surface (twice because up & down).
// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {
    int totalSurface = 0, n = A.size(), m = A[0].size();
    // Front
    vector<int> pre(m,0);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (pre[j] < A[i][j])
                totalSurface += A[i][j] - pre[j];
            pre[j] = A[i][j];
        }
    }
    // Back
    for (int i=0; i<m; i++)
        pre[i] = 0;
    for (int i=n-1; i>=0; i--)
    {
        for (int j=0; j<m; j++)
        {
            if (pre[j] < A[i][j])
                totalSurface += A[i][j] - pre[j];
            pre[j] = A[i][j];
        }
    }
    // Left
    pre.resize(n);
    for (int i=0; i<n; i++)
        pre[i] = 0;
    for (int j=0; j<m; j++)
    {
        for (int i=0; i<n; i++)
        {
            if (pre[i] < A[i][j])
                totalSurface += A[i][j] - pre[i];
            pre[i] = A[i][j];
        }
    }
    // Right
    for (int i=0; i<n; i++)
        pre[i] = 0;
    for (int j=m-1; j>=0; j--)
    {
        for (int i=0; i<n; i++)
        {
            if (pre[i] < A[i][j])
                totalSurface += A[i][j] - pre[i];
            pre[i] = A[i][j];
        }
    }
    // Up&Bottom
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (A[i][j] > 0)
                totalSurface += 2;
    return totalSurface;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

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
