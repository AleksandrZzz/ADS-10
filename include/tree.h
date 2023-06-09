// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
 public:
    explicit Tree(std::vector<char> nums) :root(nullptr) {
        MakeTree(nums);
    }
    std::vector<std::vector<char>> getPerm() const {
        return permutations;
    }

 private:
    struct Node {
        char symbol;
        std::vector<Node*> descen;
        Node(char sym = '\0') :symbol(sym) {}
        explicit Node(char sym = '\0') :symbol(sym) {}
    };
    Node* root;
    std::vector<std::vector<char>> permutations;
    void addNode(Node* newroot, std::vector<char> row) {
        if (!newroot) {
            root = newroot = new Node;
        }
        for (char symbol : row) {
            Node* temp = new Node(symbol);
            newroot->descen.push_back(temp);
            std::vector<char> newRow(row);
            newRow.erase(std::find(newRow.begin(), \
                newRow.end(), symbol));
            addNode(temp, newRow);
        }
    }
    void evadeTree(Node* newroot, std::vector<char> row) {
        if (newroot != nullptr && newroot->symbol != '\0')
            row.push_back(newroot->symbol);
        if (newroot->descen.empty())
            permutations.push_back(row);
        for (Node* descen : newroot->descen) {
            evadeTree(descen, row);
        }
    }
    void MakeTree(std::vector<char> row) {
        addNode(root, row);
        evadeTree(root, {});
    }
};
#endif  // INCLUDE_TREE_H_
