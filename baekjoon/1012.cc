#include <bits/stdc++.h>

int solve() {
  int M, N, K;
  std::cin >> M >> N >> K;

  std::vector arr(N, std::vector(M, 0));
  std::vector visited(N, std::vector(M, false));

  for (int i = 0; i < K; i++) {
    int x, y;
    std::cin >> x >> y;
    arr[y][x] = 1;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j]) {
        continue;
      }

      if (!arr[i][j]) {
        visited[i][j] = true;
        continue;
      }

      std::queue<std::pair<int, int>> q;
      q.push({i, j});
      while (!q.empty()) {
        const auto [y, x] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
          constexpr int dx[] = {0, 1, 0, -1};
          constexpr int dy[] = {-1, 0, 1, 0};
          const int n = y + dy[k];
          const int m = x + dx[k];

          if (n < 0 || n >= N || m < 0 || m >= M) {
            continue;
          }

          if (visited[n][m]) {
            continue;
          }

          if (!arr[n][m]) {
            visited[n][m] = true;
            continue;
          }

          visited[n][m] = true;
          q.push({n, m});
        }
      }
      ans++;
    }
  }

  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    std::cout << solve() << '\n';
  }
  return 0;
}