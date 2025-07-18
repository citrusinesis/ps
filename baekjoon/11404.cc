#include <bits/stdc++.h>

constexpr int kInf = 100000000;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector graph(n, std::vector(n, kInf));
  for (int i = 0; i < n; i++) {
    graph[i][i] = 0;
  }

  while (m--) {
    int u, v, c;
    std::cin >> u >> v >> c;
    graph[u - 1][v - 1] = std::min(graph[u - 1][v - 1], c);
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  for (const auto& row : graph) {
    for (const auto cost : row) {
      std::cout << (cost == kInf ? 0 : cost) << " ";
    }
    std::cout << '\n';
  }

  return 0;
}