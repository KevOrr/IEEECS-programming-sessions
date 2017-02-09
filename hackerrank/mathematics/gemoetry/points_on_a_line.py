#!/usr/bin/env python3

import sys

n = int(input())
points = [list(map(int, line.split())) for line in sys.stdin.read().split('\n')]

print('YES' if any(all(point[dim] == points[0][dim] for point in points) for dim in (0,1)) else 'NO')
