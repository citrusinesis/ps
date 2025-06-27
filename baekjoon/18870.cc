#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> coords(N);
  for (int i = 0; i < N; i++) {
    std::cin >> coords[i];
  }

  std::vector<int> unique_coords = coords;

  std::sort(unique_coords.begin(), unique_coords.end());
  unique_coords.erase(std::unique(unique_coords.begin(), unique_coords.end()),
                      unique_coords.end());

  for (int coord : coords) {
    const auto it =
        std::lower_bound(unique_coords.begin(), unique_coords.end(), coord);
    std::cout << std::distance(unique_coords.begin(), it) << " ";
  }

  std::cout << '\n';
  return 0;
}