#include <ios>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> coord_t;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int M, N, H;
  cin >> M >> N >> H;

  vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
  queue<coord_t> q;

  int unripe_tomatoes = 0;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < M; ++k) {
        cin >> box[i][j][k];
        if (box[i][j][k] == 1) {
          q.push({i, j, k});
        } else if (box[i][j][k] == 0) {
          unripe_tomatoes++;
        }
      }
    }
  }

  if (unripe_tomatoes == 0) {
    cout << 0 << "\n";
    return 0;
  }

  int dh[] = {-1, 1, 0, 0, 0, 0};
  int dn[] = {0, 0, 0, 0, -1, 1};
  int dm[] = {0, 0, -1, 1, 0, 0};

  while (!q.empty()) {
    auto [h, n, m] = q.front();
    q.pop();

    for (int i = 0; i < 6; ++i) {
      int next_h = h + dh[i];
      int next_n = n + dn[i];
      int next_m = m + dm[i];

      if (next_h >= 0 && next_h < H && next_n >= 0 && next_n < N &&
          next_m >= 0 && next_m < M) {
        if (box[next_h][next_n][next_m] == 0) {
          box[next_h][next_n][next_m] = box[h][n][m] + 1;
          q.push({next_h, next_n, next_m});
        }
      }
    }
  }

  int max_days = 0;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < M; ++k) {
        if (box[i][j][k] == 0) {
          cout << -1 << "\n";
          return 0;
        }
        if (max_days < box[i][j][k]) {
          max_days = box[i][j][k];
        }
      }
    }
  }

  cout << max_days - 1 << "\n";

  return 0;
}
