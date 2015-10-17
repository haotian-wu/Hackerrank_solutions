#########################################################
# Copyright (C) 2015 Haotian Wu
#
# This file is the solution to the question:
# https://www.hackerrank.com/challenges/fibonacci-modified
#
# Redistribution and use in source and binary forms are permitted.
#########################################################

# For simplexity of large number computation I'll just use Python here.
a,b,n = raw_input().split()
arr = [0 for i in range(20)]
arr[0] = int(a)
arr[1] = int(b)
n = int(n)
for i in range(2,n):
    arr[i] = arr[i-1] ** 2 + arr[i-2]
print arr[n-1]
