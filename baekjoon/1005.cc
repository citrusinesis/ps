#include <bits/stdc++.h>

class ACMCraftSolver {
  std::vector<int> build_time_;
  std::vector<std::vector<int>> graph_;
  std::vector<int> indegree_;
  int n_ = 0;

public:
  ACMCraftSolver(const int n, const std::vector<int> &build_time)
      : build_time_(build_time), n_(n) {
    graph_.resize(n);
    indegree_.assign(n, 0);
  }

  void AddDependency(const int prerequisite, const int building) {
    graph_[prerequisite].push_back(building);
    indegree_[building]++;
  }

  int Solve(const int target) {
    std::vector<int> completion_time(n_);
    std::queue<int> q;

    for (int i = 0; i < n_; i++) {
      if (indegree_[i] == 0) {
        q.push(i);
        completion_time[i] = build_time_[i];
      }
    }

    while (!q.empty()) {
      const int current = q.front();
      q.pop();

      for (int next : graph_[current]) {
        completion_time[next] =
            std::max(completion_time[next],
                     completion_time[current] + build_time_[next]);

        indegree_[next]--;
        if (indegree_[next] == 0) {
          q.push(next);
        }
      }
    }

    return completion_time[target];
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> build_time(N);
    for (int i = 0; i < N; i++) {
      std::cin >> build_time[i];
    }

    ACMCraftSolver solver(N, build_time);

    for (int i = 0; i < K; i++) {
      int X, Y;
      std::cin >> X >> Y;

      solver.AddDependency(X - 1, Y - 1);
    }

    int W;
    std::cin >> W;

    std::cout << solver.Solve(W - 1) << '\n';
  }

  return 0;
}