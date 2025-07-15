#include <bits/stdc++.h>

void dfs(const std::vector<std::vector<int>> &graph, std::vector<int> &parent,
         const int u, const int p) {
  for (const auto v : graph[u]) {
    if (v == p) {
      continue;
    }

    if (!parent[v]) {
      parent[v] = u;
    }

    dfs(graph, parent, v, u);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector graph(N + 1, std::vector<int>());
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    std::cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::vector parent(N + 1, 0);
  dfs(graph, parent, 1, 0);

  for (auto it = parent.begin() + 2; it != parent.end(); ++it) {
    std::cout << *it << '\n';
  }

  return 0;
}