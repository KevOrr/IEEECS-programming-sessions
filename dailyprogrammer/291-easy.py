#!/usr/bin/env python3

# [2016-11-07] Challenge #291 [Easy] Goldilocks' Bear Necessities
# https://redd.it/5bn0b7

import sys

min_weight, max_temp = map(int, input().split())
seats = [tuple(map(int, line.split())) for line in sys.stdin]

print(' '.join(str(i+1) for i,seat in enumerate(seats) if seat[0] >= min_weight and seat[1] <= max_temp))

