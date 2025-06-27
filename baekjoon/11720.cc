#include <iostream>

using namespace std;
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int result = 0;
  char input;
  while (N--) {
    cin >> input;
    result += atoi(&input);
  }

  cout << result << '\n';
  return 0;
}
