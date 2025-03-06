#include "../includes/Serializer.hpp"

Serializer::Serializer() {
}

Serializer::~Serializer() {

}

Serializer &Serializer::operator=(const Serializer &src) {
    if (this == &src)
        return *this;
    return *this;
}

__intptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<__intptr_t>(ptr);
}

Data *Serializer::deserialize(__intptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}