#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <optional>
#include <vector>

template<typename T>
class MinMaxHeap {
    std::vector<T> heap;

    static int parent(const size_t i) { return (i - 1) / 2; }
    static int left_child(const size_t i) { return 2 * i + 1; }
    static int right_child(const size_t i) { return 2 * i + 2; }

    static bool is_min_level(const size_t i) {
        if (i == 0)
            return true;
        return static_cast<int>(std::floor(std::log2(i + 1))) % 2 == 0;
    }

    void push_down_min(size_t i) {
        while (left_child(i) < heap.size()) {
            size_t m = find_smallest_child_or_grandchild(i);

            if (m >= left_child(left_child(i))) {
                if (heap[m] < heap[i]) {
                    std::swap(heap[i], heap[m]);
                    if (heap[m] > heap[parent(m)]) {
                        std::swap(heap[m], heap[parent(m)]);
                    }
                    i = m;
                } else {
                    break;
                }
            } else {
                if (heap[m] < heap[i]) {
                    std::swap(heap[i], heap[m]);
                }
                break;
            }
        }
    }

    void push_down_max(size_t i) {
        while (left_child(i) < heap.size()) {
            size_t m = find_largest_child_or_grandchild(i);

            if (m >= left_child(left_child(i))) {
                if (heap[m] > heap[i]) {
                    std::swap(heap[i], heap[m]);
                    if (heap[m] < heap[parent(m)]) {
                        std::swap(heap[m], heap[parent(m)]);
                    }
                    i = m;
                } else {
                    break;
                }
            } else {
                if (heap[m] > heap[i]) {
                    std::swap(heap[i], heap[m]);
                }
                break;
            }
        }
    }

    void push_down(const size_t i) {
        if (is_min_level(i)) {
            push_down_min(i);
        } else {
            push_down_max(i);
        }
    }

    void push_up(size_t i) {
        if (i == 0)
            return;

        if (is_min_level(i)) {
            if (heap[i] > heap[parent(i)]) {
                std::swap(heap[i], heap[parent(i)]);
                push_up_max(parent(i));
            } else {
                push_up_min(i);
            }
        } else {
            if (heap[i] < heap[parent(i)]) {
                std::swap(heap[i], heap[parent(i)]);
                push_up_min(parent(i));
            } else {
                push_up_max(i);
            }
        }
    }

    void push_up_min(size_t i) {
        while (i > 2 && heap[i] < heap[parent(parent(i))]) {
            std::swap(heap[i], heap[parent(parent(i))]);
            i = parent(parent(i));
        }
    }

    void push_up_max(size_t i) {
        while (i > 2 && heap[i] > heap[parent(parent(i))]) {
            std::swap(heap[i], heap[parent(parent(i))]);
            i = parent(parent(i));
        }
    }

    size_t find_smallest_child_or_grandchild(size_t i) {
        size_t lc = left_child(i);
        size_t rc = right_child(i);
        size_t min_idx = lc;

        if (rc < heap.size() && heap[rc] < heap[lc]) {
            min_idx = rc;
        }

        const size_t grandchild_start = left_child(lc);
        for (size_t j = 0; j < 4 && grandchild_start + j < heap.size(); ++j) {
            if (heap[grandchild_start + j] < heap[min_idx]) {
                min_idx = grandchild_start + j;
            }
        }
        return min_idx;
    }

    size_t find_largest_child_or_grandchild(size_t i) {
        size_t lc = left_child(i);
        size_t rc = right_child(i);
        size_t max_idx = lc;

        if (rc < heap.size() && heap[rc] > heap[lc]) {
            max_idx = rc;
        }

        const size_t grandchild_start = left_child(lc);
        for (size_t j = 0; j < 4 && grandchild_start + j < heap.size(); ++j) {
            if (heap[grandchild_start + j] > heap[max_idx]) {
                max_idx = grandchild_start + j;
            }
        }
        return max_idx;
    }

    void build() {
        if (heap.empty())
            return;
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            push_down(i);
        }
    }

public:
    MinMaxHeap<T>() = default;

    explicit MinMaxHeap<T>(size_t size) { heap.reserve(size); }
    MinMaxHeap<T>(size_t size, T val) : heap(size, val) { build(); }

    template<typename It>
    MinMaxHeap<T>(It begin, It end) {
        heap.assign(begin, end);
        build();
    }

    [[nodiscard]] bool is_empty() const { return heap.empty(); }
    [[nodiscard]] size_t size() const { return heap.size(); }

    void push(const T &val) {
        heap.push_back(val);
        push_up(heap.size() - 1);
    }

    [[nodiscard]] std::optional<T> get_min() const {
        if (is_empty())
            return std::nullopt;
        return heap[0];
    }

    [[nodiscard]] std::optional<T> get_max() const {
        if (is_empty())
            return std::nullopt;
        if (heap.size() == 1)
            return heap[0];
        if (heap.size() == 2)
            return heap[1];
        return heap[1] > heap[2] ? heap[1] : heap[2];
    }

    std::optional<T> pop_min() {
        if (is_empty())
            return std::nullopt;
        T min_val = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!is_empty()) {
            push_down(0);
        }
        return min_val;
    }

    std::optional<T> pop_max() {
        if (is_empty())
            return std::nullopt;
        size_t max_idx = 0;
        if (heap.size() <= 2) {
            max_idx = heap.size() - 1;
        } else {
            max_idx = (heap[1] > heap[2]) ? 1 : 2;
        }

        T max_val = heap[max_idx];
        heap[max_idx] = heap.back();
        heap.pop_back();

        if (max_idx < heap.size()) {
            push_down(max_idx);
        }

        return max_val;
    }
};


int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    while (T--) {
        MinMaxHeap<int> mmh;

        int k;
        std::cin >> k;
        while (k--) {
            char query;
            int input;

            std::cin >> query >> input;
            switch (query) {
                case 'I':
                    mmh.push(input);
                    break;
                case 'D':
                    if (mmh.is_empty())
                        continue;
                    if (input == 1) {
                        mmh.pop_max();
                    } else {
                        mmh.pop_min();
                    }
                    break;
                default:
                    break;
            }
        }

        if (mmh.is_empty()) {
            std::cout << "EMPTY\n";
        } else {
            std::cout << *mmh.get_max() << " " << *mmh.get_min() << '\n';
        }
    }

    return 0;
}
