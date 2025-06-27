#include <ios>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool set_time(int N, int M, vector<int> &time) {
  if (M > 100000 || M < 0) {
    return false;
  }

  if (time[M] > time[N] + 1 || time[M] == 0) {
    time[M] = time[N] + 1;
    return true;
  }

  return false;
}

void push(int N, queue<int> &q, vector<int> &time) {
  if (set_time(N, N + 1, time)) {
    q.push(N + 1);
  };

  if (set_time(N, N - 1, time)) {
    q.push(N - 1);
  };

  if (set_time(N, 2 * N, time)) {
    q.push(2 * N);
  };
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  if (N == K) {
    cout << 0 << '\n';
    return 0;
  }

  if (K < N) {
    cout << N - K << '\n';
    return 0;
  }

  vector<int> time(100000, 0);
  queue<int> q;

  push(N, q, time);

  while (q.front() != K) {
    push(q.front(), q, time);
    q.pop();
  }

  cout << time[q.front()] << '\n';

  return 0;
}