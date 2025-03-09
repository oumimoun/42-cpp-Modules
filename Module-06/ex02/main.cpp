#include "Base.hpp"

int main()
{
    try {
        Base *obj = generate();
        std::cout << "Identifying with pointer: ";
        identify(obj);

        std::cout << "Identifying with reference: ";
        identify(*obj);
        delete obj;
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
