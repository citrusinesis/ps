#include <bits/stdc++.h>

constexpr int kInf = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, S;
  std::cin >> N >> S;

  std::vector sum(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    std::cin >> sum[i];
    sum[i] += sum[i - 1];
  }

  int length = kInf;
  int l = 0, r = 0;
  while (l <= r && r <= N) {
    if (r < N && sum[r] - sum[l] < S) {
      r++;
    } else if (sum[r] - sum[l] >= S) {
      length = std::min(length, r - l);
      l++;
    } else {
      break;
    }
  }

  std::cout << (length == kInf ? 0 : length) << '\n';

  return 0;
}