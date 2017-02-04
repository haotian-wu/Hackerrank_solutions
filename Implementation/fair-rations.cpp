/*******************************************************
 * Copyright (C) 2017 Haotian Wu
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/fair-rations
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
#define INF 1000000
using namespace std;

// In this problem, we call the number of people that holding odd number of breads "odd count".
// we call the array "odd array" if the odd count is ODD; and we call it "even array" if the odd count is EVEN.
// We can first observe that the operation that distribute bread doesn't change the odd-even nature (we call it parity) of odd count of the array.
// This is because, when you distribute bread, there're only three possibilities on the two people you give bread to:
// 1. Odd Odd -> Even Even, then the odd count reduced by 2.
// 2. Odd Even -> Even Odd (Or Even Odd -> Odd Even), the odd count doesn't change.
// 3. Even Even -> Odd Odd, the odd count is increased by 2.
// +2, +0 or -2 will not change the parity of a number. 
// So if an array is odd array, it will remain an odd array no matter how many operations we apply to it.
// Considering our final goal, all numbers being even, is an even array, we should output "NO" if the initial array is odd.
// If it's even, we need to find a way to minimize the bread we distribute.
// Consider the following array: 1 0 0 0 1 (here 0 means even and 1 means odd)
// Giving bread to the first two people will get 0 1 0 0 1, and then giving bread to the second and third we get 0 0 1 0 1.
// Next we get 0 0 0 1 1, and finally we get 0 0 0 0 0. That being said we need (the difference of index) moves to eliminate two odd people.
// What about 1 0 1 1 0 0 1 ? Should we give bread to the third and fourth people to get 1 0 0 0 0 0 1?
// Of course not. Considering we are removing 1's in pairs, we should remove the first two 1's in the array, then next two, then next two...
// So we can use two steps to turn 1 0 1 to 0 0 0, and three steps to turn 1 0 0 1 to 0 0 0 0.

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int cnt = 0, preidx = -1;
    for (int i=0; i<n; i++)
    {
        if (arr[i] % 2 == 1)
        {
            if (preidx != -1)
            {
                cnt += i - preidx;
                preidx = -1;
            }
            else
                preidx = i;
        }
    }
    if (preidx == -1)
        printf("%d\n", cnt*2);
    else
        printf("NO\n");
}
