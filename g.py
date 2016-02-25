#!/usr/bin/env python
#Author: Kevinorr <kevinorr@mail.usf.edu>

import sys

binstring = raw_input()

for i in range(len(binstring) / 7):
    n = int(binstring[7*i:7*i+7], 2)
    sys.stdout.write(chr(n))
