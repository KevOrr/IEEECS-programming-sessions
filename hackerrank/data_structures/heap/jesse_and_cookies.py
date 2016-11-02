#!/usr/bin/env python3

import heapq

n, k = map(int, input().split())

cookies = []
for cookie in map(int, input().split()):
    heapq.heappush(cookies, cookie)

num_mixes = 0

while any(cookie < k for cookie in cookies) and len(cookies) > 1:
    new_cookie = heapq.heappop(cookies) + 2 * heapq.heappop(cookies)
    heapq.heappush(cookies, new_cookie)
    num_mixes += 1

if len(cookies) <= 1 and sum(cookies) < k:
    print(-1)
else:
    print(num_mixes)
