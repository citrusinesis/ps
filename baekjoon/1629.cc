#include <bits/stdc++.h>

#define ll long long

ll calc(const ll A, const ll B, const ll C) {
  if (B == 0) {
    return 1;
  }

  if (B == 1) {
    return A % C;
  }

  if (B % 2 == 0) {
    const ll temp = calc(A, B / 2, C);
    return (temp * temp) % C;
  }

  return (A * calc(A, B - 1, C)) % C;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll A, B, C;
  std::cin >> A >> B >> C;

  std::cout << calc(A, B, C) << std::endl;

  return 0;
}
