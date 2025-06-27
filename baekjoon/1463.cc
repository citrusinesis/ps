#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  std::vector dp = {0, 0, 1, 1};
  for (int i = 4; i <= N; i++) {
    dp.push_back(std::min({
        dp[i - 1] + 1,
        i % 2 == 0 ? dp[i / 2] + 1 : INT_MAX,
        i % 3 == 0 ? dp[i / 3] + 1 : INT_MAX,
    }));
  }

  std::cout << dp[N] << '\n';
  return 0;
}