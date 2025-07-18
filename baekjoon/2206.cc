#include <bits/stdc++.h>

constexpr int kInf = std::numeric_limits<int>::max();

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

int BFS(const std::vector<std::vector<int>> &map) {
  const int N = map.size(), M = map[0].size();
  if (N == 1 && M == 1) {
    return 1;
  }

  std::vector visited(2, std::vector(N, std::vector(M, false)));
  std::queue<std::tuple<int, int, int, int>> q; // {y, x, dist, broken}

  q.emplace(0, 0, 1, 0);
  visited[0][0][0] = true;

  while (!q.empty()) {
    const auto [y, x, dist, broken] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      const int next_y = y + dy[i];
      const int next_x = x + dx[i];

      if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
        continue;
      }

      if (!broken) {
        if (map[next_y][next_x] && !visited[1][next_y][next_x]) {
          if (next_y == N - 1 && next_x == M - 1) {
            return dist + 1;
          }
          visited[1][next_y][next_x] = true;
          q.emplace(next_y, next_x, dist + 1, 1);
        }

        if (!map[next_y][next_x] && !visited[0][next_y][next_x]) {
          if (next_y == N - 1 && next_x == M - 1) {
            return dist + 1;
          }
          visited[0][next_y][next_x] = true;
          q.emplace(next_y, next_x, dist + 1, 0);
        }
      } else {
        if (!map[next_y][next_x] && !visited[1][next_y][next_x]) {
          if (next_y == N - 1 && next_x == M - 1) {
            return dist + 1;
          }
          visited[1][next_y][next_x] = true;
          q.emplace(next_y, next_x, dist + 1, 1);
        }
      }
    }
  }

  return -1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  std::vector map(N, std::vector(M, 0));
  for (int i = 0; i < N; i++) {
    std::string line;
    std::cin >> line;

    for (int j = 0; j < M; j++) {
      map[i][j] = line[j] - '0';
    }
  }

  std::cout << BFS(map) << std::endl;

  return 0;
}