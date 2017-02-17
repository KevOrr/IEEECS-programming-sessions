#include <stdint.h>
#include <inttypes.h>

#include <map>
#include <iostream>

const uint32_t MOD = 1000000007;
std::map<uint_fast32_t, uint_fast32_t> fibs;

uint_fast32_t fib(uint_fast32_t n) {
    auto result = fibs.find(n);
    if (result == fibs.end()) {
        if (n & 1) {
            uint_fast32_t half_n = (n+1)/2;
            uint_fast32_t F_half_n = fib(half_n);
            uint_fast32_t F_half_n_m1 = fib(half_n-1);

            return fibs[n] = F_half_n*F_half_n + F_half_n_m1*F_half_n_m1;
        } else {
            uint_fast32_t half_n = n/2;
            uint_fast32_t F_half_n = fib(half_n);

            return fibs[n] = (2*fib(half_n-1) + F_half_n)*F_half_n;
        }
    }
    return result->second;
}

uint_fast32_t fib_kinda(uint_fast32_t a, uint_fast32_t b, uint_fast32_t n) {
    return b*fib(n) + a*fib(n-1);
}

int main() {
    fibs[0] = 0;
    fibs[1] = 1;

    uint_fast32_t n_tests;
    for (std::cin >> n_tests; n_tests > 0; --n_tests) {
        uint_fast32_t a, b, n;
        std::cin >> a >> b >> n;
        std::cout << fib_kinda(a, b, n) % MOD << std::endl;
    }
}
