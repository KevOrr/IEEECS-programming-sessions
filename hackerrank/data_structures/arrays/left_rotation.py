#!/usr/bin/env python2

n, d = map(int, raw_input().split())

if n == d:
    # one full revolution = back to where we started
    print raw_input()

array = map(int, raw_input().split())

rotated = array[d:] + array[:d]
print ' '.join(map(str, rotated))
