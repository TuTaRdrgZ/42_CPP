#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &) {}
RPN &RPN::operator=(const RPN &other) {
  static_cast<void>(other);
  return *this;
}

void RPN::run(std::string expression) {

  std::istringstream iss(expression);
  std::stack<int> stack;
  std::string token;
  int a, b;

  while (iss >> token) {
    if (std::isdigit(token[0]) ||
        (token.size() > 1 && token[0] == '-' && std::isdigit(token[1]))) {
      int num = std::atoi(token.c_str());
      if (num < 0) {
        throw std::runtime_error(
            "Error: Invalid Input: Negative numbers not allowed.");
      }
      stack.push(num);
    } else if (token == "+" || token == "-" || token == "*" || token == "/") {
      if (stack.size() < 2) {
        throw std::runtime_error("Error: Invalid Input: Too many operators.");
      }
      b = stack.top();
      stack.pop();
      a = stack.top();
      stack.pop();

      if (token == "+") {
        stack.push(a + b);
      } else if (token == "-") {
        stack.push(a - b);
      } else if (token == "*") {
        stack.push(a * b);
      } else if (token == "/") {
        if (b == 0) {
          throw std::runtime_error("Error: Division by zero.");
        }
        stack.push(a / b);
      }
    } else {
      throw std::runtime_error("Error: Invalid token encountered.");
    }
  }

  if (stack.size() != 1) {
    throw std::runtime_error("Error: Invalid Input: Too many operands.");
  }
  std::cout << stack.top() << std::endl;
}
