#include <bits/stdc++.h>

void solve() {
  int N;
  std::cin >> N;

  std::unordered_map<std::string, std::vector<std::string>> map;
  while (N--) {
    std::string item, category;
    std::cin >> item >> category;

    map[category].push_back(item);
  }

  if (map.size() == 1) {
    std::cout << map.begin()->second.size() << "\n";
    return;
  }

  int result = 1;
  for (const auto [_, value] : map) {
    result *= value.size() + 1;
  }

  std::cout << result - 1 << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}