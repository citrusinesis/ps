#include <bits/stdc++.h>

void Dfs(const std::vector<int> &graph, std::vector<int> &state,
         const int node) {
  if (state[node] == 1) {
    int current = node;
    do {
      state[current] = 3;
      current = graph[current];
    } while (current != node);
    return;
  }

  if (state[node] >= 2) {
    return;
  }
  state[node] = 1;

  Dfs(graph, state, graph[node]);

  if (state[node] == 1) {
    state[node] = 2;
  }
}

void Solve() {
  int N;
  std::cin >> N;

  std::vector state(N + 1, 0);
  std::vector graph(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    std::cin >> graph[i];
  }
  for (int i = 1; i <= N; i++) {
    if (state[i] == 0) {
      Dfs(graph, state, i);
    }
  }

  int cycle_count = 0;
  for (int i = 1; i <= N; i++) {
    if (state[i] == 3) {
      cycle_count++;
    }
  }

  std::cout << N - cycle_count << '\n';
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