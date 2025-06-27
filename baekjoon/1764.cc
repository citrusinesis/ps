#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  set<string> A;
  set<string> B;

  string input;
  while (N--) {
    cin >> input;
    A.insert(input);
  }

  while (M--) {
    cin >> input;
    B.insert(input);
  }

  vector<string> intersect;
  set_intersection(A.begin(), A.end(), B.begin(), B.end(),
                   back_inserter(intersect));

  sort(intersect.begin(), intersect.end());
  cout << intersect.size() << '\n';
  for (auto name : intersect) {
    cout << name << '\n';
  }

  return 0;
}