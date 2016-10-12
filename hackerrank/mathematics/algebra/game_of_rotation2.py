#!/usr/bin/env python2

import itertools as it

n_blocks = int(raw_input())
block_values = map(int, raw_input().split())

partial_sums = []

for i in xrange(n_blocks):
    rotated = block_values[i:] + block_values[:i]
    partial_sums.append(sum([i*val for i,val in it.izip(xrange(1, n_blocks+n_blocks), rotated)]))

print max(partial_sums)
