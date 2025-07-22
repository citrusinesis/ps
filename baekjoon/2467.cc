#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<long long> val(N);
  for (int i = 0; i < N; i++) {
    std::cin >> val[i];
  }

  int front = 0, back = N - 1;
  int best_front = front, best_back = back;
  long long best_sum = std::abs(val[front] + val[back]);

  while (front < back) {
    const long long current_sum = val[front] + val[back];

    if (std::abs(current_sum) < best_sum) {
      best_sum = std::abs(current_sum);
      best_front = front;
      best_back = back;
    }

    if (current_sum > 0) {
      --back;
    } else if (current_sum < 0) {
      ++front;
    } else {
      break;
    }
  }

  std::cout << val[best_front] << ' ' << val[best_back] << '\n';

  return 0;
}