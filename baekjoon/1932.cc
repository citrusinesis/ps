#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector triangle(N, std::vector<int>());
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      int input;
      std::cin >> input;

      if (j == 0) {
        triangle[i].push_back(i == 0 ? input : triangle[i - 1][0] + input);
      } else if (j == i) {
        triangle[i].push_back(triangle[i - 1][i - 1] + input);
      } else {
        triangle[i].push_back(
            std::max(triangle[i - 1][j - 1], triangle[i - 1][j]) + input);
      }
    }
  }

  std::cout << *std::ranges::max_element(triangle[N - 1]) << '\n';

  return 0;
}