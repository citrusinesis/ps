#include <iostream>

struct BinaryTreeNode {
private:
  int val_;
  BinaryTreeNode *left{};
  BinaryTreeNode *right{};

public:
  explicit BinaryTreeNode(const int val) : val_(val) {}

  ~BinaryTreeNode() {
    delete left;
    delete right;
  }

  void add_node(const int val) {
    if (val == val_)
      return;

    if (val < val_) {
      if (left)
        left->add_node(val);
      else
        left = new BinaryTreeNode(val);
    } else if (val > val_) {
      if (right)
        right->add_node(val);
      else
        right = new BinaryTreeNode(val);
    }
  }

  void postorder_traverse(std::ostream &os) const {
    if (left)
      left->postorder_traverse(os);
    if (right)
      right->postorder_traverse(os);
    os << val_ << " ";
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  BinaryTreeNode *root = nullptr;
  int input;

  while (std::cin >> input) {
    if (!root)
      root = new BinaryTreeNode(input);
    else
      root->add_node(input);
  }

  if (root) {
    root->postorder_traverse(std::cout);
    delete root;
  }

  return 0;
}