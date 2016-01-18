#########################################################
# Copyright (C) 2015 Haotian Wu
#
# This file is the solution to the question:
# https://www.hackerrank.com/challenges/xor-and-sum
#
# Redistribution and use in source and binary forms are permitted.
#########################################################

# Can't find a good DP algorithm here. Tell me if you find one.
a = raw_input()
b = raw_input()
a10 = int(a,2)
b10 = int(b,2)
sum = 0
for i in range(0,314160):
    sum += (a10 ^ (b10 << i))
print sum % 1000000007
