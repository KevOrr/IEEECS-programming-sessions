#!/usr/bin/env python
import sys

nums = map(int, raw_input().split())

hailo = sorted(n for n in nums if n%2) #odds
hailo += sorted((n for n in nums if not n%2), reverse=True) #reversed evens

sys.stdout.write(' '.join(map(str, hailo)))
