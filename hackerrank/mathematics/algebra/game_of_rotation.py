#!/usr/bin/env python2

import itertools as it

n_blocks = int(raw_input())
block_values = map(int, raw_input().split())

total = sum(block_values)
partial_sums = [sum(i*block_value for i,block_value in it.izip(xrange(1, n_blocks+1), block_values))]

for i in xrange(1, n_blocks):
    next_sum = partial_sums[-1]
    next_sum += n_blocks * block_values[i - 1]
    next_sum -= total
    partial_sums.append(next_sum)

print max(partial_sums)
