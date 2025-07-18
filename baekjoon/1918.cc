#include <bits/stdc++.h>

constexpr int CalculatePrecedence(const char c) {
  if (c == '(' || c == ')') {
    return -1;
  }
  if (c >= 'A' && c <= 'Z') {
    return 0;
  }
  if (c == '+' || c == '-') {
    return 1;
  }
  if (c == '*' || c == '/') {
    return 2;
  }
  return -1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string infix_expr;
  std::cin >> infix_expr;

  std::stack<char> op_stack;
  for (const char &c : infix_expr) {
    const int c_precedence = CalculatePrecedence(c);
    if (c_precedence == 0) {
      std::cout << c;
      continue;
    }

    if (c == '(') {
      op_stack.push(c);
      continue;
    }

    if (c == ')') {
      while (!op_stack.empty() && op_stack.top() != '(') {
        std::cout << op_stack.top();
        op_stack.pop();
      }
      if (!op_stack.empty()) {
        op_stack.pop();
      }
      continue;
    }

    if (c_precedence > 0) {
      while (!op_stack.empty() && op_stack.top() != '(' &&
             CalculatePrecedence(op_stack.top()) >= c_precedence) {
        std::cout << op_stack.top();
        op_stack.pop();
      }
      op_stack.push(c);
    }
  }

  while (!op_stack.empty()) {
    std::cout << op_stack.top();
    op_stack.pop();
  }

  std::cout << '\n';
  return 0;
}