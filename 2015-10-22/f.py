#!/usr/bin/env python
#Author: Kevinorr <kevinorr@mail.usf.edu>

import sys

str1, str2 = raw_input().split()

num1 = int(''.join(reversed(str1)))
num2 = int(''.join(reversed(str2)))

sys.stdout.write(''.join(reversed(str(num1 + num2))))
