#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    int input;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> input;
        A.push_back(input);
    }

    int result = 0;
    for (auto iter = A.rbegin(); iter != A.rend(); iter++) {
        result += K / (*iter);
        K %= *iter;
    }

    cout << result << '\n';

    return 0;
}
