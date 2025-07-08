#include <bits/stdc++.h>

int N, M;
std::vector<int> current;

void backtrack(const int start) {
  if (current.size() == M) {
    for (int i = 0; i < M; i++) {
      std::cout << current[i];
      if (i < M - 1) std::cout << " ";
    }
    std::cout << "\n";
    return;
  }

  for (int i = start; i <= N; i++) {
    current.push_back(i);
    backtrack(i + 1);
    current.pop_back();
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;
  backtrack(1);

  return 0;
}