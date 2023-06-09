// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> perm = tree.getPermut();
    if (n > perm.size()) {
        return {};
    } else {
    return perm[n - 1];
    }
}
