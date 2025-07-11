#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> stairs(N + 1);
  for (int i = 1; i <= N; i++) {
    std::cin >> stairs[i];
  }

  if (N == 1) {
    std::cout << stairs[1] << '\n';
    return 0;
  }

  std::vector<std::pair<int, int>> dp(N + 1, {0, 0});
  dp[1] = {0, stairs[1]};

  if (N >= 2) {
    dp[2] = {stairs[2], stairs[1] + stairs[2]};
  }

  for (int i = 3; i <= N; i++) {
    dp[i] = {
        std::max(dp[i - 2].first, dp[i - 2].second) + stairs[i],
        dp[i - 1].first + stairs[i],
    };
  }

  const auto [before_two, before_one] = dp[N];
  std::cout << std::max(before_two, before_one) << '\n';

  return 0;
}