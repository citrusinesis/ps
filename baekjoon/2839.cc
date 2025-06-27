#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> dp(N / 5, -1);
    for (int i = 0; i <= (N / 5); i++) {
        const int r = N - (i * 5);
        if (r % 3 == 0) {
            if (i == 0) {
                dp[i] = i + r / 3;
            }
            dp[i] = dp[i - 1] != -1 ? std::min(i + r / 3, dp[i - 1]) : i + r / 3;
        }
        dp[i] = i == 0 ? -1 : dp[i - 1];
    }

    std::cout << dp.back() << '\n';

    return 0;
}
