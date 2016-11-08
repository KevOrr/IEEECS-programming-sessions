#!/usr/bin/env python2

# [2016-11-07] Challenge #291 [Easy] Goldilocks' Bear Necessities
# https://redd.it/5bn0b7

print ' '.join((lambda d:(str(i+1)for i,s in enumerate(d[1:])if s[0]>=d[0][0]and s[1]<=d[0][1]))([map(int,l.split())for l in __import__('sys').stdin]))

