#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  map<string, int> wiki;
  map<int, string> inv_wiki;

  cin >> N >> M;
  string name;
  for (int i = 1; i <= N; i++) {
    cin >> name;
    wiki.insert(make_pair(name, i));
    inv_wiki.insert(make_pair(i, name));
  }

  string input;
  for (int i = 0; i < M; i++) {
    cin >> input;
    try {
      cout << inv_wiki.find(stoi(input))->second << '\n';
    } catch (...) {
      cout << wiki.find(input)->second << '\n';
    }
  }

  return 0;
}