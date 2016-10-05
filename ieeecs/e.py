#!/usr/bin/env python
# 

import sys

n = int(raw_input())

def gen_cause_why_not(n):
    a, b = 0, 1
    for i in range(n):
        yield a
        a, b = b, a + b

sys.stdout.write(' '.join(map(str, gen_cause_why_not(n))))
