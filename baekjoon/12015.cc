#include <bits/stdc++.h>
#include <list>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> lis;
  lis.reserve(N);

  for (int i = 0; i < N; i++) {
    int value;
    std::cin >> value;

    if (lis.empty() || lis.back() < value) {
      lis.push_back(value);
    } else {
      *std::ranges::lower_bound(lis, value) = value;
    }
  }

  std::cout << lis.size() << '\n';

  return 0;
}