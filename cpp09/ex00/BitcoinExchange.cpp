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
      date = Trim(date);
      rateStr = Trim(rateStr);
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

  std::string yearStr = date.substr(0, 4);
  std::string monthStr = date.substr(5, 2);
  std::string dayStr = date.substr(8, 2);

  for (size_t i = 0; i < yearStr.size(); ++i) {
    if (!std::isdigit(yearStr[i]))
      return false;
  }
  for (size_t i = 0; i < monthStr.size(); ++i) {
    if (!std::isdigit(monthStr[i]))
      return false;
  }
  for (size_t i = 0; i < dayStr.size(); ++i) {
    if (!std::isdigit(dayStr[i]))
      return false;
  }

  int year = std::atoi(yearStr.c_str());
  int month = std::atoi(monthStr.c_str());
  int day = std::atoi(dayStr.c_str());

  if (month < 1 || month > 12)
    return false;

  int maxDay;
  switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      maxDay = 31;
      break;
    case 4: case 6: case 9: case 11:
      maxDay = 30;
      break;
    case 2:
      if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        maxDay = 29;
      else
        maxDay = 28;
      break;
    default:
      return false;
  }

  if (day < 1 || day > maxDay)
    return false;

  return true;
}

bool BitcoinExchange::ProcessLine(const std::string &line) {
  size_t pos = line.find('|');
  if (pos == std::string::npos) {
    std::cout << "Error: bad input => " << line << std::endl;
    return false;
  }
  std::string date = Trim(line.substr(0, pos));
  std::string valueStr = Trim(line.substr(pos + 1));

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

std::string BitcoinExchange::Trim(const std::string &s) {
  size_t start = s.find_first_not_of(" \t");
  if (start == std::string::npos)
    return "";
  size_t end = s.find_last_not_of(" \t");
  return s.substr(start, end - start + 1);
}
