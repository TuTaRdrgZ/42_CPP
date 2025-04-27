#ifndef RPN_HPP
#define RPN_HPP
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>

class RPN {
public:
  static void run(std::string expression);

private:
  ~RPN();
  RPN();
  RPN(const RPN &);
  RPN &operator=(const RPN &);
};

#endif // RPN_HPP
