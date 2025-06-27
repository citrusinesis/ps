#include <cmath>
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

  int N;
  cin >> N;

  priority_queue<int, vector<int>, function<bool(int, int)>> heap(
      [](const int l, const int r) {
        if (abs(l) == abs(r)) {
          return l > r;
        }
        return abs(l) > abs(r);
      });

  int input;
  while (N--) {
    cin >> input;

    if (input == 0) {
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
