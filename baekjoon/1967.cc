#include <bits/stdc++.h>

std::pair<int, int> dfs(
    const int start,
    const std::vector<std::vector<std::pair<int, int>>> &graph) {
  std::vector dist(graph.size(), INT_MAX);
  std::vector visited(graph.size(), false);
  std::stack<int> stack;

  dist[start] = 0;
  stack.push(start);
  while (!stack.empty()) {
    const int u = stack.top();
    stack.pop();
    visited[u] = true;
    for (auto const [v, weight] : graph[u]) {
      if (!visited[v]) {
        dist[v] = dist[u] + weight;
        stack.push(v);
      }
    }
  }

  int max_dist = 0;
  int farthest_node = start;
  for (int i = 1; i < graph.size(); i++) {
    if (dist[i] != INT_MAX && dist[i] > max_dist) {
      max_dist = dist[i];
      farthest_node = i;
    }
  }

  return {farthest_node, max_dist};
}

int solve(const std::vector<std::vector<std::pair<int, int>>> &graph) {
  int farthest_node, diameter;
  std::tie(farthest_node, std::ignore) = dfs(1, graph);
  std::tie(std::ignore, diameter) = dfs(farthest_node, graph);
  return diameter;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<std::vector<std::pair<int, int>>> graph(N + 1);
  for (int i = 1; i < N; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
  }

  std::cout << solve(graph) << '\n';
  return 0;
}