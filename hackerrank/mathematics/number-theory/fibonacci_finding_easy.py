#!/usr/bin/env python3

import functools

# def fib_kinda(a, b, n):
#     cache = fib_kinda.cache
# 
#     def fib_kinda_actual(a, b, n):
#         if n in (0, 1):
#             return (a,b)[n]
#         return 
# 
# 
#     else:
#         if (a,b) not in cache:
#             cache[a,b] = []
#         if len(cache[a,b]) < n:
#             last = len(cache[a,b]) - 1
#             cache[a,b] += [0]*(n - len(cache[a,b]))
#             for i in range(last, n+1):
#                 fib_kinda(a, b, i)
#         return cache[(a,b,n)]
# 
# fib_kinda.cache = {}

if __name__ == '__main__':
    for _ in range(int(input())):
        a, b, n = map(int, input().split())
        x, y = a, b
        for  i in range(n):
            x, y = y, (x+y)%int(10**9+7)
        print(x)
