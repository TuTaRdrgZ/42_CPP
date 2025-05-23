#include "ScalarConverter.hpp"
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printChar(char c) {
  std::cout << "char: ";
  if (isprint(c)) {
    std::cout << "'" << c << "'" << std::endl;
  } else {
    std::cout << "Non displayable" << std::endl;
  }
}

void ScalarConverter::printInt(int value) {
  std::cout << "int: " << value << std::endl;
}

void ScalarConverter::printFloat(float value) {
  std::cout << std::fixed << std::setprecision(1) << "float: " << value << "f"
            << std::endl;
}

void ScalarConverter::printDouble(double value) {
  std::cout << std::fixed << std::setprecision(1) << "double: " << value
            << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
  try {
    if (literal == "nan") {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      printFloat(NAN);
      printDouble(NAN);
      return;
    }
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
        literal == "-inf" || literal == "+inf" || literal == "nan") {
      printChar(0); // Not valid for char conversion
      printInt(0);  // Not valid for int conversion
      printFloat(static_cast<float>(atof(literal.c_str())));
      printDouble(static_cast<double>(atof(literal.c_str())));
      return;
    }

    if (literal.length() == 1 && !isdigit(literal[0])) {
      char c = literal[0];
      printChar(c);
      printInt(static_cast<int>(c));
      printFloat(static_cast<float>(c));
      printDouble(static_cast<double>(c));
      return;
    }

    double num = atof(literal.c_str());

    if (std::isnan(num) || std::isinf(num)) {
      std::cout << "char: impossible" << std::endl;
    } else {
      printChar(static_cast<char>(num));
    }
    if (num == floor(num) && num >= INT_MIN && num <= INT_MAX) {
      printInt(static_cast<int>(num));
    } else {
      std::cout << "int: impossible" << std::endl;
    }
    printFloat(static_cast<float>(num));
    printDouble(num);

  } catch (const std::exception &e) {
    std::cout << "Conversion error: " << e.what() << std::endl;
  }
}
