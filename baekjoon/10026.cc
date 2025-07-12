#include <bits/stdc++.h>

constexpr int dy[] = {-1, 0, 1, 0};
constexpr int dx[] = {0, 1, 0, -1};

void bfs(const std::vector<std::vector<char>>& map,
         std::vector<std::vector<bool>>& visited, int areas[],
         const std::pair<int, int>& start, const char current,
         const std::function<int(char)>& parse) {
  const int N = map.size();
  std::queue<std::pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    const auto [y, x] = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      const int next_y = y + dy[k];
      const int next_x = x + dx[k];

      if (0 > next_x || 0 > next_y || N <= next_x || N <= next_y) {
        continue;
      }

      if (visited[next_y][next_x]) {
        continue;
      }

      if (parse(map[next_y][next_x]) == parse(current)) {
        visited[next_y][next_x] = true;
        q.emplace(next_y, next_x);
      }
    }
  }

  areas[parse(current)]++;
}

int normal(const std::vector<std::vector<char>>& map) {
  const int N = map.size();
  std::vector visited(N, std::vector(N, false));

  int areas[] = {0, 0, 0};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j]) {
        continue;
      }

      constexpr auto parse = [](const char color) {
        switch (color) {
          case 'R':
            return 0;
          case 'G':
            return 1;
          case 'B':
            return 2;
          default:
            return -1;
        }
      };

      bfs(map, visited, areas, {i, j}, map[i][j], parse);
    }
  }

  return std::accumulate(std::begin(areas), std::end(areas), 0);
}

int colorblind(const std::vector<std::vector<char>>& map) {
  const int N = map.size();
  std::vector visited(N, std::vector(N, false));

  int areas[] = {0, 0};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j]) {
        continue;
      }

      constexpr auto parse_blind = [](const char color) {
        switch (color) {
          case 'R':
          case 'G':
            return 0;
          case 'B':
            return 1;
          default:
            return -1;
        }
      };

      bfs(map, visited, areas, {i, j}, map[i][j], parse_blind);
    }
  }

  return std::accumulate(std::begin(areas), std::end(areas), 0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector map(N, std::vector<char>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> map[i][j];
    }
  }

  std::cout << normal(map) << ' ' << colorblind(map) << std::endl;
  return 0;
}