#include "Array.hpp"

int main(void)
{
    try
    {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        int size = 10;
        Array<int> array(size);
        std::cout << "array size: " << array.size() << std::endl;

        for (unsigned int i = 0; i < array.size(); i++)
            array[i] = i + 1;

        std::cout << "Array of Integer: ";
        for (unsigned int i = 0; i < array.size(); i++)
            std::cout << array[i] << " ";
        std::cout << "\n";

        Array<int> copyArray(array);
        std::cout << "The new Array of Integer with copy constructor: ";
        for (unsigned int i = 0; i < copyArray.size(); i++)
            std::cout << copyArray[i] << " ";
        std::cout << "\n";

        copyArray[0] = 100;
        std::cout << "Modified copyArray[0]: " << copyArray[0] << std::endl;
        std::cout << "Original     array[0]: " << array[0] << std::endl;

        Array<int> assignedArray = array;
        std::cout << "The assigned Array of Integer with copy assignement operator: ";
        for (unsigned int i = 0; i < assignedArray.size(); i++)
            std::cout << assignedArray[i] << " ";
        std::cout << std::endl;

        const Array<int> constArray = array;
        std::cout << "Const array size: " << constArray.size() << std::endl;
        std::cout << "Const array: ";
        for (unsigned int i = 0; i < constArray.size(); i++)
            std::cout << array[i] << " ";
        std::cout << "\n";

        std::cout << "Trying an out-of-bounds index..." << std::endl;
        std::cout << array[-1] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}