#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char *filename) {
  std::ifstream dbFile(filename);
  if (!dbFile.is_open()) {
    throw std::runtime_error("Could not open file");
  }
  std::string line;
  if (std::getline(dbFile, line)) { /* header skipped */
  }
  while (std::getline(dbFile, line)) {
    if (line.empty())
      continue;
    std::istringstream iss(line);
    std::string date, rateStr;
    if (std::getline(iss, date, ',') && std::getline(iss, rateStr)) {
      date = trim(date);
      rateStr = trim(rateStr);
      double rate = std::atof(rateStr.c_str());
      db_[date] = rate;
    }
  }
  dbFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  db_ = other.db_;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    db_ = other.db_;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) const {
  if (date.length() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;

  std::string year = date.substr(0, 4);
  std::string month = date.substr(5, 2);
  std::string day = date.substr(8, 2);

  for (size_t i = 0; i < year.size(); ++i) {
    if (!std::isdigit(year[i]))
      return false;
  }
  for (size_t i = 0; i < month.size(); ++i) {
    if (!std::isdigit(month[i]))
      return false;
  }
  for (size_t i = 0; i < day.size(); ++i) {
    if (!std::isdigit(day[i]))
      return false;
  }

  int mon = std::atoi(month.c_str());
  int d = std::atoi(day.c_str());

  if (mon < 1 || mon > 12)
    return false;
  if (d < 1 || d > 31) // simplified: not checking month-specific days
    return false;

  return true;
}

bool BitcoinExchange::ProcessLine(const std::string &line) {
  size_t pos = line.find('|');
  if (pos == std::string::npos) {
    std::cout << "Error: bad input => " << line << std::endl;
    return false;
  }
  std::string date = trim(line.substr(0, pos));
  std::string valueStr = trim(line.substr(pos + 1));

  if (!isValidDate(date)) {
    std::cout << "Error: bad input => " << line << std::endl;
    return false;
  }

  double value;
  std::istringstream iss(valueStr);
  if (!(iss >> value)) {
    std::cout << "Error: bad input => " << line << std::endl;
    return false;
  }

  if (value < 0) {
    std::cout << "Error: not a positive number." << std::endl;
    return false;
  }
  if (value > 1000) {
    std::cout << "Error: too large a number." << std::endl;
    return false;
  }

  std::map<std::string, double>::iterator it = db_.lower_bound(date);
  if (it == db_.end()) {
    it = db_.end();
    --it;
  } else if (it->first != date) {
    if (it != db_.begin()) {
      --it;
    }
  }
  double rate = it->second;
  double result = value * rate;

  std::cout << date << " => " << valueStr << " = " << result << std::endl;
  return true;
}

std::string BitcoinExchange::trim(const std::string &s) {
  size_t start = s.find_first_not_of(" \t");
  if (start == std::string::npos)
    return "";
  size_t end = s.find_last_not_of(" \t");
  return s.substr(start, end - start + 1);
}
