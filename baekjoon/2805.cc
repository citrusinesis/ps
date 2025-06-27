#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int N;
  long long M;
  std::cin >> N >> M;

  std::vector<int> trees(N);
  for (int i = 0; i < N; i++) {
    std::cin >> trees[i];
  }

  long long start = 0;
  long long end = *std::max_element(trees.begin(), trees.end());

  long long ans = 0;
  while (start <= end) {
    const long long mid = start + (end - start) / 2;

    long long sum = 0;
    for (int i = 0; i < N; i++) {
      if (trees[i] > mid) {
        sum += trees[i] - mid;
      }
    }

    if (sum >= M) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  std::cout << ans << '\n';
  return 0;
}