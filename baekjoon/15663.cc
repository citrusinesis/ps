#include <bits/stdc++.h>

void backtrack(const std::vector<int>& nums, std::vector<bool>& used,
               std::vector<int>& current, std::map<std::string, bool>& dup,
               const int M) {
  if (static_cast<int>(current.size()) == M) {
    std::stringstream ss;
    for (const auto val : current) {
      ss << val << ' ';
    }

    const std::string output = ss.str();
    if (dup.contains(output)) {
      return;
    }

    dup[output] = true;
    std::cout << output << '\n';
    return;
  }

  for (int idx = 0; idx < nums.size(); idx++) {
    if (!used[idx]) {
      used[idx] = true;
      current.push_back(nums[idx]);

      backtrack(nums, used, current, dup, M);

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
  std::map<std::string, bool> dup;

  backtrack(nums, used, current, dup, M);

  return 0;
}