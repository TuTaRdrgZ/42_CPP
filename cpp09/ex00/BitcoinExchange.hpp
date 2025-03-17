#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, double> db_;
  BitcoinExchange();

public:
  BitcoinExchange(const char *filename);
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();
  bool isValidDate(const std::string &date) const;
  bool ProcessLine(const std::string &line);
  std::string trim(const std::string &s);
};

#endif // BITCOINEXCHANGE_HPP
