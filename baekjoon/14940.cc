#include <iostream>
#include <list>
#include <queue>
#include <utility>

std::pair<int, int> operator+(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::vector map(n, std::vector<int>(m));
    std::vector distances(n, std::vector(m, -1));

    std::queue<std::pair<int, int>> q;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cin >> map[i][j];

            if (map[i][j] == 0) {
                distances[i][j] = 0;
            }

            if (map[i][j] == 2) {
                q.push({i, j});
                distances[i][j] = 0;
            }
        }
    }

    const std::list<std::pair<int, int>> masks = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
        auto pos = q.front();

        for (auto mask: masks) {
            auto [y, x] = mask + pos;

            if (y < 0 || y >= n || x < 0 || x >= m) {
                continue;
            }

            if (map[y][x] == 0) {
                distances[y][x] = 0;
                continue;
            }

            if (distances[y][x] != -1) {
                continue;
            }

            q.push({y, x});
            distances[y][x] = distances[pos.first][pos.second] + 1;
        }

        q.pop();
    }

    for (const auto &row: distances) {
        for (const auto val: row) {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
