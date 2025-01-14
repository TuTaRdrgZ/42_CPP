#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) { *this = other; }

Serializer &Serializer::operator=(const Serializer &other) {
  if (this != &other) {
    *this = other;
  }
  return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) { return ptr->intData; }

Data *Serializer::deserialize(uintptr_t raw) {
  Data *data = reinterpret_cast<Data *>(raw);
  return data;
}
