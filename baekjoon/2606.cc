#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int>> graph(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    std::cin >> u >> v;
    graph[u - 1].push_back(v - 1);
    graph[v - 1].push_back(u - 1);
  }

  std::vector<bool> visited(N, false);
  std::queue<int> q;
  q.push(0);
  visited[0] = true;

  int ans = 0;
  while (!q.empty()) {
    const int u = q.front();
    q.pop();

    for (auto v : graph[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);

        ans++;
      }
    }
  }

  std::cout << ans << '\n';
  return 0;
}
