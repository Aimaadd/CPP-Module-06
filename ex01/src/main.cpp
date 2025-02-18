#include "../includes/Serializer.hpp"

int main() {
    Data test;
    test.name = "test_name";
    test.user_id = 4124;

    std::cout << "here\n";
    printf("%p\n", &test);
    uintptr_t truc = Serializer::serialize(&test);
    std::cout << truc << std::endl;
    std::cout << Serializer::deserialize(truc) << std::endl;
    
}