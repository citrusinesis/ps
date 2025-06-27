#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;

  int ans = -1;

  for (int i = N / 5; i >= 0; --i) {
    if (const int r = N - (i * 5); r % 3 == 0) {
      ans = i + r / 3;
      break;
    }
  }

  std::cout << ans << '\n';
  return 0;
}