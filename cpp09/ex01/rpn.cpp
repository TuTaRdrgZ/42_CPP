#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>

bool checkValidChars(const std::string &str) {
  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (!std::isdigit(*it) && *it != '+' && *it != '-' && *it != '/' &&
        *it != '*' && *it != ' ')
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " \"expression\"" << std::endl;
    return 1;
  }

  std::string expression = argv[1];

  if (!checkValidChars(expression)) {
    std::cerr << "Invalid input: Expression contains invalid characters."
              << std::endl;
    return 1;
  }

  std::istringstream iss(expression);
  std::stack<int> stack;
  std::string token;
  int a, b;

  try {
    while (iss >> token) {
      if (std::isdigit(token[0]) ||
          (token.size() > 1 && token[0] == '-' && std::isdigit(token[1]))) {
        int num = std::atoi(token.c_str());
        if (num < 0) {
          throw std::runtime_error(
              "Invalid Input: Negative numbers not allowed.");
        } else if (num > 9) {
          throw std::runtime_error("Invalid Input: Big numbers not allowed.");
        }
        stack.push(num);
      } else if (token == "+" || token == "-" || token == "*" || token == "/") {
        if (stack.size() < 2) {
          throw std::runtime_error("Invalid Input: Too many operators.");
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
            throw std::runtime_error("Division by zero.");
          }
          stack.push(a / b);
        }
      } else {
        throw std::runtime_error("Invalid token encountered.");
      }
    }

    if (stack.size() != 1) {
      throw std::runtime_error("Invalid Input: Too many operands.");
    }

    std::cout << stack.top() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
