#include "Serializer.hpp"

int main()
{
    Data d = {78, 'A'};
    Data *ptr = &d;

    uintptr_t address = Serializer::serialize(ptr);
    Data *deserialized = Serializer::deserialize(address);

    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Serialized pointer: " << address << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;

    return 0;
}
