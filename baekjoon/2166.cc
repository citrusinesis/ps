#include <bits/stdc++.h>

long double CalculatePolygonArea(const std::vector<int> &x,
                                 const std::vector<int> &y) {
  const int N = x.size();

  long long i = 0, j = 0;
  for (int idx = 0; idx < N; idx++) {
    i += static_cast<long long>(x[idx]) *
         static_cast<long long>(y[(idx + 1) % N]);
    j += static_cast<long long>(x[(idx + 1) % N]) *
         static_cast<long long>(y[idx]);
  }

  return 0.5L * static_cast<long double>(std::llabs(i - j));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector x(N, 0);
  std::vector y(N, 0);
  for (int i = 0; i < N; i++) {
    std::cin >> x[i] >> y[i];
  }

  std::cout.precision(1);
  std::cout << std::fixed << CalculatePolygonArea(x, y) << '\n';

  return 0;
}