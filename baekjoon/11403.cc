#include <bits/stdc++.h>

constexpr int kInf = std::numeric_limits<int>::max();

typedef std::vector<std::vector<int>> Graph;

Graph FloydWarshall(const Graph &graph) {
  Graph dist(graph.size(), std::vector(graph.size(), kInf));
  for (int i = 0; i < graph.size(); i++) {
    for (int j = 0; j < graph.size(); j++) {
      if (graph[i][j] > 0) {
        dist[i][j] = graph[i][j];
      } else {
        dist[i][j] = kInf;
      }
    }
  }

  for (int k = 0; k < graph.size(); k++) {
    for (int i = 0; i < graph.size(); i++) {
      for (int j = 0; j < graph.size(); j++) {
        if (dist[i][k] != kInf && dist[k][j] != kInf) {
          dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  return dist;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  Graph graph(N, std::vector(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> graph[i][j];
    }
  }

  for (const Graph dist = FloydWarshall(graph); const auto &row : dist) {
    for (const auto &val : row) {
      if (val == kInf) {
        std::cout << 0 << " ";
      } else {
        std::cout << 1 << " ";
      }
    }
    std::cout << std::endl;
  }

  return 0;
}