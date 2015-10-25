#!/usr/bin/env python

from __future__ import division
import sys
import math

counts = map(int, raw_input().split())
color_index = int(raw_input())

prob = math.floor(counts[color_index - 1] / sum(counts) * 100) / 100

sys.stdout.write('{0:.2f}'.format(prob))
