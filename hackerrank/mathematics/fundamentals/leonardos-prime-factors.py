#!/usr/bin/env python3

# Sieve of Eratosthenes
# Code by David Eppstein, UC Irvine, 28 Feb 2002
# http://code.activestate.com/recipes/117119/
# Begin the Holy Implementation of the Sieve:
def gen_primes():
    D = {}
    q = 2
    while True:
        if q not in D:
            yield q
            D[q * q] = [q]
        else:
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]
        q += 1

prime_gen = gen_primes()
primes = [next(prime_gen)]

for _ in range(int(input())):
    composite = int(input())
    prime_prod = 2
    num_primes = 0

    while prime_prod <= composite:
        num_primes += 1

        if len(primes) <= num_primes:
            primes.append(next(prime_gen))

        prime_prod *= primes[num_primes]

    print(num_primes)
