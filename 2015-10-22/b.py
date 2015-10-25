#!/usr/bin/env python

import sys

sides = raw_input().split()

if sides[0] == '_':
    third = (float(sides[2])**2 - float(sides[1])**2)**0.5
elif sides[1] == '_':
    third = (float(sides[2])**2 - float(sides[0])**2)**0.5
elif sides[2] == '_':
    third = (float(sides[0])**2 + float(sides[1])**2)**0.5

sys.stdout.write('{0:.3f}'.format(third))
