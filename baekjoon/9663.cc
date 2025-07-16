#include <bits/stdc++.h>

class NQueenSolver {
  int n;
  std::vector<int> board;

  std::vector<bool> used_cols;
  std::vector<bool> used_diag1;  // y = x + c => c = j - i
  std::vector<bool> used_diag2;  // y = -x + c => c = j + i

  bool can_place(const std::pair<int, int>& pos) const {
    auto [row, col] = pos;
    return !used_cols[col] && !used_diag1[col - row + (n - 1)] &&
           !used_diag2[col + row];
  }

  void place_queen(const std::pair<int, int>& pos) {
    auto [row, col] = pos;

    board[row] = col;
    used_cols[col] = true;
    used_diag1[col - row + (n - 1)] = true;
    used_diag2[col + row] = true;
  }

  void remove_queen(const std::pair<int, int>& pos) {
    auto [row, col] = pos;

    board[row] = -1;
    used_cols[col] = false;
    used_diag1[col - row + (n - 1)] = false;
    used_diag2[col + row] = false;
  }

  int backtrack(int row) {
    if (row == n) {
      return 1;
    }

    int count = 0;
    for (int col = 0; col < n; col++) {
      if (can_place({row, col})) {
        place_queen({row, col});
        count += backtrack(row + 1);
        remove_queen({row, col});
      }
    }

    return count;
  }

  void initialize() {
    this->board = std::vector(this->n, -1);
    this->used_cols.assign(n, false);
    this->used_diag1.assign(2 * n - 1, false);
    this->used_diag2.assign(2 * n - 1, false);
  }

 public:
  explicit NQueenSolver(const int size)
      : n(size),
        board(size, -1),
        used_cols(size, false),
        used_diag1(2 * size - 1, false),
        used_diag2(2 * size - 1, false) {}

  int solve() {
    initialize();
    return backtrack(0);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;
  std::cout << NQueenSolver(N).solve();

  return 0;
}