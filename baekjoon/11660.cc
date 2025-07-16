#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  std::vector num(N + 1, std::vector(N + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> num[i][j];
    }
  }

  std::vector sum(N + 1, std::vector(N + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      sum[i][j] = num[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }

  while (M--) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    std::cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] +
                     sum[x1 - 1][y1 - 1]
              << '\n';
  }

  return 0;
}