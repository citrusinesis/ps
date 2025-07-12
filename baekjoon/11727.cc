#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<long long> tile = {1, 3};
  for (int i = 2; i < 1000; i++) {
    tile.push_back((tile[i - 1] + 2 * tile[i - 2]) % 10007);
  }

  int n;
  std::cin >> n;

  std::cout << tile[n - 1] << std::endl;
  return 0;
}