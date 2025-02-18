#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data;

  data.intData = 42;
  data.ptrData = &data;

  std::cout << "Data before serialization:                    " << data.intData
            << ", " << data.ptrData << std::endl;

  uintptr_t raw = Serializer::serialize(&data);
  Data *deserializedPtr = Serializer::deserialize(raw);

  if (deserializedPtr == &data) {
    std::cout << "Serialization and deserialization successful! The pointers "
                 "are equal."
              << std::endl;
  } else {
    std::cout << "Something went wrong. The pointers are not equal."
              << std::endl;
  }

  std::cout << "Data after serialization and deserialization: " << data.intData
            << ", " << data.ptrData << std::endl;

  return 0;
}
