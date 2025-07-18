#include <bits/stdc++.h>

constexpr int INF = std::numeric_limits<int>::max();

std::pair<int, int> dfs(
    const std::vector<std::vector<std::pair<int, int>>>& tree,
    std::vector<bool>& visited, const int current, const int current_dist) {
  visited[current] = true;

  int max_dist = current_dist;
  int farthest_node = current;

  for (const auto& [neighbor, weight] : tree[current]) {
    if (!visited[neighbor]) {
      const int new_dist = current_dist + weight;
      if (auto [far_node, far_dist] = dfs(tree, visited, neighbor, new_dist);
          far_dist > max_dist) {
        max_dist = far_dist;
        farthest_node = far_node;
      }
    }
  }

  visited[current] = false;
  return {farthest_node, max_dist};
}

std::pair<int, int> findFarthestNode(
    const std::vector<std::vector<std::pair<int, int>>>& tree,
    const int start) {
  std::vector visited(tree.size(), false);
  return dfs(tree, visited, start, 0);
}

int solve(const std::vector<std::vector<std::pair<int, int>>>& tree) {
  int node, result;
  std::tie(node, std::ignore) = findFarthestNode(tree, 1);
  std::tie(std::ignore, result) = findFarthestNode(tree, node);
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int V;
  std::cin >> V;

  std::vector tree(V + 1, std::vector<std::pair<int, int>>());
  for (int i = 0; i < V; i++) {
    int u;
    std::cin >> u;

    int input, v = 0;
    bool flag = false;
    while (std::cin >> input) {
      if (input == -1) break;
      if (!flag) {
        v = input;
        flag = true;
      } else {
        tree[u].emplace_back(v, input);
        flag = false;
      }
    }
  }

  std::cout << solve(tree) << std::endl;

  return 0;
}