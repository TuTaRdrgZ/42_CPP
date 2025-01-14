#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data;

  data.intData = 42;
  data.ptrData = &data;

  std::cout << "Data before serialization:                    " << data.intData
            << ", " << data.ptrData << std::endl;
  Serializer::deserialize(Serializer::serialize(&data));
  std::cout << "Data after serialization and deserialization: " << data.intData
            << ", " << data.ptrData << std::endl;
}
