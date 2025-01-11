#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &);
  ScalarConverter &operator=(ScalarConverter const &);
  ~ScalarConverter();
  static void printChar(char c);
  static void printInt(int value);
  static void printFloat(float value);
  static void printDouble(double value);

public:
  static void convert(const std::string &literal);
};

#endif
