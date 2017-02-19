#include <stdint.h>
#include <inttypes.h>

#include <iostream>
#include <vector>
#include <stack>

class node {
public:
    std::vector<std::pair<uint32_t, uint32_t> > neighbors; // (neighbor_index, num_neighbors)
    bool explored = false;
};

void set_weights(std::vector<node> &nodes) {
    std::stack<uint32_t> s;
    s.push(0);
    while (s.size()) {
        uint32_t i = s.top();
        node n = nodes[i];
        if (n.explored) {
            bool all_neighbors_expanded = true;
            for (auto it = n.neighbors.begin(), end = n.neighbors.end(); it != end; ++it)
                all_neighbors_expanded = all_neighbors_expanded && nodes[it->first].explored;
            if (all_neighbors_expanded) {
                
                for ()
            }
        }
    }
}

int main() {
    int n_games;
    std::cin >> n_games;

    for (; n_games > 0; --n_games) {
        uint32_t n;
        std::cin >> n;
        std::vector<node> nodes(n);

        for (uint32_t i=0; i<n-1; ++i) {
            uint32_t u, v;
            std::cin >> u >> v;

            nodes[u].neighbors.push_back(std::pair<uint32_t, uint32_t>{v, 0});
            nodes[v].neighbors.push_back(std::pair<uint32_t, uint32_t>{u, 0});
        }

        set_weights(nodes);
    }
}
