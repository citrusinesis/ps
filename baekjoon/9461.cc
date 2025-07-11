#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  std::vector<long long> P = {1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
  for (int i = 10; i < 100; i++) {
    P.push_back(P[i - 2] + P[i - 3]);
  }

  while (T--) {
    int n;
    std::cin >> n;
    std::cout << P[n - 1] << "\n";
  }

  return 0;
}