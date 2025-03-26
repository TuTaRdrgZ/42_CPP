#include "RPN.hpp"

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
    std::cerr << "Error: Invalid input: Expression contains invalid characters."
              << std::endl;
    return 1;
  }

  try {
    RPN::run(expression);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
