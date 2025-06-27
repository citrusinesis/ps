#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> row_t;
typedef vector<row_t> matrix_t;

matrix_t copyMatrix(const matrix_t &matrix, std::pair<size_t, size_t> row_range, std::pair<size_t, size_t> col_range) {
    auto [rt, rb] = row_range;
    auto [cl, cr] = col_range;

    const size_t new_rows = rb - rt;
    const size_t new_cols = cr - cl;

    if (new_rows == 0 || new_cols == 0) {
        return {};
    }

    matrix_t copy(new_rows, row_t(new_cols));
    for (size_t i = 0; i < new_rows; i++) {
        for (size_t j = 0; j < new_cols; j++) {
            copy[i][j] = matrix[rt + i][cl + j];
        }
    }

    return copy;
}

int getMatrixColor(const matrix_t &matrix) {
    if (matrix.empty() || matrix.front().empty()) {
        return -1;
    }

    const int val = matrix.front().front();
    for (const auto &row: matrix) {
        for (const auto &col: row) {
            if (col != val) {
                return -1;
            }
        }
    }

    return val;
}

pair<int, int> operator+(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
};

pair<int, int> split_matrix(const matrix_t &matrix) {
    if (const int color = getMatrixColor(matrix); color != -1) {
        return color == 0 ? make_pair(1, 0) : make_pair(0, 1);
    }

    const int n = matrix.size();
    const size_t mid = n / 2;

    const matrix_t top_left = copyMatrix(matrix, {0, mid}, {0, mid});
    const matrix_t top_right = copyMatrix(matrix, {0, mid}, {mid, n});
    const matrix_t bottom_left = copyMatrix(matrix, {mid, n}, {0, mid});
    const matrix_t bottom_right = copyMatrix(matrix, {mid, n}, {mid, n});

    return split_matrix(top_left) + split_matrix(top_right) + split_matrix(bottom_left) + split_matrix(bottom_right);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    size_t N;
    cin >> N;

    matrix_t matrix(N, row_t(N));
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    const auto [white, blue] = split_matrix(matrix);
    cout << white << '\n' << blue << '\n';

    return 0;
}
