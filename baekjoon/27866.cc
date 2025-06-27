#include <iostream>
#include <string>
int main() {
  std::string input;
  int i;
  std::cin >> input >> i;
  std::cout << input[i - 1];
}