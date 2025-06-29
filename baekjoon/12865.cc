#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, K;
  std::cin >> N >> K;

  std::vector<std::pair<int, int>> things;
  for (int i = 0; i < N; i++) {
    int w, v;
    std::cin >> w >> v;

    things.push_back({w, v});
  }

  std::vector dp(N + 1, std::vector(K + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      const auto [w, v] = things[i - 1];
      if (j < w) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w] + v);
      }
    }
  }

  std::cout << dp[N][K] << '\n';
  return 0;
}
