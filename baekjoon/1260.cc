#include <bits/stdc++.h>

std::vector<int> dfs(const std::vector<std::vector<int>>& graph,
                     const int start) {
  std::vector visited(graph.size(), false);
  std::vector<int> result;

  std::function<void(int)> _dfs = [&](const int u) {
    visited[u] = true;
    result.push_back(u);

    for (const int v : graph[u]) {
      if (!visited[v]) {
        _dfs(v);
      }
    }
  };

  _dfs(start);
  return result;
}

std::vector<int> bfs(const std::vector<std::vector<int>>& graph,
                     const int start) {
  std::vector visited(graph.size(), false);
  std::queue<int> q;
  std::vector<int> result;

  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    const int u = q.front();
    q.pop();

    result.push_back(u);

    for (const int v : graph[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M, V;
  std::cin >> N >> M >> V;

  std::vector<std::vector<int>> graph(N + 1);
  for (int i = 1; i <= M; i++) {
    int u, v;
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (auto& adj : graph) {
    std::sort(adj.begin(), adj.end());
  }

  for (const int i : dfs(graph, V)) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  for (const int i : bfs(graph, V)) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  return 0;
}