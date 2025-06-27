#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  std::vector<int> arr(N + 1);
  for (int i = 1; i <= N; i++) {
    std::cin >> arr[i];
  }

  int ans = 0;
  std::vector dp(N + 1, 1);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < i; j++) {
      if (arr[j] < arr[i]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    ans = std::max(ans, dp[i]);
  }

  std::cout << ans << '\n';
  return 0;
}