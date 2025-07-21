#include <bits/stdc++.h>

constexpr int kMod = 1000000007;

typedef std::vector<std::vector<long long>> Matrix;

Matrix MultiplyMatrix(const Matrix &a, const Matrix &b) {
  Matrix result(2, std::vector<long long>(2, 0));

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % kMod;
      }
    }
  }

  return result;
}

Matrix MatrixPower(Matrix base, long long exponent) {
  Matrix result(2, std::vector<long long>(2, 0));

  result[0][0] = result[1][1] = 1;
  while (exponent > 0) {
    if (exponent & 1) {
      result = MultiplyMatrix(result, base);
    }
    base = MultiplyMatrix(base, base);
    exponent >>= 1;
  }

  return result;
}

long long CalculateFibonacci(long long n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  return MatrixPower({{1, 1}, {1, 0}}, n - 1)[0][0];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n;
  std::cin >> n;
  std::cout << CalculateFibonacci(n) << '\n';

  return 0;
}