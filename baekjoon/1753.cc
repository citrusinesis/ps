#include <bits/stdc++.h>

std::vector<int> dijkstra(
    int start, const std::vector<std::vector<std::pair<int, int>>>& graph) {
  std::vector dist(graph.size(), INT_MAX);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  dist[start] = 0;
  pq.emplace(0, start);

  while (!pq.empty()) {
    auto const [d, u] = pq.top();
    pq.pop();

    if (d > dist[u]) continue;

    for (auto const [v, weight] : graph[u]) {
      if (auto const new_dist = dist[u] + weight; new_dist < dist[v]) {
        dist[v] = new_dist;
        pq.emplace(new_dist, v);
      }
    }
  }

  return std::vector(dist.begin() + 1, dist.end());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int V, E;
  std::cin >> V >> E;

  int start;
  std::cin >> start;

  std::vector<std::vector<std::pair<int, int>>> graph(V + 1);
  for (int i = 0; i < E; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  for (const auto d : dijkstra(start, graph)) {
    if (d == INT_MAX) {
      std::cout << "INF" << '\n';
    } else {
      std::cout << d << '\n';
    }
  }

  return 0;
}