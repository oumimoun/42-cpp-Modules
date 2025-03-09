#include "Serializer.hpp"

int main()
{
    Data data = {"Oussama", 25};
    std::cout << "Original Data address: " << &data << " | Name: " << data.name << " | Age: " << data.age << "\n";

    uintptr_t raw = Serializer::serialize(&data);
    Data *ptr = Serializer::deserialize(raw);

    std::cout << "Deserialized Data address: " << ptr << " | Name: " << ptr->name << " | Age: " << ptr->age << "\n";

    if (ptr == &data)
        std::cout << "Serialization and deserialization worked correctly!\n";
    else
        std::cout << "Something went wrong!\n";

    return 0;
}
