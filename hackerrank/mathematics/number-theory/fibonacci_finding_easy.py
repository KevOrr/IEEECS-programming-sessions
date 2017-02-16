#!/usr/bin/env python3

import functools
import sys

def fib(n):
    cache = fib.cache
    if len(cache) <= n:
        a, b = cache[-2:]
        for _ in range(n-len(cache)+1):
            a, b = b, a+b
            cache.append(b)
        return cache[n]

fib.cache = [0, 1]

def fib_kinda(a, b, n):
    return fib(n)*b + fib(n-1)*a

if __name__ == '__main__':
    with open('input01.txt') as f:
        for _ in range(int(f.readline().strip())):
            a, b, n = map(int, f.readline().strip().split())
            print(a, b, n, end=': ')
            print(fib_kinda(a, b, n))
