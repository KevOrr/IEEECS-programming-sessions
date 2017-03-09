#include <iostream>
#include <string>

template <typename T>
struct bstnode {
    bstnode<T> *left;
    bstnode<T> *right;
    T val;
};

void print_names(bstnode<std::string> *root, std::string pattern) {
    if (root == nullptr)
        return;

    int cmp = root->val.compare(0, pattern.length(), pattern, 0, pattern.length());
    if (cmp == 0) {
        std::cout << root->val;
        print_names(root->left, pattern);
        print_names(root->right, pattern);
    } else if (cmp < 0)
        print_names(root->right, pattern);
    else if (cmp > 0)
        print_names(root->left, pattern);
}
