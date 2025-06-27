#include <algorithm>
#include <ios>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int input;
  vector<int> times;
  for (int i = 0; i < N; i++) {
    cin >> input;
    times.push_back(input);
  }

  sort(times.begin(), times.end());

  vector<int> sum(times.size());
  partial_sum(times.begin(), times.end(), sum.begin());

  cout << accumulate(sum.begin(), sum.end(), 0) << '\n';

  return 0;
}
