#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>

typedef std::pair<uint32_t, uint32_t> probability;

class node {
public:
    std::map<uint32_t, uint32_t> undirected_edges; //node_id, weight
    std::set<uint32_t> children;
    uint32_t parent;
    bool visited = false;
};

void set_weights(std::vector<node> &nodes) {
    uint32_t n = nodes.size();

    std::stack<uint32_t> s;
    s.push(0); // nodes[0] is arbitrary root

    while (s.size()) {
        uint32_t current_node_id = s.top();
        node &current_node = nodes[current_node_id];
        current_node.visited = true;

        // Set all children for current node
        for (auto it=current_node.undirected_edges.begin(), end=current_node.undirected_edges.end(); it!=end; ++it) {
            if (!nodes[it->first].visited)
                current_node.children.emplace(it->first);
            else
                current_node.parent = it->first;
        }

        // If current node has no children, then it's a leaf.
        if (!current_node.children.size()) {
            s.pop();

            // there are n-1 nodes "outside" of this node
            current_node.undirected_edges.begin()->second = n - 1;

            // parent's node count pointing towards current_node is 1
            uint32_t parent_id = current_node.undirected_edges.begin()->first;
            nodes[parent_id].undirected_edges[current_node_id] = 1;

            continue;
        }

        // If all children are explored, set parent's edge values
        bool all_children_explored = true;
        for (auto it=current_node.children.begin(), end=current_node.children.end(); it!=end; ++it)
            all_children_explored = all_children_explored && nodes[*it].visited;
        if (all_children_explored) {
            s.pop();
            uint32_t n_nodes_on_children = 0;
            for (auto it=current_node.children.begin(), end=current_node.children.end(); it!=end; ++it)
                n_nodes_on_children += current_node.undirected_edges[*it];

            nodes[current_node.parent].undirected_edges[current_node_id] = n_nodes_on_children + 1;
            current_node.undirected_edges[current_node.parent] = n - (n_nodes_on_children + 1);
        }
    }
}

inline uint32_t gcd(uint32_t a, uint32_t b) {
    return b == 0 ? a : gcd(b, a%b);
}

probability get_probability(const std::vector<node> &nodes, uint32_t u, uint32_t v) {
    auto v_to_u_edge = nodes[v].undirected_edges.find(u);

    // If nodes are unconnected, return 0 probability
    if (v_to_u_edge == nodes[v].undirected_edges.end())
        return std::pair<uint32_t, uint32_t>{0, 1};

    uint32_t n_parents = v_to_u_edge->second;
    uint32_t n = nodes.size();
    uint32_t _gcd = gcd(n_parents, n);
    return probability{n_parents/_gcd, n/_gcd};
}

int main() {
    int n_games;
    for (std::cin >> n_games; n_games>0; --n_games) {
        uint32_t n;
        std::cin >> n;
        std::vector<node> nodes(n);

        // build graph
        for (uint32_t i=n-1; i>0; --i) {
            uint32_t u,v;
            std::cin >> u >> v;
            nodes[u].undirected_edges[v] = 0;
            nodes[v].undirected_edges[u] = 0;
        }

        set_weights(nodes);

        // get guesses and calculate total probability
        uint32_t n_guesses, k;
        std::cin >> n_guesses >> k;
        probability total_prob{1, 1};
        for (; n_guesses > 0; --n_guesses) {
            uint32_t u, v;
            std::cin >> u >> v;
            probability guess_prob = get_probability(nodes, u, v);

            // Reduce a, b, c, d in (ab)/(cd) before multiplying ab and cd
            uint32_t reduce1 = gcd(total_prob.first, guess_prob.second);
            total_prob.first /= reduce1;
            guess_prob.second /= reduce1;
            uint32_t reduce2 = gcd(total_prob.second, guess_prob.first);
            total_prob.second /= reduce2;
            guess_prob.first /= reduce2;

            // multiply probabilities
            total_prob.first *= guess_prob.first;
            total_prob.second *= guess_prob.second;
        }
    }
}
