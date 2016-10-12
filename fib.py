#!/usr/bin/env python3
# For https://www.reddit.com/r/dailyprogrammer/comments/5196fi/20160905_challenge_282_easy_unusual_bases/


import functools

def cache(func):
    """@cache

    Caches results for functions whose domain is the nonnegative integers (whole numbers)"""
    
    results = []

    @functools.wraps(func)
    def wrapper(n):
        if len(results) <= n:
            for i in range(len(results), n+1):
                results.append(func(i))
        return results[n]

    wrapper._results = results
    return wrapper

@cache
def fib(n):
    return n if n in (0, 1) else fib(n-1) + fib(n-2)

@cache
def fib2dec(fib_num):
    '''fib2dec(fib_num) => dec_num

    Accepts a number that, in binary, encodes the sum of a subset of the
    Fibonanci sequence'''

    fib_string = bin(fib_num)[2:]
    digits = reversed([int(digit) for digit in fib_string])
    return sum(fib(n+1) * digit for n,digit in enumerate(digits))


def dec2fib(dec_num):
    '''dec2fib(dec_num) => fib_num

    Accepts a decimal number to be converted to a binary number that encodes
    the sum of a subset of the Fibonanxi sequence'''

    dec_string = str(dec_num)

    guess = 1
    while fib2dec(int(bin(guess)[2:], 2)) < dec_num:
        guess += 1
    return bin(guess)[2:]

