#!/usr/bin/env python3

import functools

def cache(func):
    results = {}

    @functools.wraps(func)
    def wrapper(*args):
        if a is None:
            
        if args not in results:
            result = results[args] = func(*args)
            return result
        else:
            return results[args]

    wrapper._results = results
    return wrapper

@cache
def fib_kinda(a, b, n):
    return (a, b)[n] if n in (0, 1) else fib_kinda(a, b, n-1) + fib_kinda(a, b, n-2)

if __name__ == '__main__':
    for _ in range(int(input())):
        a, b, n = map(int, input().split())
        for i in range(n):
            fib_kinda(a, b, i)
        print(fib_kinda(a, b, n))
