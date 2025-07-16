#include <bits/stdc++.h>

template <typename T>
struct node_t {
 private:
  T value;
  std::shared_ptr<node_t> left, right;

 public:
  node_t() = delete;
  explicit node_t(const T& v) : value(v), left(nullptr), right(nullptr) {}

  void set(const T& v) { value = v; }
  T get() const { return value; }

  void set_left(const std::shared_ptr<node_t> l) { left = l; }
  void set_right(const std::shared_ptr<node_t> r) { right = r; }

  auto children() const { return std::make_pair(left, right); }
};

template <typename T>
class bintree_t {
  std::shared_ptr<node_t<T>> root;

 public:
  bintree_t() = default;
  explicit bintree_t(const T& val) : root(std::make_shared<node_t<T>>(val)) {}
  explicit bintree_t(const std::shared_ptr<node_t<T>>& root) : root(root) {}

  void set_root(const std::shared_ptr<node_t<T>> r) { root = r; }
  auto get_root() const { return root; }

  template <typename Func>
  void preorder_traverse(const Func& func) {
    this->_preorder(root, func);
  }

  template <typename Func>
  void inorder_traverse(const Func& func) {
    this->_inorder(root, func);
  }

  template <typename Func>
  void postorder_traverse(const Func& func) {
    this->_postorder(root, func);
  }

 private:
  template <typename Func>
  void _preorder(std::shared_ptr<node_t<T>> node, const Func& func) {
    if (!node) return;
    func(node->get());
    auto [left, right] = node->children();
    this->_preorder(left, func);
    this->_preorder(right, func);
  }

  template <typename Func>
  void _inorder(std::shared_ptr<node_t<T>> node, const Func& func) {
    if (!node) return;
    auto [left, right] = node->children();
    this->_inorder(left, func);
    func(node->get());
    this->_inorder(right, func);
  }

  template <typename Func>
  void _postorder(std::shared_ptr<node_t<T>> node, const Func& func) {
    if (!node) return;
    auto [left, right] = node->children();
    this->_postorder(left, func);
    this->_postorder(right, func);
    func(node->get());
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::unordered_map<char, std::shared_ptr<node_t<char>>> nodes;
  for (int i = 0; i < N; ++i) {
    char u, l, r;
    std::cin >> u >> l >> r;

    if (!nodes.contains(u)) {
      nodes[u] = std::make_shared<node_t<char>>(u);
    }
    if (l != '.' && !nodes.contains(l)) {
      nodes[l] = std::make_shared<node_t<char>>(l);
      nodes[u]->set_left(nodes[l]);
    }
    if (r != '.' && !nodes.contains(r)) {
      nodes[r] = std::make_shared<node_t<char>>(r);
      nodes[u]->set_right(nodes[r]);
    }
  }

  bintree_t tree(nodes['A']);
  tree.preorder_traverse([](const char& val) { std::cout << val; });
  std::cout << '\n';
  tree.inorder_traverse([](const char& val) { std::cout << val; });
  std::cout << '\n';
  tree.postorder_traverse([](const char& val) { std::cout << val; });
  std::cout << '\n';

  return 0;
}