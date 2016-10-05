#!/usr/bin/env python

import sys

phrase = raw_input()

sys.stdout.write(str(int(phrase == ''.join(reversed(phrase)))))
