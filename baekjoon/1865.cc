#include <bits/stdc++.h>

bool HasNegativeCycle(const int N,
                      const std::vector<std::tuple<int, int, int>> &edges) {
  std::vector<long long> dist(N + 1, 0);

  for (int i = 0; i < N - 1; ++i) {
    for (const auto &[u, v, w] : edges) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }

  for (const auto &[u, v, w] : edges) {
    if (dist[u] + w < dist[v]) {
      return true;
    }
  }

  return false;
}

void Solve() {
  int N, M, W;
  std::cin >> N >> M >> W;
  std::vector<std::tuple<int, int, int>> edges;

  for (int i = 0; i < M; ++i) {
    int S, E, T;
    std::cin >> S >> E >> T;
    edges.emplace_back(S, E, T);
    edges.emplace_back(E, S, T);
  }

  for (int i = 0; i < W; ++i) {
    int S, E, T;
    std::cin >> S >> E >> T;
    edges.emplace_back(S, E, -T);
  }

  if (HasNegativeCycle(N, edges)) {
    std::cout << "YES" << '\n';
  } else {
    std::cout << "NO" << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    Solve();
  }

  return 0;
}