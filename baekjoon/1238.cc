#include <bits/stdc++.h>

constexpr int kInf = 1e4;

std::vector<int> dijkstra(
    const std::vector<std::vector<std::pair<int, int>>>& graph,
    const int start) {
  std::vector time(graph.size(), kInf);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  time[start] = 0;
  pq.emplace(0, start);

  while (!pq.empty()) {
    const auto [t, u] = pq.top();
    pq.pop();

    if (time[u] < t) continue;

    for (const auto& [v_t, v] : graph[u]) {
      if (auto new_time = time[u] + v_t; new_time < time[v]) {
        time[v] = new_time;
        pq.emplace(new_time, v);
      }
    }
  }

  return time;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M, X;
  std::cin >> N >> M >> X;

  std::vector<std::vector<std::pair<int, int>>> graph(N + 1);
  std::vector<std::vector<std::pair<int, int>>> inverted_graph(N + 1);

  for (int i = 1; i <= M; i++) {
    int u, v, t;
    std::cin >> u >> v >> t;

    graph[u].emplace_back(t, v);
    inverted_graph[v].emplace_back(t, u);
  }

  const auto return_time = dijkstra(graph, X);
  const auto going_time = dijkstra(inverted_graph, X);

  int max_time = 0;
  for (int i = 1; i <= N; i++) {
    max_time = std::max(max_time, going_time[i] + return_time[i]);
  }

  std::cout << max_time << '\n';

  return 0;
}