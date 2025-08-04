#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s1, s2;
  std::cin >> s1 >> s2;

  const int len1 = static_cast<int>(s1.length());
  const int len2 = static_cast<int>(s2.length());

  std::vector dp(len1 + 1, std::vector<int>(len2 + 1, 0));

  for (int i = 1; i <= len1; ++i) {
    for (int j = 1; j <= len2; ++j) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }

  std::string lcs_result;
  int i = len1, j = len2;

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      lcs_result = s1[i - 1] + lcs_result;
      --i;
      --j;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      --i;
    } else {
      --j;
    }
  }

  std::cout << dp[len1][len2] << '\n' << lcs_result << '\n';

  return 0;
}