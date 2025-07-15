#include <bits/stdc++.h>

void backtrack(const std::vector<int>& nums, std::vector<bool>& used,
               std::vector<int>& current, const int N, const int M) {
  if (static_cast<int>(current.size()) == M) {
    for (const auto val : current) {
      std::cout << val << ' ';
    }
    std::cout << '\n';
    return;
  }

  for (int idx = 0; idx < nums.size(); idx++) {
    if (!used[idx]) {
      used[idx] = true;
      current.push_back(nums[idx]);

      backtrack(nums, used, current, N, M);

      current.pop_back();
      used[idx] = false;
    }
  }
}

int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> nums(N);

  for (auto& num : nums) {
    std::cin >> num;
  }
  std::ranges::sort(nums);

  std::vector used(N, false);
  std::vector<int> current;
  current.reserve(M);

  backtrack(nums, used, current, N, M);

  return 0;
}