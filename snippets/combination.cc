#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

template <typename T>
class combination_iterator {
 public:
  using iterator_category = std::forward_iterator_tag;
  using value_type = std::vector<T>;
  using difference_type = std::ptrdiff_t;
  using pointer = value_type*;
  using reference = value_type&;

 private:
  const std::vector<T>* candidates_;
  std::vector<int> indices_;
  int r_;
  bool is_end_;
  mutable std::vector<T> current_combination_;

 public:
  combination_iterator(const std::vector<T>& candidates, const int r)
      : candidates_(&candidates), indices_(r), r_(r), is_end_(false) {
    if (r > static_cast<int>(candidates.size()) || r <= 0) {
      is_end_ = true;
      return;
    }

    std::iota(indices_.begin(), indices_.end(), 0);
    update_current_combination();
  }

  combination_iterator() : candidates_(nullptr), r_(0), is_end_(true) {}

  const std::vector<T>& operator*() const { return current_combination_; }

  const std::vector<T>* operator->() const { return &current_combination_; }

  combination_iterator& operator++() {
    if (is_end_) return *this;

    const auto n = static_cast<int>(candidates_->size());

    int i = r_ - 1;
    while (i >= 0 && indices_[i] == n - r_ + i) {
      --i;
    }

    if (i < 0) {
      is_end_ = true;
      return *this;
    }
    ++indices_[i];
    for (int j = i + 1; j < r_; ++j) {
      indices_[j] = indices_[j - 1] + 1;
    }

    update_current_combination();
    return *this;
  }

  combination_iterator operator++(int) {
    auto temp = *this;
    ++(*this);
    return temp;
  }

  bool operator==(const combination_iterator& other) const {
    if (is_end_ && other.is_end_) return true;
    if (is_end_ != other.is_end_) return false;
    return candidates_ == other.candidates_ && indices_ == other.indices_ &&
           r_ == other.r_;
  }

  bool operator!=(const combination_iterator& other) const {
    return !(*this == other);
  }

 private:
  void update_current_combination() const {
    current_combination_.clear();
    current_combination_.reserve(r_);
    for (auto idx : indices_) {
      current_combination_.push_back((*candidates_)[idx]);
    }
  }
};

template <typename T>
class combination_range {
  const std::vector<T>& candidates_;
  int r_;

 public:
  combination_range(const std::vector<T>& candidates, int r)
      : candidates_(candidates), r_(r) {}

  combination_iterator<T> begin() const {
    return combination_iterator<T>(candidates_, r_);
  }

  combination_iterator<T> end() const { return combination_iterator<T>{}; }
};

template <typename T>
combination_range<T> combinations(const std::vector<T>& candidates, int r) {
  return combination_range<T>(candidates, r);
}
