// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>
class Tree {
 private:
    std::vector<std::vector<char>> list;
    struct Node {
      char value = '\0';
@@ -30,7 +30,8 @@ class Tree {
      }
      return root;
    }
 public:
    std::vector<std::vector<char>> getPermut() const {
      return list;
    }
    explicit Tree(std::vector<char>);
    void Perm(Node*, std::vector<char>);
};
Tree::Tree(std::vector<char> vec) {
  root = createTree(root, vec);
  Perm(root, {});
}
void Tree::Perm(Node* root, std::vector<char> rec) {
  if (root && root->value != '\0') {
    rec.push_back(root->value);
  }
  if (!root->childs.size()) {
    list.push_back(rec);
  }
  for (Node* child : root->childs) {
    Perm(child, rec);
  }
}
#endif  // INCLUDE_TREE_H_
