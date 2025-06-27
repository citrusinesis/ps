#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::string input;
  std::vector<int> inputs;

  std::cin.ignore();
  std::getline(std::cin, input);

  std::istringstream iss(input);
  int number;
  while (iss >> number) {
    inputs.push_back(number);
  }

  int T, P;
  std::cin >> T >> P;

  int Tn = 0;
  for (int n : inputs) {
    Tn += n % T == 0 ? n / T : n / T + 1;
  }
  std::cout << Tn << '\n';

  std::cout << N / P << " " << N % P;

  return 0;
}