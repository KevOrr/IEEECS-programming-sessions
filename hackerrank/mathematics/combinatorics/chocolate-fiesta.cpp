#include <vector>
#include <iostream>
#include <cstdint>

uint32_t MOD = 1000000007;

int main() {
    uint32_t N;
    std::cin >> N;

    std::vector<uint32_t> num_subsets_even(N);
    std::vector<uint32_t> num_subsets_odd(N);

    uint32_t next_num;
    std::cin >> next_num;
    uint32_t next_num_evens = next_num % 2 == 0;
    uint32_t next_num_odds = next_num % 2 == 1;

    for (uint32_t i=1; i<N; i++) {
        uint32_t last_num_odds = next_num_odds;
        uint32_t last_num_evens = next_num_evens;
        std::cin >> next_num;

        if (next_num % 2 == 1) {
            next_num_evens = (last_num_odds + last_num_evens) % MOD;
            next_num_odds = (next_num_evens + 1) % MOD;
        } else {
            next_num_evens = (2*last_num_evens + 1) % MOD;
            next_num_odds = 2*last_num_odds % MOD;
        }
    }

    std::cout << next_num_evens << std::endl;

    return 0;
}
