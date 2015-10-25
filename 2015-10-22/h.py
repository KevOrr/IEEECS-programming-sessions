#!/usr/bin/env python
#Author: Kevinorr <kevinorr@mail.usf.edu>

from __future__ import division
import math, sys

def binom_pdf(p, n, k):
    comb = math.factorial(n) / (math.factorial(k) * math.factorial(n - k))
    return comb * p**k * (1-p)**(n-k)

outstr = ''

for i in range(int(raw_input())):
    flips, max_heads = map(int, raw_input().split())
    prob = sum(binom_pdf(0.5, flips, i) for i in range(max_heads + 1))
    outstr += '{0:.4f}'.format(prob) + '\n'

print outstr #inconsistent formatting?
