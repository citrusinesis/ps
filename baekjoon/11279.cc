#include <cstddef>
#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    size_t N;
    cin >> N;

    priority_queue<int> heap;

    int input;
    for (size_t i = 0; i < N; i++) {
        cin >> input;

        if (!input) {
            if (heap.empty()) {
                cout << 0 << '\n';
            } else {
                cout << heap.top() << '\n';
                heap.pop();
            }
        } else {
            heap.push(input);
        }
    }

    return 0;
}
