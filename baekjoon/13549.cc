#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, K;
  std::cin >> N >> K;

  std::vector dist(100001, INT_MAX);
  std::deque<int> dq;

  dq.push_back(N);
  dist[N] = 0;
  while (!dq.empty()) {
    const auto cur = dq.front();
    dq.pop_front();

    if (cur == K) {
      std::cout << dist[cur] << '\n';
      break;
    }

    if (auto next = 2 * cur; next <= 100000 && dist[next] > dist[cur]) {
      dist[next] = dist[cur];
      dq.push_front(next);
    }

    for (auto next : {cur - 1, cur + 1}) {
      if (next >= 0 && next <= 100000 && dist[next] > dist[cur] + 1) {
        dist[next] = dist[cur] + 1;
        dq.push_back(next);
      }
    }
  }

  return 0;
}