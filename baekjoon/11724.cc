#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int>> graph(N);
  for (int k = 0; k < M; ++k) {
    int u, v;
    std::cin >> u >> v;
    graph[u - 1].push_back(v - 1);
    graph[v - 1].push_back(u - 1);
  }

  std::vector visited(N, false);
  int component_count = 0;

  for (int i = 0; i < N; ++i) {
    if (!visited[i]) {
      component_count++;

      std::queue<int> q;
      q.push(i);
      visited[i] = true;

      while (!q.empty()) {
        const int u = q.front();
        q.pop();

        for (int v : graph[u]) {
          if (!visited[v]) {
            visited[v] = true;
            q.push(v);
          }
        }
      }
    }
  }

  std::cout << component_count << '\n';
  return 0;
}