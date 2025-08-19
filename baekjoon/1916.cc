#include <bits/stdc++.h>

constexpr int kInf = std::numeric_limits<int>::max();

typedef std::vector<std::vector<std::pair<int, int>>> Graph;

std::vector<int> Dijkstra(const Graph &graph, int start) {
  std::vector dist(graph.size(), kInf);
  std::priority_queue<std::pair<int, int>> pq;

  dist[start] = 0;
  pq.emplace(0, start);
  while (!pq.empty()) {
    const auto [d, u] = pq.top();
    pq.pop();

    if (-d > dist[u])
      continue;

    for (const auto [w, v] : graph[u]) {
      if (const int new_d = dist[u] + w; new_d < dist[v]) {
        dist[v] = new_d;
        pq.emplace(-new_d, v);
      }
    }
  }

  return dist;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  Graph graph(N);
  for (int i = 0; i < M; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;

    graph[u - 1].emplace_back(w, v - 1);
  }

  int u, v;
  std::cin >> u >> v;

  std::cout << Dijkstra(graph, u - 1)[v - 1] << "\n";

  return 0;
}