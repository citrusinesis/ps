#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> p(N + 1);
  for (int i = 0; i < N; i++) {
    int r, c;
    std::cin >> r >> c;

    if (i == 0)
      p[0] = r;

    p[i + 1] = c;
  }

  std::vector dp(N, std::vector(N, 0));
  for (int len = 2; len <= N; len++) {
    for (int i = 0; i <= N - len; i++) {
      const int j = i + len - 1;
      dp[i][j] = std::numeric_limits<int>::max();

      for (int k = i; k < j; k++) {
        const int mul_cost = p[i] * p[k + 1] * p[j + 1];
        const int cost = dp[i][k] + dp[k + 1][j] + mul_cost;

        dp[i][j] = std::min(dp[i][j], cost);
      }
    }
  }

  std::cout << dp[0][N - 1] << '\n';
  return 0;
}