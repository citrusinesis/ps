#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int A, B;
  std::cin >> A >> B;

  std::priority_queue<std::pair<long long, int>> pq;
  pq.emplace(A, 1);

  while (!pq.empty()) {
    const auto [number, times] = pq.top();
    pq.pop();

    if (number == B) {
      std::cout << times << std::endl;
      return 0;
    }

    if (const auto next = number * 2; next <= B) {
      pq.emplace(next, times + 1);
    }

    if (const auto next = number * 10 + 1; next <= B) {
      pq.emplace(next, times + 1);
    }
  }

  std::cout << -1 << std::endl;

  return 0;
}