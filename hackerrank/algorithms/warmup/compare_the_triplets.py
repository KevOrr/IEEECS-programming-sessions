#!/bin/python3

# Uber functional!

import operator as op
import itertools as it

alice = list(map(int, input().strip().split(' ')))
bob = list(map(int, input().strip().split(' ')))

print('{} {}'.format(*[sum(it.starmap(func, zip(alice, bob))) for func in (op.gt, op.lt)]))
