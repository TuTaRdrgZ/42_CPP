#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Could not open file" << std::endl;
    return 1;
  }
  try {
    BitcoinExchange exchange("data.csv");

    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
      if (line.empty()) {
        continue;
      }
      if (firstLine) {
        firstLine = false;
        if (line.find("date") != std::string::npos &&
            line.find("value") != std::string::npos)
          continue;
      }
      if (!exchange.ProcessLine(line)) {
        continue;
      }
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  file.close();
  return 0;
}
