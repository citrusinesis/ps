#include <bits/stdc++.h>

struct DisjointSet {
private:
  mutable std::vector<int> parent_;
  std::vector<int> rank_;

public:
  explicit DisjointSet(const int n) : parent_(n), rank_(n, 0) {
    std::iota(parent_.begin(), parent_.end(), 0);
  }

  int FindSet(const int u) const {
    if (parent_[u] != u) {
      parent_[u] = FindSet(parent_[u]);
    }
    return parent_[u];
  }

  void UnionSet(const int u, const int v) {
    const int root_u = FindSet(u);
    const int root_v = FindSet(v);

    if (root_u == root_v) {
      return;
    }

    if (rank_[root_u] < rank_[root_v]) {
      parent_[root_u] = root_v;
    } else if (rank_[root_u] > rank_[root_v]) {
      parent_[root_v] = root_u;
    } else {
      parent_[root_v] = root_u;
      rank_[root_u]++;
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int V, E;
  std::cin >> V >> E;

  std::vector<std::pair<int, std::pair<int, int>>> edges;
  edges.reserve(E);

  for (int i = 0; i < E; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    edges.emplace_back(w, std::make_pair(u, v));
  }

  std::ranges::sort(edges);

  DisjointSet disjoint_set(V + 1);
  int selected_edges = 0, total_weight = 0;

  for (const auto &[weight, edge] : edges) {
    if (selected_edges == V - 1) {
      break;
    }

    if (const auto [u, v] = edge;
        disjoint_set.FindSet(u) != disjoint_set.FindSet(v)) {
      disjoint_set.UnionSet(u, v);
      total_weight += weight;
      selected_edges++;
    }
  }

  std::cout << total_weight << '\n';
  return 0;
}