#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;

  int cache[12] = {0, 1, 2, 4};
  for (int i = 4; i < 12; i++) {
    cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
  }

  while (T--) {
    int n;
    std::cin >> n;
    std::cout << cache[n] << '\n';
  }

  return 0;
}