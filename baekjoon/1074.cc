#include <iostream>

int solve(const int n, const int r, const int c) {
  if (n == 0) {
    return 0;
  }

  const int mid = 1 << (n - 1);
  const int quadrant_size = mid * mid;

  if (r < mid && c < mid) {
    return solve(n - 1, r, c);
  }
  if (r < mid && c >= mid) {
    return quadrant_size + solve(n - 1, r, c - mid);
  }
  if (r >= mid && c < mid) {
    return 2 * quadrant_size + solve(n - 1, r - mid, c);
  }
  return 3 * quadrant_size + solve(n - 1, r - mid, c - mid);
}

int main() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, r, c;
  std::cin >> N >> r >> c;

  std::cout << solve(N, r, c) << '\n';

  return 0;
}
