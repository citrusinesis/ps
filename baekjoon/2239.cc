#include <bits/stdc++.h>

constexpr std::pair<int, int> kSudokuZone[9][9] = {
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}},
    {{0, 3}, {0, 4}, {0, 5}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}},
    {{0, 6}, {0, 7}, {0, 8}, {1, 6}, {1, 7}, {1, 8}, {2, 6}, {2, 7}, {2, 8}},
    {{3, 0}, {3, 1}, {3, 2}, {4, 0}, {4, 1}, {4, 2}, {5, 0}, {5, 1}, {5, 2}},
    {{3, 3}, {3, 4}, {3, 5}, {4, 3}, {4, 4}, {4, 5}, {5, 3}, {5, 4}, {5, 5}},
    {{3, 6}, {3, 7}, {3, 8}, {4, 6}, {4, 7}, {4, 8}, {5, 6}, {5, 7}, {5, 8}},
    {{6, 0}, {6, 1}, {6, 2}, {7, 0}, {7, 1}, {7, 2}, {8, 0}, {8, 1}, {8, 2}},
    {{6, 3}, {6, 4}, {6, 5}, {7, 3}, {7, 4}, {7, 5}, {8, 3}, {8, 4}, {8, 5}},
    {{6, 6}, {6, 7}, {6, 8}, {7, 6}, {7, 7}, {7, 8}, {8, 6}, {8, 7}, {8, 8}},
};

constexpr int GetZoneId(const int row, const int col) {
  return (row / 3) * 3 + (col / 3);
}

class Sudoku {
  std::vector<std::vector<int>> board_;

public:
  explicit Sudoku(const std::vector<std::vector<int>> &board) : board_(board) {}

  bool Solve() { return SolveBacktrack(0, 0); }

  void PrintBoard() const {
    for (const auto &row : board_) {
      for (const auto &val : row) {
        std::cout << val;
      }
      std::cout << "\n";
    }
  }

private:
  [[nodiscard]] bool IsValid(const int row, const int col,
                             const int val) const {
    for (int c = 0; c < 9; ++c) {
      if (board_[row][c] == val) {
        return false;
      }
    }

    for (int r = 0; r < 9; ++r) {
      if (board_[r][col] == val) {
        return false;
      }
    }

    const auto &zone = kSudokuZone[GetZoneId(row, col)];
    auto Check3x3Zone = [this, val](const auto &cell) {
      const auto &[zone_row, zone_col] = cell;
      return board_[zone_row][zone_col] != val;
    };
    if (!std::ranges::all_of(zone, Check3x3Zone)) {
      return false;
    }

    return true;
  }

  [[nodiscard]] bool FindEmptyCell(int &row, int &col) const {
    for (row = 0; row < 9; ++row) {
      for (col = 0; col < 9; ++col) {
        if (board_[row][col] == 0) {
          return true;
        }
      }
    }
    return false;
  }

  bool SolveBacktrack(int row, int col) {
    if (!FindEmptyCell(row, col)) {
      return true;
    }

    for (int val = 1; val <= 9; ++val) {
      if (IsValid(row, col, val)) {
        board_[row][col] = val;

        if (SolveBacktrack(row, col)) {
          return true;
        }

        board_[row][col] = 0;
      }
    }

    return false;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector board(9, std::vector(9, 0));

  for (int i = 0; i < 9; ++i) {
    std::string line;
    std::cin >> line;

    for (int j = 0; j < 9; ++j) {
      board[i][j] = line[j] - '0';
    }
  }

  Sudoku solver(board);
  solver.Solve();
  solver.PrintBoard();

  return 0;
}