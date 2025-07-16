#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;

  std::vector stickers(2, std::vector(n, 0));
  for (auto& row : stickers) {
    for (int i = 0; i < n; ++i) {
      std::cin >> row[i];
    }
  }

  std::vector dp(2, std::vector(n, 0));
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      dp[0][0] = stickers[0][0];
      dp[1][0] = stickers[1][0];
      continue;
    }

    dp[0][i] = std::max(stickers[0][i] + dp[1][i - 1], dp[0][i - 1]);
    dp[1][i] = std::max(stickers[1][i] + dp[0][i - 1], dp[1][i - 1]);
  }

  std::cout << std::max(dp[0][n - 1], dp[1][n - 1]) << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}