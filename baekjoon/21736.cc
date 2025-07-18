#include <bits/stdc++.h>

constexpr int dy[] = {0, 0, 1, -1};
constexpr int dx[] = {1, -1, 0, 0};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  std::pair<int, int> start;
  std::vector map(N, std::vector(M, ' '));
  std::vector visited(N, std::vector(M, false));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> map[i][j];

      if (map[i][j] == 'I') {
        start = {i, j};
      }
    }
  }

  std::queue<std::pair<int, int>> q;
  q.push(start);

  int result = 0;
  while (!q.empty()) {
    const auto [y, x] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      const int next_y = y + dy[i];
      const int next_x = x + dx[i];

      if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
        continue;
      }

      if (const auto val = map[next_y][next_x];
          !visited[next_y][next_x] && (val == 'O' || val == 'P')) {
        if (val == 'P') result++;
        visited[next_y][next_x] = true;
        q.push({next_y, next_x});
      }
    }
  }

  if (!result) {
    std::cout << "TT" << '\n';
  } else {
    std::cout << result << '\n';
  }

  return 0;
}